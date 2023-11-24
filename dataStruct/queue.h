#ifndef QUEUE_H
#define QUEUE_H
#include "../process_def.h"
#include<stdbool.h>
typedef struct 
{ 
	 process_settings proc ;  
	struct node* nxt   ; 
 }node; 
typedef  struct { 
	node* head ; 
	node* tail ;
 } queue; 

void init_q (queue *q );

bool enqueue ( queue *q, process_settings *proc ) ;

process_settings* dequeue ( queue *q) ;


void swap(process_settings* a,process_settings* b);
void bsort(queue *q);

#endif /* ifndef  */
