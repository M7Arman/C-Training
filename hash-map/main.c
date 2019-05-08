#include <stdio.h>
#include <limits.h>
#include "./hashmap/map/map.h"
#include "./hashmap/hashmap.h"

int main() {
  /*map* map = newMap("vazgen", 24);
  printMap(map);*/
  char* key = "hello";
  hashmap* hMap = newHashmap(key, 10);
  add(hMap, "Arman", 24);
  add(hMap, "Vardan", 18);
  add(hMap, "Ashot", 15);
  add(hMap, "John", 120);
  add(hMap, "Max", 101);

  print(hMap);
  return 0;
}
