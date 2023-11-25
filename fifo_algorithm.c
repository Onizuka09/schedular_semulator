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
	queue q1,wait_list ;

	init_q(&q1) ; 	
	init_q(&wait_list); 
	process_settings *proc = malloc(sizeof(process_settings));
    process_settings *proc2 = malloc(sizeof(process_settings));
    process_settings *proc3 = malloc(sizeof(process_settings));

    printf("\nGenerating now time for each proc ...\n");
    // proc 1
    strcpy(proc->name, "p1");
    proc->ta = 3;
    proc->te = 2;//1
    proc->color = green;
    proc->priority = 1;
    enqueue(&q1, proc);
    sum_ta += proc->te;

    strcpy(proc2->name, "p2");
    proc2->ta = 5;
    proc2->te = 2;//5
    proc2->color = red;
    proc2->priority = 2;
    enqueue(&q1, proc2);
    sum_ta += proc2->te;

    strcpy(proc3->name, "p3");
    proc3->ta = 6;
    proc3->te = 4;
    proc3->color = yellow;
    proc3->priority = 1;
    enqueue(&q1, proc3);
    sum_ta += proc3->te;
	process_settings *tproc = malloc(sizeof(process_settings));
/* 	printf("Generating now time for each proc ...\n");
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

//while(
	int c_time=0,wait_t=0; 
while (q1.head !=NULL) 
{
	tproc = dequeue(&q1); 
    if (c_time < tproc->ta-1) // wait 
	{	wait_t = tproc->ta- c_time -1 ; 
		printf("\r waiting for %d \n",wait_t); 
		fflush(stdout); 
		update_bar(sum_ta,wait_t,c_time,reset);
		update_time(sum_ta,wait_t,c_time,reset);
		sleep(wait_t) ;	printf(ESC CSI "%d" previousLine,2 );
		c_time += wait_t ; 
	}
		printf("\rExecuting now %s for %ds ...\n",proc->name,proc->te);
		fflush(stdout); 
		update_bar(sum_ta,tproc->te,c_time,tproc->color);
		
		update_time(sum_ta,tproc->te,c_time,tproc->color);

		printf(ESC CSI "%d" previousLine,2 );
		c_time+=tproc->te;
		sleep(tproc->te); 

}
/*  while (q1.head != NULL) 
	{
		tproc = dequeue(&q1); 
		//proc_print(proc); 
		printf("\rExecuting now %s for %ds ...\n",proc->name,proc->te);
		fflush(stdout); 
		update_bar(sum_ta,tproc->te,c_time,tproc->color);
		
		update_time(sum_ta,tproc->te,c_time,tproc->color);

		printf(ESC CSI "%d" previousLine,2 );
		c_time+=tproc->te;
		sleep(tproc->te); 
	}*/
	printf("\n\n\nDone !\n"); 
	return 0;
}
