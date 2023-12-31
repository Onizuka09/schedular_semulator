#include<stdio.h>
#include "queue.h"
#include<stdlib.h>
void init_queue (queue *q ) { 
	q->head = NULL ; 
	q->tail = NULL ;
} 
bool enqueue ( queue *q, Process *proc ) 
{ 
	node* nwnode = (node *)malloc( sizeof(node));
	if (nwnode == NULL ) 
		return false; 
	nwnode->proc = *proc ; 
	nwnode->next = NULL; 
	if ( q->tail == NULL && q->head == NULL) 
	{ 
		q->tail= q->head = nwnode ; 
		return true  ; 
	} 
	q->tail->next = nwnode ; 
	q->tail = nwnode ; 
return  true;
} 
Process* dequeue ( queue *q) 
{	Process *proc = malloc(sizeof(Process));
	if (proc == NULL)
		return NULL; 
	if (q->head == NULL) return  NULL ;
	node  *tmp = q->head ; 
	*proc = tmp->proc; 
	if (q->tail == q->head ) 
		q->tail = q->head = NULL ;
	else { 
	q->head = q->head->next ; 
	}	
	free( tmp) ; 	
	return proc ;	
}
void display(queue *q) {
    node *tmp = q->head;
    while (tmp != NULL) {
        printf("%d", tmp->proc.te);
        tmp = tmp->next;
        printf(" | ");
    }
}
static void swap(Process* a,Process* b)
{
	Process temp; 
	temp =*a; 
	*a=*b; 
	*b=temp;
}
void queue_bsort(queue *q)
{ 
	node *i,*j ; 
	for (i=q->head;i!=NULL;i=i->next)
	{
	  for (j=i->next;j!=NULL;j=j->next)
	  {
		{
		  if (j->proc.ta < i->proc.ta)
		  	swap(&(j->proc), &(i->proc));
		}
	  }
	}
return; 
}
void queue_bsort_1(queue *q)
{
	node *i, *j;
	for (i = q->head; i != NULL; i = i->next)
	{
		for (j = i->next; j != NULL; j = j->next)
		{
			{
				if (j->proc.ta < i->proc.ta)
					swap(&(j->proc), &(i->proc));
				else if (j->proc.ta == i->proc.ta)
				{
					if ((j->proc.te < i->proc.te))
						swap(&(j->proc), &(i->proc));
				}
			}
		}
	}
	return;
}
void queue_bsort_2(queue *q)
{
	node *i, *j;
	for (i = q->head; i != NULL; i = i->next)
	{
		for (j = i->next; j != NULL; j = j->next)
		{
			{
				if (j->proc.ta < i->proc.ta)
					swap(&(j->proc), &(i->proc));
				else if (j->proc.ta == i->proc.ta)
				{
					if ((j->proc.priority > i->proc.priority))
						swap(&(j->proc), &(i->proc));
				}
			}
		}
	}
	return;
}
void queue_bsort_te(queue *q)
{
	node *i, *j;
	for (i = q->head; i != NULL; i = i->next)
	{
		for (j = i->next; j != NULL; j = j->next)
		{
			{
				if (j->proc.remaining_time < i->proc.remaining_time)
					swap(&(j->proc), &(i->proc));
				else if (j->proc.remaining_time == i->proc.remaining_time)
				{
					if ((j->proc.ta < i->proc.ta))
						swap(&(j->proc), &(i->proc));
				}
			}
		}
	}
	return;
}
void queue_bsort_priority(queue *q)
{
	node *i, *j;
	for (i = q->head; i != NULL; i = i->next)
	{
		for (j = i->next; j != NULL; j = j->next)
		{
			{
				if (j->proc.priority > i->proc.priority)
					swap(&(j->proc), &(i->proc));
				else if (j->proc.priority == i->proc.priority)
				{
					if ((j->proc.ta < i->proc.ta))
						swap(&(j->proc), &(i->proc));
				}
			}
		}
	}
	return;
}
bool is_empty(queue* q) {
    return q->head == NULL;
}
void search_for_least_min_te(queue *q, queue *wait_list, int time)
{
	Process *p;
	queue *tmp = (queue *)malloc(sizeof(queue));
	if (tmp == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for queue.\n");
		exit(EXIT_FAILURE);
	}
	init_queue(tmp);
	tmp->head = q->head;
	while (tmp->head != NULL)
	{
		if (tmp->head->proc.ta <= time)
		{
			p = dequeue(tmp);
			q->head = tmp->head;
			enqueue(wait_list, p);
		}
		else
		{
			tmp->head = tmp->head->next;
		}
	}
	free(tmp);
	return;
}