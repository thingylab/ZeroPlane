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

#include "datarefs.h"
#include "utils/hashmap.h"
#include "init.h"

hashmap_t *datarefs_map = NULL;

hashmap_t *build_datarefs_map() {
    hashmap_t *map = hashmap_init();
    
    for(int i=0; i<DATAREFS_NUM; i++) {
        dataref_rep_t *dr = (dataref_rep_t *)malloc(sizeof(dataref_rep_t));
        char *path = datarefs[i][1];
        
        dr->path = path;
        dr->dataref = XPLMFindDataRef(datarefs[i][1]);
        
        if(dr->dataref == NULL) {
            XPLMDebugString("[ZeroPlane] Cannot find dataref: ");
            XPLMDebugString(datarefs[i][1]);
            XPLMDebugString("\n");
        }
        
        hashmap_set(map, datarefs[i][0], dr);
    }
    
    return map;
}