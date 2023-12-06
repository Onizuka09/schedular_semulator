#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"
#include<stdbool.h>

typedef  struct { 
	node* head ; 
	node* tail ;
 } queue; 

void init_queue (queue *q );

bool enqueue ( queue *q, Process *proc ) ;

Process* dequeue ( queue *q) ;

// void swap(Process* a,Process* b);
void queue_bsort_te(queue *q);

void queue_bsort(queue *q);
void queue_bsort_1(queue *q);//te
void queue_bsort_2(queue *q);//priority 
void display(queue *q);
bool is_empty(queue* q); 
void queue_bsort_priority(queue *q);



#endif /* ifndef  */
