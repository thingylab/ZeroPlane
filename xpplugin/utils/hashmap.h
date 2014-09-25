#include <stdio.h>
#include <stdbool.h>

void *hashmap_init();
void *hashmap_init_size(int bucket_n);

void hashmap_set(void *hash_map, char *key, void *value);
void *hashmap_get(void *hash_map, char *key);

bool hashmap_contains_key(void *hash_map, char *key);
unsigned long hashmap_size(void *hash_map);

void *hashmap_iterator(void * hash_map);
bool hashmap_iterator_has_next(void *iterator);
bool hashmap_iterator_next(void *iterator);
char *hashmap_iterator_key(void *iterator);
void *hashmap_iterator_value(void *iterator);