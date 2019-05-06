#ifndef INCLUDED_LIST
#define INCLUDED_LIST

typedef struct node {
  int data;
  struct node* next;
} node;

/**
 * Creates a new node with the given data
 */
node* newNode(int data);

/**
 * Initialize the given list with n elements
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
 * Reverses each N elements of the given list
 */
node* reverseN(node* list, int N);

/**
 * Shuffles the given list
 */
node* shuffle(node* list);

/**
 * Shuffles N elements of the given list
 */
node* shuffleN(node* list, int N);

#endif