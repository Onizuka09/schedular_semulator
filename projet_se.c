#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <pthread.h>
#define max_chars 50
#define ESC "\033"
#define CSI "[" 
#define previousLine "F" 
#define backspace "D" 
#define num_bars 1 

typedef struct 
{ 
	int val ; 
	struct node* nxt   ; 
 }node; 


typedef  struct { 
	node* head ; 
	node* tail ;
 } queue; 

void init_q (queue *q ) { 
	q->head = NULL ; 
	q->tail = NULL ;
} 

bool enqueue ( queue *q, int val ) 
{ 
	node* nwnode = (node *)malloc( sizeof(node));

	nwnode->val = val ; 
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
int dequeue ( queue *q) 
{	int res =0 ;  
	if (q->head == NULL) return  0 ;
	node  *tmp = q->head ; 
	res = tmp->val; 
	if (q->tail == q->head ) 
		q->tail = q->head = NULL ;
	else { 

	q->head = q->head->nxt ; 
	}	
	free( tmp) ; 	
		//printf("	-> the queue val : %d\n",res );
	return res ;	
		 
} 
void update_bar(int total_time,int time_done) { 
	int percentage_done = time_done *100 / total_time;
	int num_chars = (percentage_done * max_chars) /100 ;
	printf("["); 
	for (int i = 0 ; i<num_chars ; ++i ) 
	{	
		printf("#");
	}
	for (int i = 0; i<max_chars - num_chars; ++i )
	{	 
		printf(" ");
	}

	printf("] %d%% done \n",percentage_done);
	fflush(stdout); 
}
 int main(void)
{	
int x,r,sum=0 ; 
	printf("This is a FiFo proc execution !\n");
	printf("Enter num of proc \n "); 
	scanf("%d",&x); 
	queue q1 ; 
	init_q(&q1) ; 	
	printf("Generating now time for each proc ...\n",x);
	for ( int i = 1 ; i<=x ; ++i) 
	{
		r = rand()%10; 
		printf ("proc_%i = %d \n",i,r) ; 
		enqueue(&q1,r);
		sum +=r ; 
	}
	sleep(2); 
	printf("Total Time is %d \n",sum );  
int t=0,i=1,temp=0; 
	while (q1.tail != NULL) 
	{
		t= dequeue(&q1); 
		temp+=t;
		printf("\rExecuting now proc_%d for %d ...\n",i,t);
		fflush(stdout); 
		update_bar(sum,temp);
		printf(ESC CSI "%d" previousLine,2 );// resetting the curesor for the 2 lines 
		i++; 
	}	
	printf("\n\nDone !\n"); 
	return 0;
}
