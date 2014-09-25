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
    
    // Setup the datarefs map
    // datarefs_map = build_datarefs_map();
    
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
    context = zmq_ctx_new();
    socket = zmq_socket(context, ZMQ_PUB);
    int rc = zmq_bind(socket, "tcp://*:5556");
    
    if(rc == 0) {
        XPLMDebugString("ZMQ Enable ok.\n");
    	return 1;
    }
    
    // Not sure what else to do here
    XPLMDebugString("Init failed.\n");
    return 0;
}

PLUGIN_API void XPluginDisable(void)
{
    XPLMDebugString("Disabling plugin...\n");
    zmq_unbind(socket, "tcp://*:5555");
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
    XPLMDebugString("Sending a message...\n");
    zmq_send(socket, "AHello", 7, 0);
    
    return 1.0;
}