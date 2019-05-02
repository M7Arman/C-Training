#include <stdio.h>
#include "./list/list.h"

void testReverse();
void testShuffleN();
void testShuffle();

int main() {
  testShuffle();
  testShuffleN();
  testReverse();
  return 0;
}

void testReverse() {
  int count = 50;
  node* head = initialize(NULL, count);
  print(head);
  printf("\nReversing with %d nodes....\n\n", count);
  head = reverse(head);
  print(head);
}

void testShuffleN() {
  int n = 10;
  int count = 5000000;
  node* head = initialize(NULL, count);
  /** print(head); */
  printf("\nShuffling with %d nodes and n = %d....\n\n", count, n);
  head = shuffleN(head, n);
  /** print(head); */
}

void testShuffle() {
  int count = 50;
  node* head = initialize(NULL, count);
  /** print(head); */
  printf("\nShuffling with %d nodes....\n\n", count);
  head = shuffle(head);
  /** print(head); */
}