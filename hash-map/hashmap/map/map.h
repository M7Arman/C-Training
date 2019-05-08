#ifndef MAP_INCLUDED
#define MAP_INCLUDED

typedef struct map {
  int value;
  char* key;
  struct map* next;
} map;

map* newMap(char* key, int value);

void printMap(map* elem);

#endif
