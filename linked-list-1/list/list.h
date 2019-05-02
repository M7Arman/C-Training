#ifndef LIST_INCLUDED
#define LIST_INCLUDED

typedef struct node {
  int data;
  struct node* next;
} node;

/**
 * Created a new node with the given value
 */
node* newNode(int value);

/**
 * Prints the given linked list with the following structure <NODE_ADDRESS>:<NODE_VALUE> -> <NODE_ADDRESS>:<NODE_VALUE> -> ...
 */
void print(node* head);

/**
 * Initializes the linked list with the consecutive integer values and returns the new list
 */
node* initialize(node* head, int n);

/**
 * Shuffles the linked list as follow:
 * - nodes with odd indexes (positions) are brought to the beginning of the list
 * - nodes with even indexes (positions) are appended to the end of the list with odd indexes
 */
node* shuffle(node* list);

/**
 * Shuffles the given list so the resulting list becomes
 * 1st node -> (n+1)th node -> (2n+1)th node -> ... -> 2nd node -> (n+2)th node -> 
 * (2n + 2)th node -> ... -> (n)th node -> (2n)th node -> ...
 */
node* shuffleN(node* head, int n);

/**
 * Reverses the given list
 */
node* reverse(node* list);

/**
 * Gets the current microtime
 */
long getMicrotime();

#endif
