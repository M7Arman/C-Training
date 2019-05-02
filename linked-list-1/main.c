#include <stdio.h>
#include "list/list.h"

int main() {
  node* head = initalize(NULL, 1000000);
  int n = 5;
  printf("\nInitial list....\n");
 /* print(head);
  printf("\nStarting to reverse....\n");
  head = reverse(head);
  print(head);
  printf("\nStarting to shuffle....\n");
  head = shuffle(head);
  print(head);*/
  printf("\nStarting to shuffle with N....\n");
  long startTime = getMicrotime();
  head = shuffleN(head, n);
  printf("\nShuffling takes %lu microseconds for 1M nodes and n = %d\n", getMicrotime() - startTime, n);
 /* print(head);*/
  return 0;
}
