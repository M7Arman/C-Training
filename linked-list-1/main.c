#include <stdio.h>
#include "list/list.h"

int main() {
  node* head = newNode(5);
  print(head);
  push(head, 4);
  push(head, 4);
  push(head, 4);
  print(head);
  return 0;
}
