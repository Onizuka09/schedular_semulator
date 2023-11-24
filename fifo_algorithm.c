#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#include "dataStruct/queue.h"
#include "display_manger/display_conf.h" 
#include "process_config/global_config.h"
#include "process_def.h" 
 int main(void)
{	

int x=3,r,sum_ta=0 ; 
	printf("This is a FiFo proc execution !\n");
	printf("Enter num of proc:  "); 
//	scanf("%d",&x);
	printf("\n");
	queue q1 ; 
	init_q(&q1) ; 	
	process_settings *proc = malloc(sizeof(process_settings));
    process_settings *proc2 = malloc(sizeof(process_settings));
    process_settings *proc3 = malloc(sizeof(process_settings));

    printf("\nGenerating now time for each proc ...\n");
    // proc 1
    strcpy(proc->name, "p1");
    proc->ta = 0;
    proc->te = 3;//1
    proc->color = green;
    proc->priority = 1;
    enqueue(&q1, proc);
    sum_ta += proc->te;

    strcpy(proc2->name, "p2");
    proc2->ta = 2;
    proc2->te = 3;//5
    proc2->color = red;
    proc2->priority = 2;
    enqueue(&q1, proc2);
    sum_ta += proc2->te;

    strcpy(proc3->name, "p3");
    proc3->ta = 1;
    proc3->te = 4;
    proc3->color = yellow;
    proc3->priority = 1;
    enqueue(&q1, proc3);
    sum_ta += proc3->te;
/*	process_settings *proc = malloc(sizeof(process_settings));
	printf("Generating now time for each proc ...\n");
	for ( int i = 1 ; i<=x ; ++i) 
	{
		get_userInput(proc); 
		enqueue(&q1,proc);
		sum_ta +=proc->te ; 
	}
	*/
	bsort(&q1);
//	sleep(2); 
	printf("\n"); 
printTable(&q1,3);
printf("\n"); 
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
		
		update_time(sum_ta,time_passed,proc->te,time,proc->color);

		printf(ESC CSI "%d" previousLine,2 );// resetting the curesor for the 2 lines 
		time+=proc->te;
		sleep(proc->te); 
	}
/*
while ( q1.head != NULL ) 
{ 
	if (q1.head->proc.ta == time ) 
		printf ("Proc: %s has arrived exuting it now for: %d \n",q1.head->proc.ta); 
	proc = dequeue(&q1);

}*/
	printf("\n\n\nDone !\n"); 
	return 0;
}
