#include <stdio.h>
#include "list/list.h"

int main() {
  node* list = initialize(11);
  print(list);
  /*list = label(list);
  print(list);
  list = reverse(list);
  print(list);*/
  list = reverseN(8, list);
  print(list);
  return 0;
}