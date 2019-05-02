#ifndef LIST_INCLUDED
#define LIST_INCLUDED

typedef struct node {
  int data;
  struct node* next;
} node;

node* initialize(node* list, int n);

void print(node* list);

node* reverse(node* list);

node* shuffle(node* list);

node* shuffleN(node* list, int n);

#endif