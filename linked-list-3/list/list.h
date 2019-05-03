#ifndef INCLUDED_LIST
#define INCLUDED_LIST

typedef struct node
{
  int data;
  struct node *next;
} node;

node* newNode(int value);

node* initialize(int n);

node* label(node* list);

node* reverse(node* list);

node* reverseN(int N, node* list);

void print(node* list);

#endif