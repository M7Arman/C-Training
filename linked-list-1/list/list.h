#ifndef LIST_INCLUDED
#define LIST_INCLUDED

typedef struct node {
  int data;
  struct node* next;
} node;


node* newNode(int value);

void push(node* head, int value);

void print(node* head);

#endif
