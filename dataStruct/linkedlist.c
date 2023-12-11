  #include "linkedlist.h"
  #include <stdio.h>
  #include<stdlib.h>
node *create_new_node(Process value){
        node *result = malloc(sizeof(node));
        result->proc = value;
        result->next =NULL;
        return result;
}
node *create_new_node_new(Process *value){
        node *result = malloc(sizeof(node));
        result->proc = *value;
        result->next =NULL;
        return result;
}
node *insert_at_head(node **head, node *node_to_insert){
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}
void printlist(node *head){
    node *temporary = head;
    while (temporary !=NULL){
        printf("%d - ", temporary->proc.ta);
        temporary = temporary->next;
    }
    printf("\n");
}
static  node* swap( node* ptr1,  node* ptr2)
{
     node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}
int linkedlist_bubbleSort( node** head, int count)
{
     node** h;
    int i, j, swapped;
    for (i = 0; i <= count; i++) {
        h = head;
        swapped = 0;
        for (j = 0; j < count - i - 1; j++) {
             node* p1 = *h;
             node* p2 = p1->next;
            if (p1->proc.ta > p2->proc.ta) {
                *h = swap(p1, p2);
                swapped = 1;
            }
            h = &(*h)->next;
        }
        if (swapped == 0)
            break;
    }
     return 0;
}
int linkedlist_bubbleSortpriority( node** head, int count)
{
     node** h;
    int i, j, swapped;
    for (i = 0; i <= count; i++) {
        h = head;
        swapped = 0;
        for (j = 0; j < count - i - 1; j++) {
             node* p1 = *h;
             node* p2 = p1->next;
            if (p1->proc.priority < p2->proc.priority) {
                *h = swap(p1, p2);
                swapped = 1;
            }
            else if (p1->proc.priority == p2->proc.priority){
                if (p1->proc.ta > p2->proc.ta) {
                *h = swap(p1, p2);
                swapped = 1;
            }
            }
            h = &(*h)->next;
        }
        if (swapped == 0)
            break;
    }
     return 0;
}