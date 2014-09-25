#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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


float myCallback(float inElapsedSinceLastCall, float inElapsedTimeSinceLastFlightLoop, int inCounter, void * inRefcon);

PLUGIN_API int XPluginStart(char *outName, char * outSig, char * outDesc)
{
	// Plugin Info
	strcpy(outName, "ZeroPlane");
	strcpy(outSig, "ThingyLab.ZeroPlane");
	strcpy(outDesc, "A data streaming plugin.");
    
    XPLMRegisterFlightLoopCallback(myCallback, 1, (void *)0);
    
	return 1;
}

PLUGIN_API void XPluginStop(void)
{
}

PLUGIN_API int XPluginEnable(void)
{
	return 1;
}

PLUGIN_API void XPluginDisable(void)
{
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
    XPLMDebugString("My callback was called!");
    
    return 1.0;
}