#include <stdlib.h>
#include <stdio.h>
#include "list.h"

node* newNode(int value) {
  node* elem = (node*) malloc(sizeof(node));
  elem->next = NULL;
  elem->data = value;

  return elem;
}

node* initialize(node* list, int n) {
  while(n) {
    node* elem = newNode(n);
    elem->next = list;
    list = elem;
    --n;
  }
  return list;
}

void print(node* list) {
  if(NULL == list) {
    printf("\nList is empty\n\n");
    return;
  }
  while(NULL != list) {
    printf("%p:%d%s", list, list->data, (NULL == list->next) ? " -> NULL \n" : " -> ");
    list = list->next;
  }
}

node* reverse(node* list) {
  node* prev = NULL;
  node* next = NULL;
  while(NULL != list) {
    next = list->next;
    list->next = prev;
    prev = list;
    list = next;
  }
  return prev;
}

node* reverseN(node* list, int n) {
  if(n < 2 || NULL == list) {
    return list;
  }
  node* prevTail = NULL;
  node* tail = NULL;
  node* head = NULL;
  node* firstHead = NULL;
  node* prev = NULL;
  node* next = NULL;
  int i = 1;
  int isFirstHead = 1;
  for(; NULL != list; ++i) {
    if(1 == i) {
      prevTail = tail;
      tail = list;
      prev = list;
      list = list->next;
    } else {
      if(i == n) {
        if(isFirstHead) {
          firstHead = list;
          isFirstHead = 0;
        }
        head = list;
        if(NULL != prevTail) {
          prevTail->next = head;
        }
        i = 0;
      }
      next = list->next;
      list->next = prev;
      prev = list;
      list = next;
    }
  }
  if(i != 1) {
    if(NULL == prevTail) {
      firstHead = prev;
    } else {
      prevTail->next = prev;
    }
  }
  tail->next = NULL;
  return firstHead;
}

node* shuffle(node* list) {
  return shuffleN(list, 2);
}

node* shuffleN(node* list, int n) {
  if(n < 2 || NULL == list) {
    return list;
  }
  node** heads = (node**) malloc(sizeof(node) * n);
  node** tails = (node**) malloc(sizeof(node) * n);
  int i = 0;
  int isHead = 1;
  for(; NULL != list; list = list->next, ++i) {
    if(isHead) {
      *(heads + i) = list;
      *(tails + i) = list;
      if(i == n - 1) {
        isHead = 0;
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