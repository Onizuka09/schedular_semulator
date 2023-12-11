#ifndef LINKEDLIST_H 
#define LINKEDLIST_H 
#include "node.h"
node *create_new_node(Process value);
node *insert_at_head(node **head, node *node_to_insert);
void printlist(node *head) ;
int linkedlist_bubbleSort( node** head, int count);
int linkedlist_bubbleSortpriority( node** head, int count);
#endif