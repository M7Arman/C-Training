#include <stdio.h>
#include "list/list.h"

int main() {
  node* list = initialize(13);
  print(list);
  list = label(list);
  print(list);
  list = reverse(list);
  print(list);
  return 0;
}

