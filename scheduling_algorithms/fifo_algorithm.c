#include <stdio.h>		
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#include "../dataStruct/queue.h"
#include "../display_manger/display_conf.h" 
#include "../process_config/global_config.h"
#include "../process_def.h" 

int  calculate_simulation_time(queue q)
{
int total_t=0; 
Process *p; 
	while(q.head!=NULL)
	{
		p = q.head; 
		if (total_t < p->ta)
		{
			total_t = p->ta; 
		}
		total_t += p->te;
		q.head = q.head->next;
	}
	// free(p);
	return total_t;
} 
 int main(void)
    
{	

int num_proc=4,r,sum_ta=0 ; 
	printf("This is a FiFo proc execution !\n");
	printf("Enter num of proc:  "); 
//	scanf("%d",&x);
	printf("\n");
	queue q1,wait_list ;

	init_queue(&q1) ; 	
	init_queue(&wait_list); 
	Process *proc = malloc(sizeof(Process));
    Process *proc2 = malloc(sizeof(Process));
    Process *proc3 = malloc(sizeof(Process));
	Process *proc4 = malloc(sizeof(Process));
	printf("\nGenerating now time for each proc ...\n");
    // proc 1
    strcpy(proc->name, "p1");
    proc->ta = 0; //3
    proc->te = 3;//2
    proc->color = green;
    proc->priority = 1;
    enqueue(&q1, proc);
    sum_ta += proc->te;

    strcpy(proc2->name, "p2");
    proc2->ta = 5; //5
    proc2->te = 2;//2
    proc2->color = red;
    proc2->priority = 2;
    enqueue(&q1, proc2);
    sum_ta += proc2->te;

    strcpy(proc3->name, "p3");
    proc3->ta = 9;// 9 //2
    proc3->te = 4; //4
    proc3->color = yellow;
    proc3->priority = 1;
    enqueue(&q1, proc3);
    sum_ta += proc3->te;

	strcpy(proc4->name, "p4");
	proc4->te = 4; // 4
	proc4->ta = 3; // 9 //2
	proc4->color = yellow;
	proc4->priority = 1;
	enqueue(&q1, proc4);
	sum_ta += proc4->te;

	Process *tproc = malloc(sizeof(Process));
/* 	printf("Generating now time for each proc ...\n");
	for ( int i = 1 ; i<=x ; ++i) 
	{
		get_userInput(proc); 
		enqueue(&q1,proc);
		sum_ta +=proc->te ; 
	}
	*/
	queue_bsort(&q1);
	// bsort;
//	sleep(2); 
	printf("\n"); 
	
printTable(&q1,num_proc);
printf("\n"); 
	printf("Total Te excution: %ds \n",sum_ta);

	int c_time = 0, wait_t = 0, total_t = 0, total_wait;
	total_t = q1.tail->proc.ta + q1.tail->proc.te - 1;
	printf("tottal time 1: %d \n",total_t );
	total_t = calculate_simulation_time(q1) ; 
		printf("tottal time 2: %d \n", total_t);
	// int max_ch = round((float)(50/total_t))+50;

	total_wait = total_t - sum_ta;
	
	while (q1.head !=NULL)
	{
		tproc = dequeue(&q1);
	    // if (c_time <= tproc->ta-1) // wait
		if (c_time < tproc->ta ) // wait
			{
				// if ()

				// wait_t = tproc->ta- c_time -1 ;
				wait_t = tproc->ta - c_time ;
				printf(clear_line);
				printf("\rwaiting for %d \n", wait_t);
				fflush(stdout);
				update_bar(total_t, wait_t, c_time, reset);
				update_time(total_t, wait_t, c_time, reset);
				sleep(wait_t);
				printf(ESC CSI "%d" previousLine, 3);
				c_time += wait_t;

		}
			printf("\rExecuting now %s for %ds ...\n",tproc->name,tproc->te);
			fflush(stdout);
			update_bar(total_t,tproc->te,c_time,tproc->color);

			update_time(total_t,tproc->te,c_time,tproc->color);

			printf(ESC CSI "%d" previousLine,3);
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
