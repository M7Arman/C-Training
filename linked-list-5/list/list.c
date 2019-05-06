#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/**
 * Creates a new node with the given data
 */
node* newNode(int data) {
  node* elem = (node*) malloc(sizeof(node));
  elem->next = NULL;
  elem->data = data;

  return elem;
}

/**
 * Initialize the given list with n elements
 */
node* initialize(node* list, int n) {
  while(n > 0) {
    node* elem = newNode(n);
    elem->next = list;
    list = elem;
    --n;
  }
  return list;
}

/**
 * Prints the given list
 */
void print(node* list) {
  if(list == NULL) {
    printf("List is empty\n\n");
    return;
  }
  while(NULL != list) {
    printf("%p:%i%s", list, list->data, list->next == NULL ? " -> NULL \n" : " -> ");
    list = list->next;
  }
}

/**
 * Reverses the given list
 */
node* reverse(node* list) {
  node* prev = NULL;
  node* next = NULL;
  while(list != NULL) {
    next = list->next;
    list->next = prev;
    prev = list;
    list = next;
  }
  return prev;
}

/**
 * Reverses each N elements of the given list
 */
node* reverseN(node* list, int N) {
  if(N < 1 || list == NULL) {
    return list;
  }
  node* firstHead = NULL;
  node* head = NULL;
  node* tail = NULL;
  node* prevTail = NULL;
  node* prev = NULL;
  node* next = NULL;
  int i = 1;
  int isFirstHead = 1;
  for(; NULL != list; ++i) {
    if(i == 1) {
      prevTail = tail;
      tail = list;
      prev = tail;
      list = list->next;
    } else {
      if (i == N) {
        if(isFirstHead) {
          firstHead = list;
          isFirstHead = 0;
        }
        head = list;
        if(prevTail != NULL) {
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
    if(prevTail == NULL) {
      firstHead = prev;
    } else {
      prevTail->next = prev;      
    }
  }
  tail->next = NULL;
  return firstHead;
}

/**
 * Shuffles the given list
 */
node* shuffle(node* list) {
  return shuffleN(list, 2);
}

/**
 * Shuffles N elements of the given list
 */
node* shuffleN(node* list, int N) {
  if(list == NULL || N < 2) {
    return list;
  }
  node** heads = (node**) malloc(sizeof(node));
  node** tails = (node**) malloc(sizeof(node));
  node* head = list;
  int isHead = 1;
  int i = 0;
  for(; NULL != list; list = list->next, ++i) {
    if(isHead) {
      *(heads + i) = list;
      *(tails + i) = list;
      if(i == N - 1) {
        isHead = 0;
      }
      continue;
    }
    if(i > N - 1) {
      i = 0;
    }
    (*(tails + i))->next = list;
    *(tails + i) = (*(tails + i))->next;
  }
  if(isHead) { /* this means N is bigger than the list size */
    return head;
  }
  for(i = 0; i < N - 1; ++i) {
    (*(tails + i))->next = (*(heads + i + 1));
  }
  (*(tails + N - 1))->next = NULL;
  return *heads;
}
