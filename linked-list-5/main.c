#include <stdio.h>
#include "list/list.h"

int main() {
  int N = 3;
  node* list = initialize(NULL, 12);
  print(list);
/*  
  printf("\n\nReversing the list...\n");
  list = reverse(list);
  print(list);

    
  printf("\n\nReversing each %i elements of the list...\n", N);
  list = reverseN(list, N);
  print(list);
*/
  printf("\n\nShuffling each %i elements of the list...\n", N);
  list = shuffleN(list, N);
  print(list);
  /**/
  return 0;
}