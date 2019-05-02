#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node* newNode(int value) {
  node* elem = (node*) malloc(sizeof(node));
  elem->data = value;
  elem->next = NULL;
  return elem;
}

node* initialize(node* list, int n) {
  while (n > 0) {
    node* elem = newNode(n);
    elem->next = list;
    list = elem;
    --n;
  }
  return list;
}

void print(node* list) {
  if(list == NULL) {
    printf("\nList is empty\n");
    return;
  }
  while(list != NULL) {
    printf("%p:%d%s", list, list->data, list->next == NULL ? " -> NULL\n" : " -> ");
    list = list->next;
  }
}

node* reverse(node* list) {
  node* next = NULL;
  node* prev = NULL;
  while(list != NULL) {
    next = list->next;
    list->next = prev;
    if(NULL == next) {
      break;
    }
    prev = list;
    list = next;
  }
  return list;
}

node* reverseN(node* list, int n) {
  int i = 1;
  int isFirstHead = 1;
  node* firstHead = NULL;
  node* tail = NULL;
  node* head = NULL;
  for(; NULL != list; list = list->next, ++i) {
    if(isFirstHead && i == n) {
      firstHead = list;
    }
    if(0 == i) {
      tail = list;
      //TODO: continue...
    }
      //TODO: continue...
  }
  return firstHead;
}

node* shuffle(node* list) {
  return shuffleN(list, 2);
}

node* shuffleN(node* list, int n) {
  if(n < 2) {
    return list;
  }
  int i = 0;
  int isHead = 1; /** boolean variable to check if it's one of head nodes */
  node** heads = (node**) malloc(n * sizeof(node));
  node** tails = (node**) malloc(n * sizeof(node));
  for(; NULL != list; list = list->next, ++i) {
    if(isHead) {
      *(heads + i) = list;
      *(tails + i) = list;
      if(i == n - 1) {
        isHead = 0; /** make isHead false */
      }
      continue;
    }
    if(i == n) {
      i = 0;
    }
    (*(tails + i))->next = list;
    *(tails + i) = list;
  }

  for(i = 0; i < n - 1; ++i) {
    (*(tails + i))->next = *(heads + i + 1);
  }
  (*(tails + n - 1))->next = NULL;
  return *heads;
}