#include <stdio.h>
#include "list/list.h"

int main() {
  node* list = initialize(NULL, 20);/*
  print(list);
  printf("\n\nShuffling each N nodes of the list...\n");
  list = shuffleN(list, 2);
  print(list);

  printf("\n\nReversing the list...\n");
  list = reverse(list);
  print(list);
  printf("\n\nReversing each N nodes of the list...\n");*/
  print(list);
  list = reverseN(list, 5);
  print(list);
  return 0;
}
