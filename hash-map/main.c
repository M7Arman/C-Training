#include <stdio.h>
#include <limits.h>
#include "./hashmap/map/map.h"
#include "./hashmap/hashmap.h"

int main() {
  /*map* map = newMap("vazgen", 24);
  printMap(map);*/
  char* key = "hello";
  hashmap* hMap = newHashmap(key, 10);
  add(hMap, "asd", 7);
  add(hMap, "211", 8);
  add(hMap, "212", 5);
  add(hMap, "as2", 120);
  add(hMap, "dsa", 101);

  print(hMap);
  return 0;
}
