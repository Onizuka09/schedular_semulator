#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "dataStruct/queue.h"
#include "display_manger/display_conf.h" 
#include "process_config/global_config.h"
void printTbale(process_settings *proc,int num_proc) { 
// name , Ta, Te , priorite, 
int col=4  , ligne=num_proc; 
//for (int i=0 ; i<col; ++i)
//{
	printf("%s\t",proc->name);
	printf("%d\t",proc->ta);
	printf("%d\t",proc->te);
	printf("%d\t",proc->priority); 
	//printf("%d\t
//}	
}

int main(void)

{
    int x, r, sum_ta = 0;
    queue q1;
    init_q(&q1);

    // Allocate memory for process_settings structures
    process_settings *proc = malloc(sizeof(process_settings));
    process_settings *proc1 = malloc(sizeof(process_settings));
    process_settings *proc2 = malloc(sizeof(process_settings));

//	gantt(NULL) ; 
    printf("\nGenerating now time for each proc ...\n");
    // proc 1
    strcpy(proc->name, "p1");
    proc->ta = 0;
    proc->te = 1;
    proc->color = green;
    proc->priority = 1;
    enqueue(&q1, proc);
    sum_ta += proc->te;
    strcpy(proc2->name, "p2");
    proc->ta = 2;
    proc->te = 5;
    proc->color = green;
    proc->priority = 2;
    enqueue(&q1, proc2);
    sum_ta += proc2->te;
    strcpy(proc->name, "p3");
    proc->ta = 1;
    proc->te = 4;
    proc->color = green;
    proc->priority = 1;
    enqueue(&q1, proc);
    sum_ta += proc->te;



    // proc 2 (similar setup)
//    bsort(&q1);
    // sleep(2);
    printf("Total Time execution: %ds \n", sum_ta);

    int time = 0;
    printf("P_name\tTa\tTe\tPriority\n");		
    while (q1.head!= NULL)
    {
		process_settings *proc = dequeue(&q1);
		//printf("Proc: %s has arrived executing it now for: %d \n", proc->name, proc->te);
		printTbale(proc,3);
		printf("\n");
 
    }

    // Free allocated memory
    free(proc);
    free(proc1);
    free(proc2);

    printf("\n\nDone !\n");
    return 0;
}

