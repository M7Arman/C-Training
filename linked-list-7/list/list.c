#include <stdlib.h>
#include <stdio.h>
#include "list.h"

node* newNode(int value) {
  node* elem = (node*) malloc(sizeof(node));
  elem->next = NULL;
  elem->data = value;

  return elem;
}

node* initialize(int N) {
  if(N < 1) {
    return NULL;
  }
  node* list = newNode(N);
  node* head = list;
  while(N > 1) {
    --N;
    list->next = newNode(N);
    list = list->next;
  }

  return head;
}

void print(node* list) {
  if(NULL == list) {
    printf("List is empty!\n");
    return;
  }
  while(NULL != list) {
    printf("%p:%d -> ", list, list->data);
    list = list->next;
  }
  printf("NULL\n");
}

node* label(node* list) {
  int i;
  node* head = list;
  for(i = 1; NULL != list; ++i, list = list->next) {
    list->data = i;
  }
  return head;
}

node* reverse(node* list) {
  node* next = NULL;
  node* prev = NULL;
  while(NULL != list) {
    next = list->next;
    list->next = prev;
    prev = list;
    list = next;
  }
  return prev;
}

node *reverseN(int N, node *list) {
  if(N < 2 || NULL == list) {
    return list;
  }
  node* tail = NULL;
  node* prevTail = NULL;
  node* head = NULL;
  node* firstHead = NULL;
  node* prev = NULL;
  node* next = NULL;
  int i = 1, isFirstHead = 1;
  for(; NULL != list; ++i) {
    if(1 == i) {
      prevTail = tail;
      tail = list;
      prev = list;
      list = list->next;
    } else {
      if(i == N) {
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
  tail->next = NULL;
  if(NULL == firstHead) {
    return prev;
  }
  if(i != 1) {
    prevTail->next = prev;
  }
  return firstHead;
}
