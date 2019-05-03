#ifndef INCLUDED_LIST
#define INCLUDED_LIST

typedef struct node
{
  int data;
  struct node *next;
} node;

/**
 * Creates a new node with the given value
 */
node* newNode(int value);

/**
 * Create a list, which nodes count is n
 */
node* initialize(int n);

/**
 * Sets consecutive integer values to the list nodes started with 1
 */
node* label(node* list);

/**
 * Reverses the given list
 */
node* reverse(node* list);

/**
 * Reverses each N nodes of the given list 
 */
node* reverseN(int N, node* list);

/**
 * Prints the given list
 */
void print(node* list);

#endif