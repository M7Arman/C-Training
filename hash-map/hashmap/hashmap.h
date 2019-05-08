#ifndef HASHMAP_INCLUDED
#define HASHMAP_INCLUDED
#include "./map/map.h"

typedef struct hashmap {
  map** data;
  unsigned int capacity;
} hashmap;

hashmap* newHashmap(char* key, int value);

unsigned long hash(char* str);

void printRow(map* head);

void print(hashmap* hashmap);

map* add(hashmap* hMap, char* key, int value);

map* get(hashmap* hMap, char* key);

int getValue(hashmap* hMap, char* key);

#endif