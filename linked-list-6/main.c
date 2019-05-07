#include <stdlib.h>
#include <stdio.h>
#include "list/list.h"

int main() {
  node* list = initialize(10);
  print(list);
  list = reverse(list);
  print(list);
  list = label(list);
  print(list);
  list = reverseN(12, list);
  print(list);
  return 0;
}