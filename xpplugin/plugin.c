#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <zmq.h>

#include "XPLMPlugin.h"
#include "XPLMDisplay.h"
#include "XPLMGraphics.h"
#include "XPLMProcessing.h"
#include "XPLMDataAccess.h"
#include "XPLMMenus.h"
#include "XPLMUtilities.h"
#include "XPWidgets.h"
#include "XPStandardWidgets.h"
#include "XPLMScenery.h"

#include "init.h"
#include "datarefs.h"
#include "utils/hashmap.h"
#include "protobuf/ZeroPlane.pb-c.h"

// The following global stuff will have to move someplace else
void *datarefs_map = NULL;

void *context = NULL;
void *socket = NULL;

float myCallback(float inElapsedSinceLastCall, float inElapsedTimeSinceLastFlightLoop, int inCounter, void * inRefcon);


PLUGIN_API int XPluginStart(char *outName, char * outSig, char * outDesc)
{
	// Pass plugin info to XPlane
	strcpy(outName, "ZeroPlane");
	strcpy(outSig, "ThingyLab.ZeroPlane");
	strcpy(outDesc, "A data streaming plugin.");
    
    // ZMQ context. Just one per process.
    context = zmq_ctx_new();
    
    // Setup the datarefs map
    datarefs_map = build_datarefs_map();
    XPLMDebugString("[ZeroPlane] Datarefs map built.");
    
    // Register the main callback
    XPLMRegisterFlightLoopCallback(myCallback, 1, (void *)0);
    
	return 1;
}

PLUGIN_API void XPluginStop(void)
{
}

PLUGIN_API int XPluginEnable(void)
{
    // Open the ZMQ context & socket
    socket = zmq_socket(context, ZMQ_PUB);
    int rc = zmq_bind(socket, "tcp://*:5556");
    
    if(rc == 0) {
        XPLMDebugString("[ZeroPlane] ZMQ Enable ok.\n");
    	return 1;
    }
    
    // Not sure what else to do here
    XPLMDebugString("[ZeroPlane] Init failed.\n");
    return 0;
}

PLUGIN_API void XPluginDisable(void)
{
    XPLMDebugString("Disabling plugin...\n");
    // zmq_unbind(socket, "tcp://*:5555");
    zmq_close(socket);
    zmq_ctx_destroy(context);
}

PLUGIN_API void XPluginReceiveMessage(XPLMPluginID inFromWho, long inMessage, void * inParam)
{
}

float myCallback(float inElapsedSinceLastCall, float inElapsedTimeSinceLastFlightLoop, int inCounter, void * inRefcon) 
{
    // float curPitch = 0.0;
    //
    // curPitch = XPLMGetDataf(pitch);
    //
    // char str[80];
    // sprintf(str, "Pitch = %f", curPitch); // Unsafe much?
    
    Zeroplane__Message msg = ZEROPLANE__MESSAGE__INIT;
    Zeroplane__Airplane airplane = ZEROPLANE__AIRPLANE__INIT;
	void *buf;
	size_t len;
    
    XPLMDataRef callSignDataRef = XPLMFindDataRef("sim/aircraft/view/acf_tailnum");
    if(callSignDataRef == NULL)
        XPLMDebugString("[ZeroPlane] Nope!\n");
    
    XPLMDebugString(((dataref_rep_t *)hashmap_get(datarefs_map, TAILNUM))->path);
    char callsign[40];
    int copied = XPLMGetDatab(callSignDataRef, callsign, 0, 39);
    
    
    msg.airplane = &airplane;
    
    airplane.plane_num = 1;
    airplane.tailnum = callsign;
    
    len = zeroplane__message__get_packed_size(&msg);
    buf = malloc(len);
    
    char str[800];
    sprintf(str, "[ZeroPlane] Packed size = %lu\n[ZeroPlane] nb copied: %i", len, copied);
    XPLMDebugString(str);
    
    zeroplane__message__pack(&msg, buf);
    
	zmq_msg_t zmqmsg;
	int a = zmq_msg_init_size(&zmqmsg, len); //len*4
	void *data = zmq_msg_data(&zmqmsg);
 	memcpy(data, buf, len);
    
    zmq_msg_send(&zmqmsg, socket, 0);
        
    XPLMDebugString("[ZeroPlane] Sending a message...\n");
    // zmq_send(socket, "AHello", 7, 0);
    
    return 5.0;
}