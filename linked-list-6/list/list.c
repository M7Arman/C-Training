#include <stdlib.h>
#include <stdio.h>
#include "list.h"

node* newNode(int value) {
  node* elem = (node*) malloc(sizeof(node));
  if(elem != NULL) {
    elem->data = value;
    elem->next = NULL;
  }
  return elem;
}

node* initialize(int N) {
  int i = 0;
  node* head = newNode(i++);
  node* list = head;
  while(i < N) {
    if(list == NULL) {
      break;
    }
    list->next = newNode(i++);
    list = list->next;
  }
  return  head;
}

node *label(node *list) {
  node* head = list;
  int i;
  for(i = 1; NULL != list; list = list->next, ++i) {
    list->data = i;
  }
  return head;
}

void print(node* list) {
  if(NULL == list) {
    printf("List is empty\n\n");
  }
  for(; NULL != list; list = list->next) {
    printf("%p:%i -> ", list, list->data);
  }
  printf("NULL\n\n");
}

node *reverse(node *list) {
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

node *reverseN(int N, node *list) {
  node* firstHead = NULL;
  node* head = NULL;
  node* tail = NULL;
  node* prevTail = NULL;
  node* next = NULL;
  node* prev = NULL;
  int isFirstHead = 1;
  int i;
  for(i = 1; NULL != list; ++i) {
    if(i == 1) {
      prevTail = tail;
      tail = list;
      prev = list;
      list = list->next;
    } else {
      if(i == N) {
        head = list;
        if(isFirstHead) {
          firstHead = head;
          isFirstHead = 0;
        }
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
  if(1 != i && NULL != prevTail) {
    prevTail->next = prev;
  }
  if(NULL != tail) {
    tail->next = NULL;
  }
  if(NULL == firstHead) {
    firstHead = prev;
  }
  return firstHead;
}