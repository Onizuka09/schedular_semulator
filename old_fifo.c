#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <pthread.h>
#include <string.h>

#define max_chars 50 
#define ESC "\033"
#define CSI "[" 
#define previousLine "F" 
#define backspace "D" 
#define forward "C"
#define num_bars 1 
#define endd_bar 0 
#define RED_TEXT    "\x1b[31m"
#define GREEN_TEXT  "\x1b[32m"
#define YELLOW_TEXT "\x1b[33m"
#define RESET_TEXT  "\x1b[0m"


typedef enum {
	green,
	yellow,
	red,
	reset,
}colors;
typedef struct { 
	int ta; 
	int te; 
	int priority; 
	char name[10] ;
	colors color;

}process_settings; 


void pick_color(colors color, char* ch_color) {
    if (color == green)
        strcpy(ch_color, GREEN_TEXT);
    else if (color == red)
        strcpy(ch_color, RED_TEXT);
    else if (color == yellow)
        strcpy(ch_color, YELLOW_TEXT);
    else
        strcpy(ch_color, RESET_TEXT);
}

void proc_print(process_settings* proc ); 
typedef struct 
{ 
	 process_settings proc ;  
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
void update_bar(int total_time,int current_time,int te,int time,colors cl) {

	int p_t = time*100/total_time;
	int written_chars = (p_t * max_chars) /100 ;


	int p_te = te*100/total_time;
	int num_chars = (p_te * max_chars) /100 ;

	int p_ct = current_time *100 / total_time;
	int char_ct = (p_ct * max_chars) /100 ;

	char cl_str[15]="";
	pick_color(cl,cl_str);
	int num_white_spaces=0;
	if (time !=0)
	{	printf(ESC CSI "%d" forward,max_chars);
		printf(ESC CSI "%d" backspace "\033[K",max_chars - written_chars);   
		fflush(stdout); 
		num_white_spaces=max_chars -( num_chars + written_chars);
	}
	else 
	{	num_white_spaces = max_chars - num_chars ;
		printf("[");
	}
	printf("%s",cl_str);
	for (int i = 0 ; i<num_chars ; ++i ) 
	{	
		printf("#");
	}
	
	for (int i = 0; i<num_white_spaces; ++i )
	{	 
		printf(" ");
	}

	printf(RESET_TEXT"] %d%% done\n",p_ct);
	fflush(stdout); 
}
void proc_print(process_settings* proc ) 
{
	
	printf("name %s\n",proc->name);
	printf("ta: %d\n",proc->ta);
	printf("te: %d\n",proc->te); 
	printf("prio: %d\n",proc->priority);

}
colors intToColor(int value) {
    switch (value) {
        case 0:
            return green;
        case 1:
            return yellow;
        case 2:
            return red;
        default:
            return reset;
    }
}
void get_userInput(process_settings* proc){ 
	//proc->name = malloc(255);
	int cl=0;
	printf("enter name: "); 
	scanf("%s",proc->name);
	printf("enter ta: "); 
	scanf("%d",&proc->ta);
	printf("enter te: "); 
	scanf("%d",&proc->te);
	printf("enter priority: "); 
	scanf("%d",&proc->priority);
	printf("enter color: ");
	scanf("%d",&cl);
	proc->color= intToColor(cl);
	printf("\n");
return ;
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

 int main(void)
{	

int x,r,sum_ta=0 ; 
	printf("This is a FiFo proc execution !\n");
	printf("Enter num of proc:  "); 
	scanf("%d",&x);
	printf("\n");
	queue q1 ; 
	init_q(&q1) ; 	
	process_settings *proc = malloc(sizeof(process_settings));
	printf("Generating now time for each proc ...\n");
	for ( int i = 1 ; i<=x ; ++i) 
	{
		get_userInput(proc); 
		enqueue(&q1,proc);
		sum_ta +=proc->te ; 
	}
	
	bsort(&q1);
	sleep(2); 
	printf("Total Time excution: %ds \n",sum_ta);  
int t=0,i=1,time_passed=0,time=0; 
	while (q1.tail != NULL) 
	{
		proc = dequeue(&q1); 
		//proc_print(proc); 
		printf("\rExecuting now %s for %ds ...\n",proc->name,proc->te);
		time_passed+=proc->te;
		fflush(stdout); 
		update_bar(sum_ta,time_passed,proc->te,time,proc->color);
		printf(ESC CSI "%d" previousLine,2 );// resetting the curesor for the 2 lines 
		time+=proc->te;
		sleep(proc->te); 
	}	
	printf("\n\nDone !\n"); 
	return 0;
}
