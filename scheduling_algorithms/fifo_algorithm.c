#include <stdio.h>		
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#include "../dataStruct/queue.h"
#include "../display_manger/display_conf.h" 
#include "../process_config/global_config.h"
#include "../process_def.h"
#include "../file_manipulation/csv_file_manip.h"

// int  calculate_simulation_time(queue q)
// {
// int total_t=0; 
// Process *p; 
// 	while(q.head!=NULL)
// 	{
// 		p = q.head; 
// 		if (total_t < p->ta)
// 		{
// 			total_t = p->ta; 
// 		}
// 		total_t += p->te;
// 		q.head = q.head->next;
// 	}
// 	// free(p);
// 	return total_t;
// } 
int main(void)
    
{	

	printf("\n");
	queue q1 ;
	init_queue(&q1) ;

	// Process *pr = malloc(sizeof(Process));
	// int nbr_proc;
	// FILE *fpt;
	// fpt = fopen("file_manipulation/File.csv", "r");
	// if (fpt == NULL)
	// {
	// 	fprintf(stderr, "Error opening the file.\n");
	// 	return 1;
	// }
	// // Read the header line from the CSV file
	// char buffer[100];
	// fgets(buffer, sizeof(buffer), fpt);
	// // Read the remaining lines from the CSV file
	// int color = 0;
	// while (fgets(buffer, sizeof(buffer), fpt) != NULL)
	// {
	// 	// Parse the CSV line
	// 	if (sscanf(buffer, "%19[^,], %d, %d, %d,%d", pr->name, &pr->te, &pr->ta, &pr->priority, &color) == 5)
	// 	{
	// 		// Create a new node and insert it into the linked list
	// 		pr->color = intToColor(color);
	// 		enqueue(&q1, pr);
	// 		nbr_proc++;
	// 	}
	// }
	int nb_proc = 0;
	char *csv = CSV_file_name;
	// Create_CSV_file(csv);
	// fill_csv_file(csv);
	node *tmp;
	node *Head = NULL;
	Head = Read_csv_file(csv, &nb_proc);
	// printf("nbr proc: %d\n", nb_proc);
	tmp = Head;
	while (tmp != NULL) // transfomr a linked list to a queue ;
	{
		enqueue(&q1, &tmp->proc);
		tmp = tmp->next;
	}
	printf("nbr proc: %d\n", nb_proc);
	Process *tproc = malloc(sizeof(Process));
	queue_bsort(&q1);
	// bsort;
//	sleep(2); 
	printf("\n"); 
	printTable(&q1,0);
	printf("\n"); 
	int c_time = 0, wait_t = 0, total_t = 0;
	total_t = calculate_simulation_time(q1.head) ; 
	printf("tottal time 2: %d \n", total_t);
	// int max_ch = round((float)(50/total_t))+50;
	printf("This is a FiFo proc execution !\n");

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
				update_bar(total_t, wait_t, c_time, E_RESET_C);
				update_time(total_t, wait_t, c_time, E_RESET_C);
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

	printf("\n\n\nDone !\n"); 
	return 0;
}
