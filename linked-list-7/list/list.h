#ifndef LIST_INCLUDED
#define LIST_INCLUDED

typedef struct node {
  int data;
  struct node* next;
} node;

node* initialize(int N);

void print(node* list);

node* label(node* list);

node* reverse(node* list);

node *reverseN(int N, node *list);

#endif
