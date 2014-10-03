#include <stdio.h>
#include <stdbool.h>

typedef struct bucket_t {
	char *key;
	void *payload;
	
	struct bucket_t *next;
} bucket_t;

typedef struct hashmap_t {
	bucket_t **buckets;
	int buckets_n;
} hashmap_t;

typedef struct iterator_t {
    hashmap_t *map;
    int cur_bucket_idx;
    bucket_t *current;
    
    char *filter;
} iterator_t;


hashmap_t *hashmap_init();
hashmap_t *hashmap_init_size(int bucket_n);

void hashmap_set(hashmap_t *hash_map, char *key, void *value);
void *hashmap_get(hashmap_t *hash_map, char *key);

bool hashmap_contains_key(hashmap_t *hash_map, char *key);
unsigned long hashmap_size(hashmap_t *hash_map);

iterator_t *hashmap_iterator(hashmap_t *hash_map);
iterator_t *hashmap_iterator_filter(hashmap_t *hash_map, char *keyStartsWith);
iterator_t *hashmap_iterator_next(iterator_t *iterator);
char *hashmap_iterator_key(iterator_t *iterator);
void *hashmap_iterator_value(iterator_t *iterator);