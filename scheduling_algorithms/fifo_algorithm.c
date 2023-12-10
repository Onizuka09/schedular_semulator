#include "scheculing_algorithm.h"

void FIFO_algo(void)
    
{	

	printf("\n");
	queue q1 ;
	init_queue(&q1) ;
	int nb_proc = 0;
	char *csv = CSV_file_name;
	// Create_CSV_file(csv);
	// fill_csv_file(csv);
	node *tmp;
	node *Head = NULL;
	Head = Read_csv_file(csv, &nb_proc);
	  /////////////////////mofifffffffffff
FILE *csvFile = fopen("processes1.csv", "w");

if (csvFile == NULL) {
    fprintf(stderr, "Erreur d'ouverture du fichier CSV.\n");
    exit(EXIT_FAILURE);
}
////////////////mofifffffffffffffff
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
	printf("This is a FiFo proc execution !\n");
	tproc->remaining_time = tproc->te;
	while (q1.head !=NULL)
	{
		tproc = dequeue(&q1);
		if (c_time < tproc->ta ) // wait
			{

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
			/////////////////modifier2
				tproc->tf=c_time;
				printf("%scompleted at %d\n",tproc->name,c_time) ;  
				fprintf(csvFile, "Process %s completed at time %d\n", tproc->name,c_time);
				 /////////////////////////end modifier 2

			fflush(stdout);
			update_bar(total_t,tproc->te,c_time,tproc->color);

			update_time(total_t,tproc->te,c_time,tproc->color);
			
			printf(ESC CSI "%d" previousLine,3);
			c_time+=tproc->te;
			
			


			sleep(tproc->te);
	}

	printf("\n\n\nDone !\n"); 
	fclose(csvFile);
	return ;
}
