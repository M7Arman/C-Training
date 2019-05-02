#include <stdio.h>
#include "list/list.h"

void testShuffleN();
void testShuffle();
void testReverse();

int main() {
 /* testShuffle();
  testShuffleN();*/
  testReverse();
  return 0;
}

/**
 * Tests shuffle N algorithm implementation for linked list
 */
void testShuffleN() {
  int count = 1000000;
  int n = 5;
  node* head = initialize(NULL, count);
  printf("\nInitialized the linked list with %d nodes\n", count);
  printf("\nStarting to shuffle with N....\n");
  long startTime = getMicrotime();
  head = shuffleN(head, n);
  printf("\nShuffling takes %lu microseconds for %d nodes and n = %d\n", getMicrotime() - startTime, count, n);
}

/**
 * Tests shuffle algorithm implementation for linked list
 */
void testShuffle() {
  int count = 100;
  node* head = initialize(NULL, count);
  printf("\nInitialized the linked list with %d nodes\n", count);
  printf("\nStarting to shuffle....\n");
  long startTime = getMicrotime();
  head = shuffle(head);
  printf("\nShuffling takes %lu microseconds for %d nodes\n", getMicrotime() - startTime, count);
}

/**
 * Tests reverse algorithm implementation for linked list
 */
void testReverse() {
  int count = 1000000;
  node* head = initialize(NULL, count);
  printf("\nInitialized the linked list with %d nodes\n", count);
  /*print(head);*/
  printf("\nStarting to reverse....\n");
  long startTime = getMicrotime();
  head = reverse(head);
  printf("\nReversing takes %lu microseconds for %d nodes\n", getMicrotime() - startTime, count);
  /*print(head);*/
}