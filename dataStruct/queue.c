#include "queue.h"
#include<stdlib.h>
void init_q (queue *q ) { 
	q->head = NULL ; 
	q->tail = NULL ;
} 


bool enqueue ( queue *q, process_settings *proc ) 
{ 
	node* nwnode = (node *)malloc( sizeof(node));

	nwnode->proc = *proc ; 
	nwnode->nxt = NULL; 
	if ( q->tail == NULL && q->head == NULL) 
	{ 
		q->tail= q->head = nwnode ; 
		return 0 ; 
	} 
	q->tail->nxt = nwnode ; 
	q->tail = nwnode ; 
	// if the lis is empty 

return  0;
} 
process_settings* dequeue ( queue *q) 
{	process_settings *proc = malloc(sizeof(process_settings));


	if (q->head == NULL) return  0 ;
	node  *tmp = q->head ; 
	*proc = tmp->proc; 
	if (q->tail == q->head ) 
		q->tail = q->head = NULL ;
	else { 

	q->head = q->head->nxt ; 
	}	
	free( tmp) ; 	
		//printf("	-> the queue val : %d\n",res );
	return proc ;	
		 
}


void swap(process_settings* a,process_settings* b)
{
	process_settings temp; 
	temp =*a; 
	*a=*b; 
	*b=temp;
}
void bsort(queue *q)
{ 
	node *i,*j ; 

	bool state=false;
//	i=q; 
//	j=i->nxt; 
	for (i=q->head;i!=NULL;i=i->nxt)
	{
	  for (j=i->nxt;j!=NULL;j=j->nxt)
	  {
		{
		  if (j->proc.ta < i->proc.ta)
		  	swap(&(j->proc), &(i->proc)); 
		}
	  }
	}

return; 
}


