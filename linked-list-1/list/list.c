#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
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
    printf("%p:%d%s", head, head->data, (head->next == NULL) ? " -> NULL\n" : " -> ");
    head = head->next;
  }
}

node* initalize(node* head, int n) {
  node* list = head;
  while(n > 0) {
    node* elem = newNode(n);
    elem->next = list;
    list = elem;
    --n;
  }
  return list;
}

node* shuffle(node* list) {
  node* oddList = NULL;
  node* evenList = NULL;
  node* evenListHead = NULL;
  node* head = list;
  size_t i = 1;
  for(; list != NULL; list = list->next) {
    if(i == 1) {
      if(NULL == oddList) {
        oddList = list;
      } else {
        oddList->next = list;
        oddList = list;
      }
      i = 0;
    } else {
      if(NULL == evenList) {
        evenList = list;
        evenListHead = evenList;
      } else {
        evenList->next = list;
        evenList = list;
      }
      i = 1;    
    }
  }
  evenList->next = NULL;
  oddList->next = evenListHead; 
  return head;
}

node* shuffleN(node* head, int n) {
  if(n < 2) { 
    return head;
  }
  node* list = head;
  node** heads = (node**) malloc(n * sizeof(node));
  node** tails = (node**) malloc(n * sizeof(node));
  int i = 0;
  int areHeads = 1;
  for(; list != NULL; list = list->next, ++i) {
    if(areHeads && i <= n - 1) {
      *(tails + i) = list;
      *(heads + i) = list;
      if(i == n - 1) {
        areHeads = 0;
        i = -1;
      }
      continue;
    }
    if(i > n - 1) {
      i = 0;
    }
    (*(tails + i))->next = list;
    *(tails + i) = list;
  }
  for(i = 0; i < n - 1; ++i) {
    (*(tails + i))->next = *(heads + i + 1);
  }
  (*(tails + n - 1))->next = NULL;
  return head;
}

node* reverse(node* list) {
  node* next = NULL;
  node* prev = NULL;
  node* head = NULL;
  while(list != NULL) {
    next = list->next;
    list->next = prev;
    prev = list;
    if(NULL == next) {
      head = list;
    }
    list = next;
  }
  return head;
}

long getMicrotime() {
  struct timeval currentTime;
  gettimeofday(&currentTime, NULL);
  return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

