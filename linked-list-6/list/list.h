#ifndef LIST_INCLUDED
#define LIST_INCLUDED

typedef struct node {
  int data;
  struct node* next;
} node;

node* newNode(int value);

node* initialize(int value);

node* label(node *list);

node* reverse(node *list);

node* reverseN(int N, node *list);

void print(node* list);

#endif