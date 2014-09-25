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
#include "init.h"
#include "utils/hashmap.h"

void *build_datarefs_map() {
    void *map = hashmap_init();
    
    for(int i=0; i<DATAREFS_NUM; i++) {
        dataref_rep_t *dr = (dataref_rep_t *)malloc(sizeof(dataref_rep_t));
        char *key = datarefs[i][0];
        
        dr->path = key;
        dr->dataref = XPLMFindDataRef(datarefs[i][1]);
        
        hashmap_set(map, key, dr);
    }
    
    return map;
}