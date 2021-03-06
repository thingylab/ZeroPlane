#ifndef INIT_H_5E9ABF9B
#define INIT_H_5E9ABF9B

#include "utils/hashmap.h"

// Contains the path to a Dataref and its matching opaque structure
// These are created and stored in a map when the plugin is loaded.
typedef struct {
    char *path;
    XPLMDataRef dataref;
} dataref_rep_t;

extern hashmap_t *datarefs_map;

hashmap_t *build_datarefs_map();

#endif /* end of include guard: INIT_H_5E9ABF9B */