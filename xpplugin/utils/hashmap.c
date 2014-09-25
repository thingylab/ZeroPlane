#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#include "hashmap.h"

/*
 * This is really just for fun.
 * It's been a long time since I last implemented a hashmap in C.
 */

typedef struct bucket_t {
	char *key;
	void *payload;
	
	struct bucket_t *next;
} bucket_t;

typedef struct hash_map_t {
	bucket_t **buckets;
	int buckets_n;
} hash_map_t;

typedef struct iterator_t {
    hash_map_t *map;
    int cur_bucket_idx;
    bucket_t *current;
    
    bool is_at_end;
} iterator_t;

///////////////////////////////
// Utility (private) functions.
///////////////////////////////

#define MAP_POINTER(map) ((hash_map_t *)map)

// "djb2" string hash function
// See: http://www.cse.yorku.ca/~oz/hash.html
// And: https://groups.google.com/forum/#!msg/comp.lang.c/lSKWXiuNOAk/zstZ3SRhCjgJ
unsigned long str_hash(char *str) {
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}

// Computes the bucket index the given key belongs to.
int get_bucket_idx(hash_map_t *map, char *key) {
	unsigned long hash = str_hash(key);
	
    return hash % map->buckets_n;
}

//////////////////////////////////
// API / Public Functions & Macros
//////////////////////////////////

// Initializes a new hash_map with 'bucket_n' buckets.
void *hashmap_init_size(int bucket_n) {
	hash_map_t *new_map = (hash_map_t *)malloc(sizeof(hash_map_t));
	
	// Init NULL buckets
	new_map->buckets_n = bucket_n;
	new_map->buckets = malloc(bucket_n * sizeof(bucket_t *));
	memset(new_map->buckets, 0, bucket_n * sizeof(bucket_t *));
	
	return (void *)new_map;
}

// Initializes a new hash map with 50 buckets.
void *hashmap_init() {
	return hashmap_init_size(50);
}

// Returns the number of elements in the map.
unsigned long hashmap_size(void *hash_map) {
    hash_map_t *map = MAP_POINTER(hash_map);
    unsigned long count = 0;
    
    for(int i=0; i<map->buckets_n; i++){
        bucket_t *bucket = map->buckets[i];

        while(bucket != NULL) {
            count++;
            
            bucket = bucket->next;
        }
    }
    
    return count;
}


bool hashmap_contains_key(void *hash_map, char *key) {
    hash_map_t *map = MAP_POINTER(hash_map);
    int bucket_idx = get_bucket_idx(map, key);
    
    bucket_t *bucket = map->buckets[bucket_idx];
    
    while(bucket != NULL) {
        if(strcmp(bucket->key, key) == 0)
            return true;
        
        bucket = bucket->next;
    }
    
    return false;
}

// Adds a new key/value pair to the map.
void hashmap_set(void *hash_map, char *key, void *value) {
	hash_map_t *map = MAP_POINTER(hash_map);
	
	// Hash key a compute destination bucket index
	unsigned long hash = str_hash(key);
	int bucket_idx = get_bucket_idx(map, key);
    
    printf("%s - %i\n", key, bucket_idx);
	
	// Allocate a new bucket
	bucket_t *new_bucket = (bucket_t *)malloc(sizeof(bucket_t));
	new_bucket->key = key;
	new_bucket->payload = value;
	new_bucket->next = NULL;
	
	bucket_t *prev_bucket = map->buckets[bucket_idx];
    
    // Nothing in the bucket: set the head element and return.
    if(prev_bucket == NULL) {
        map->buckets[bucket_idx] = new_bucket;
        return;
    }
    
    // Otherwise, loop through the elements and replace or add
    
    while(true) {
        if(strcmp(key, prev_bucket->key) == 0) {
            // The key already exists: replace the payload.
            // What should happen to the old payload? Should it be freed?
            prev_bucket->payload = value;
            return;
        }
        
        if(prev_bucket->next == NULL) {
            prev_bucket->next = new_bucket;
            return;
        }
        
        prev_bucket = prev_bucket->next;
    }
}

// Returns the value for the given key. NULL if the key does not exist.
void *hashmap_get(void *hash_map, char *key) {
	hash_map_t *map = MAP_POINTER(hash_map);
	
	// Hash key a compute destination bucket index
	unsigned long hash = str_hash(key);
	int bucket_idx = get_bucket_idx(map, key);
	
	if(map->buckets[bucket_idx] == NULL)
		return NULL;
	
	bucket_t *b = map->buckets[bucket_idx];
	
	while(strcmp(b->key, key) != 0)
		b = b->next;
	
	return b->payload;
}


///////////////////////////////
// Iterating Through A Hash Map
///////////////////////////////

void *hashmap_iterator(void * hash_map) {
    hash_map_t *map = MAP_POINTER(hash_map);
    bucket_t *first_bucket = NULL;
    iterator_t *it = (iterator_t *)malloc(sizeof(iterator_t));
    int first_bucket_idx = 0;
    
    // Find first non-NULL bucket, if any
    for(first_bucket_idx=0; first_bucket_idx<map->buckets_n; first_bucket_idx++) {
        if(map->buckets[first_bucket_idx] != NULL) {
            first_bucket = map->buckets[first_bucket_idx];
            break;
        }
    }
    
    it->map = map;
    it->cur_bucket_idx = first_bucket_idx;
    it->current = first_bucket;
    it->is_at_end = first_bucket == NULL ? true : false;
    
    return (void*)it;
}

bool hashmap_iterator_has_next(void *iterator) {
    iterator_t *it = (iterator_t *)iterator;
    
    if(it->current->next != NULL)
        return true;
    
    for(int i=it->cur_bucket_idx+1; i<it->map->buckets_n; i++) {
        if(it->map->buckets[i] != NULL)
            return true;
    }
    
    return false;
}

bool hashmap_iterator_next(void *iterator) {
    iterator_t *it = (iterator_t *)iterator;
    
    if(!hashmap_iterator_has_next(iterator)) {
        it->is_at_end = true;
        return false;
    }
    
    if(it->current->next != NULL) {
        it->current = it->current->next;
        return true;
    }
    
    for(int i=it->cur_bucket_idx+1; i<it->map->buckets_n; i++) {
        if(it->map->buckets[i] != NULL) {
            it->current = it->map->buckets[i];
            it->cur_bucket_idx = i;
            return true;
        }
    }
    
    return false;
}

char *hashmap_iterator_key(void *iterator) {
    iterator_t *it = (iterator_t *)iterator;
    
    if(it->is_at_end)
        return NULL;
    
    return it->current->key;
}

void *hashmap_iterator_value(void *iterator) {
    iterator_t *it = (iterator_t *)iterator;
    
    if(it->is_at_end)
        return NULL;
    
    return it->current->payload;
}