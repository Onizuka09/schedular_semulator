//
// Created by amani on 17/11/23.
//

#ifndef PROJECTSE_DATASTRUCTURE_H
#define PROJECTSE_DATASTRUCTURE_H

#endif //PROJECTSE_DATASTRUCTURE_H

// Definition of the Process structure representing a process with name, CPU units, priority, and arrival date.
typedef struct Process{
    char Name[10];
    int CPU_units;
    int priority;
    int Arrival_date;
    int remaining_time;
    int execution_time;
}Process;

//Queue
typedef struct
{
    Process value ;
    struct node* next   ;
}node;


typedef  struct {
    node *head ;
    node *tail ;
} queue;
void init_queue(queue *q)
{
    q->head=NULL;
    q->tail=NULL;
}

bool enqueue(queue *q, Process value){
    //create a new node
    node * newnode = malloc(sizeof (node));
    if(newnode==NULL){
        return false;
    }
    newnode->value =value;
    newnode->next=NULL;

    // if there is a tail , conncet that tail to this new node
    if(q->tail!=NULL){
        q->tail->next=newnode;
    }
    q->tail =newnode;
    //make sure the head makes sense
    if (q->head==NULL){
        q->head=newnode;
    }
    return true;
}

Process dequeue ( queue *q){
    // check to see if hte queue is empty
    //if ( q->head==NULL) return ;

    //save the head of the queue
    node *tmp = q->head;

    //save the result we're going to return
    Process result = tmp->value;

    //take it off
    q->head = q->head->next;
    if ( q->head ==NULL){
        q->tail=NULL;
    }
    return result;

}
void display(queue *q) {
    node *tmp = q->head;
    while (tmp != NULL) {
        printf("%d", tmp->value.CPU_units);
        tmp = tmp->next;
        printf(" | ");
    }
}
// Function to check if a queue is empty
int is_empty(queue* q) {
    return q->head == NULL;
}


    // linkedlist
    node *create_new_node(Process value){
        node *result = malloc(sizeof(node));
        result->value = value;
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
        //printf("%d -" , temporary->value.Arrival_date);
        printf("%d - ", temporary->value.Arrival_date);
        temporary = temporary->next;
    }
    printf("\n");
}
//***********************************************************
// sort list
/*Function to swap the nodes */
struct node* swap( node* ptr1,  node* ptr2)
{
     node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

/* Function to sort the list */
int bubbleSort( node** head, int count)
{
     node** h;
    int i, j, swapped;

    for (i = 0; i <= count; i++) {

        h = head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++) {

             node* p1 = *h;
             node* p2 = p1->next;

            if (p1->value.Arrival_date > p2->value.Arrival_date) {

                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }

        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}
