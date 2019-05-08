#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "hashmap.h"
#include "./map/map.h"

unsigned long hash(char* str) {
  unsigned long hash = 5381;
  int c;

  while (c = *str++)
      hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

  return hash % 10; /** return hash; */
}

hashmap* newHashmap(char* key, int value) {
  hashmap* hMap = (hashmap*) malloc(sizeof(hashmap));
  if(NULL == hMap) {
    return NULL;
  }
  unsigned long h = hash(key);
  hMap->data[h] = newMap(key, value);
  return hMap;
}

map* get(hashmap* hMap, char* key) {
  unsigned long h = hash(key);
  map* map = hMap->data[h];
  while(NULL != map) {
    if(map->key == key) {
      return map;
    }
    map = map->next;
  }
  return NULL;
}

int getValue(hashmap* hMap, char* key) {
  map* map = get(hMap, key);
  if(NULL != map) {
    return map->value;
  }
  return INT_MIN;
}

void printRow(map* head) {
  if(NULL == head) {
    printf("Row is empty\n");
    return;
  }
  while(head != NULL) {
    printf("(%s: %d)%s", head->key, head->value, NULL == head->next ? "\n" : " -> ");    
    head = head->next;
  }
}

map* add(hashmap* hMap, char* key, int value) {
  unsigned long h = hash(key);

  map* map = hMap->data[h];
  if(NULL == map) {
    hMap->data[h] = newMap(key, value);
    return hMap->data[h];
  }
  while(1) {
    if(map->key == key) {
      map->value = value;
      return map;
    }
    if(NULL == map->next) {
      map->next = newMap(key, value);
      return map->next;
    }
    map = map->next;
  }
}


void print(hashmap* hashmap) {
  int i;
  for(i = 0; i < 10; ++i) {
    printf("[%i]\t",i);
    printRow(hashmap->data[i]);
  }
}