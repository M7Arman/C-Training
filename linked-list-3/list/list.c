#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "list.h"

node* newNode(int value) {
  node* elem = (node*) malloc(sizeof(node));
  if(NULL == elem) {
    return NULL;
  }
  elem->data = value;
  elem->next = NULL;
  return elem;  
}

node* initialize(int n) {
  node* head = NULL;
  node* elem = NULL;
  srand(time(NULL));
  while(n > 0) {
    elem = newNode(rand() % 100);
    elem->next = head;
    head = elem;
    --n;
  }
  return head;
}

node* label(node* list) {
  int i = 1;
  node* head = list;
  for(; list != NULL; list = list->next) {
    list->data = i;
    ++i;
  }
  return head;
}

node* reverse(node* list) {
  int n = 0;
  node* next = NULL;
  node* prev = NULL;
  while(list != NULL) {
    next = list->next;
    list->next = prev;
    prev = list;
    list = next;
  }
  return prev;
}

node* reverseN(int N, node* list) {
  if(N < 2 || NULL == list) {
    return list;
  }
  node* head = NULL;
  node* firstHead = NULL;
  node* tail = NULL;
  node* prevTail = NULL;
  node* prevElem = NULL;
  int isFirstHead = 1;
  int i;
  for(i = 1; list != NULL; ++i) {
    if(isFirstHead && i == N) {
      firstHead = list;
      isFirstHead = 0;
    }
    if(i == 1) {
      prevTail = tail;
      tail = list;
      prevElem = list;
      list = list->next;
      continue;
    } else if(i == N) {
      head = list;
      if(prevTail != NULL) {
        prevTail->next = head;
      }
      i = 0;
    }
    node* next = list->next;
    list->next = prevElem;
    prevElem = list;
    list = next;
  }
  if(1 != i) {
    if(NULL != prevTail) {
      prevTail->next = prevElem;
    } else {
      firstHead = prevElem;
    }
  }
  tail->next = NULL;
  return firstHead;
}

void print(node* list) {
  if(NULL == list) {
    printf("\nList is empty\n\n");
  }
  for(; list != NULL; list = list->next) {
    printf("%d%s", list->data, NULL == list->next ? "\n" : " -> " );
  }
}
