#ifndef LIST_INCLUDED
#define LIST_INCLUDED

typedef struct node {
  int data;
  struct node* next;
} node;

/**
 * Initialize the list with n nodes, if list is NULL it creates a new one
 */
node* initialize(node* list, int n);

/**
 * Prints the given list
 */
void print(node* list);

/**
 * Reverses the given list
 */
node* reverse(node* list);

/**
 * Reverses each n nodes of the list and joins them into one list
 */
node* reverseN(node* list, int n);

/**
 * Shuffles the given list
 */
node* shuffle(node* list);

/**
 * Shuffles each n nodes of the given list and joins them into one list
 */
node* shuffleN(node* list, int n);

#endif