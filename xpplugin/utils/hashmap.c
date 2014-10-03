#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#include "hashmap.h"

/*
 * This is really just for fun.
 * It's been a long time since I last implemented a hashmap in C.
 */

// "djb2" string hash function
// See: http://www.cse.yorku.ca/~oz/hash.html
// And: https://groups.google.com/forum/#!msg/comp.lang.c/lSKWXiuNOAk/zstZ3SRhCjgJ
unsigned long str_hash(char *str) 
{
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}

// Computes the bucket index the given key belongs to.
int get_bucket_idx(hashmap_t *map, char *key) 
{
	unsigned long hash = str_hash(key);
	
    return hash % map->buckets_n;
}

//////////////////////////////////
// API / Public Functions & Macros
//////////////////////////////////

// Initializes a new hash_map with 'bucket_n' buckets.
hashmap_t *hashmap_init_size(int bucket_n) 
{
	hashmap_t *new_map = (hashmap_t *)malloc(sizeof(hashmap_t));
	
	// Init NULL buckets
	new_map->buckets_n = bucket_n;
	new_map->buckets = malloc(bucket_n * sizeof(bucket_t *));
	memset(new_map->buckets, 0, bucket_n * sizeof(bucket_t *));
	
	return (void *)new_map;
}

// Initializes a new hash map with 50 buckets.
hashmap_t *hashmap_init() 
{
	return hashmap_init_size(50);
}

// Returns the number of elements in the map.
unsigned long hashmap_size(hashmap_t *map) 
{
    unsigned long count = 0;
    
    for(int i=0; i<map->buckets_n; i++)
    {
        bucket_t *bucket = map->buckets[i];

        while(bucket != NULL) 
        {
            count++;
            
            bucket = bucket->next;
        }
    }
    
    return count;
}


bool hashmap_contains_key(hashmap_t *map, char *key) 
{
    int bucket_idx = get_bucket_idx(map, key);
    
    bucket_t *bucket = map->buckets[bucket_idx];
    
    while(bucket != NULL)
    {
        if(strcmp(bucket->key, key) == 0)
            return true;
        
        bucket = bucket->next;
    }
    
    return false;
}

// Adds a new key/value pair to the map.
void hashmap_set(hashmap_t *map, char *key, void *value) 
{	
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
    if(prev_bucket == NULL) 
    {
        map->buckets[bucket_idx] = new_bucket;
        return;
    }
    
    // Otherwise, loop through the elements and replace or add
    
    while(true) {
        if(strcmp(key, prev_bucket->key) == 0) 
        {
            // The key already exists: replace the payload.
            // What should happen to the old payload? Should it be freed?
            prev_bucket->payload = value;
            return;
        }
        
        if(prev_bucket->next == NULL) 
        {
            prev_bucket->next = new_bucket;
            return;
        }
        
        prev_bucket = prev_bucket->next;
    }
}

// Returns the value for the given key. NULL if the key does not exist.
void *hashmap_get(hashmap_t *map, char *key) 
{	
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

/////////////////////////////
// String utility function(s)
/////////////////////////////

// From http://stackoverflow.com/questions/4770985/something-like-startswithstr-a-str-b-in-c
bool startsWith(const char *pre, const char *str)
{
    size_t lenpre = strlen(pre);
    size_t lenstr = strlen(str);
    
    return lenstr < lenpre ? false : strncmp(pre, str, lenpre) == 0;
}


///////////////////////////////
// Iterating Through A Hash Map
///////////////////////////////

// Private utility function
// Updates the iterator to go to the next value, without taking filters into account
// Same return semantics as hashmap_iterator_next
// NOTE: this thing should probably free the iterator before returning NULL...
iterator_t *it_nxt(iterator_t *it)
{ 
    if(it == NULL)
        return NULL;
    
    if(it->current != NULL && it->current->next != NULL){
        it->current = it->current->next;
        return it;
    }
    
    for(int i=it->cur_bucket_idx+1; i<it->map->buckets_n; i++)
    {
        if(it->map->buckets[i] != NULL)
        {
            it->cur_bucket_idx = i;
            it->current = it->map->buckets[i];
            
            return it;
        }
    }
    
    return NULL;
}

iterator_t *hashmap_iterator_filter(hashmap_t * map, char *keyStartsWith) 
{
    iterator_t *it = (iterator_t *)malloc(sizeof(iterator_t));
    int first_bucket_idx = 0;
    
    it->map = map;
    it->cur_bucket_idx = first_bucket_idx;
    it->current = NULL;
    it->filter = keyStartsWith;
    
    it = it_nxt(it);
    
    if(it == NULL)
        return NULL;
    
    if(!startsWith(it->filter, hashmap_iterator_key(it)))
        it = hashmap_iterator_next(it);
    
    return it;
}

iterator_t *hashmap_iterator(hashmap_t * map) 
{
    return hashmap_iterator_filter(map, NULL);
}

// Returns the updated iterator, or NULL if there is no further element.
iterator_t *hashmap_iterator_next(iterator_t *it) 
{
    if(it->filter == NULL)
        return it_nxt(it);
    
    do 
    {
        it = it_nxt(it);
    } while(it != NULL && !startsWith(it->filter, hashmap_iterator_key(it)));

    return it;
}

char *hashmap_iterator_key(iterator_t *it) 
{    
    if(it == NULL)
        return NULL;
    
    return it->current->key;
}

void *hashmap_iterator_value(iterator_t *it) 
{
    if(it == NULL)
        return NULL;
    
    return it->current->payload;
}