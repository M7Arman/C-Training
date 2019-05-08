#include <stdlib.h>
#include <stdio.h>
#include "map.h"

map* newMap(char* key, int value) {
  map* elem = (map*) malloc(sizeof(map));
  if(elem == NULL) {
    return NULL;
  }
  elem->key = key;
  elem->value = value;
  elem->next = NULL;

  return elem;
}

void printMap(map* elem) {
  printf("%s: %i\n", elem->key, elem->value);
}
