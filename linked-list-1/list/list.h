#ifndef LIST_INCLUDED
#define LIST_INCLUDED

typedef struct node {
  int data;
  struct node* next;
} node;


node* newNode(int value);

void push(node* head, int value);

void print(node* head);

node* initalize(node* head, int n);

node* shuffle(node* list);

node* shuffleN(node* head, int n);

node* reverse(node* list);

long getMicrotime();

#endif
