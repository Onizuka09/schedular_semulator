#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#include "dataStruct/queue.h"
#include "display_manger/display_conf.h" 
#include "process_config/global_config.h"
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
