#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node* newNode(int value) {
  node* elem = (node*) malloc(sizeof(node));	
  elem->data = value;
  elem->next = NULL;
  return elem;
}

void push(node* head, int value) {
  node* elem = newNode(value);
  if(head == NULL) {
    head = elem;
  } else {
    while(head->next != NULL) {
      head = head->next;
    }
    head->next = elem;
  }
}

void print(node* head) {
  while(head != NULL) {
    printf("%d%s", head->data, (head->next == NULL) ? "\n" : " -> ");
    head = head->next;
  }
}

