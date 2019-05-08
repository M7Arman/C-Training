#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "hashmap.h"
#include "./map/map.h"
#define TABLE_SIZE 15

unsigned int hash(char* str) {
  int sum = 0;
  int c;
  for (; '\0' != *str; str++) {
    sum += *str;
  }
  return sum % TABLE_SIZE;
}

hashmap* newHashmap(char* key, int value) {
  hashmap* hMap = (hashmap*) malloc(sizeof(hashmap));
  if(NULL == hMap) {
    return NULL;
  }
  map** data = (map**) malloc(sizeof(map*) * TABLE_SIZE);
  if(NULL == data) {
    free(hMap);
    return NULL;
  }
  int i;
  for(i = 0; i < TABLE_SIZE; ++i) {
    data[i] = NULL;
  }
  hMap->data = data;
  unsigned int h = hash(key);
  hMap->data[h] = newMap(key, value);
  return hMap;
}

map* get(hashmap* hMap, char* key) {
  unsigned int h = hash(key);
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
  unsigned int h = hash(key);
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
  for(i = 0; i < TABLE_SIZE; ++i) {
    printf("[%i]\t",i);
    printRow(hashmap->data[i]);
  }
}