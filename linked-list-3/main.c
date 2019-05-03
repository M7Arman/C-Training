#include <stdio.h>
#include "list/list.h"

void testReverseN();
void testReverse();
void testLabel();

int main() {
  testReverse();
  return 0;
}

void testReverseN() {
  node* list = initialize(10);
  print(list);
  list = reverseN(5, list);
  print(list);
}

void testReverse() {
  node* list = initialize(10);
  print(list);
  list = reverse(list);
  print(list);
}

void testLabel() {
  node* list = initialize(10);
  print(list);
  list = label(list);
  print(list);
}