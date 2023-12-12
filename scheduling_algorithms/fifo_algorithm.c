#include "scheculing_algorithm.h"
void FIFO_algo(void)
{	
	printf("\n");
	queue q1 ;
	queue GUIq;
	queue metrics_q;
	init_queue(&metrics_q);
	init_queue(&q1) ;
	init_queue(&GUIq);
	Process *Gproc = malloc(sizeof(Process));
	int nb_proc = 0;
	char *csv = CSV_file_name;
	node *tmp;
	node *Head = NULL;
	Head = Read_csv_file(csv, &nb_proc);

	tmp = Head;
	while (tmp != NULL) 
	{
		enqueue(&q1, &tmp->proc);
		tmp = tmp->next;
	}
	printf("nbr proc: %d\n", nb_proc);
	Process *tproc = malloc(sizeof(Process));
	queue_bsort(&q1);
	printf("\n"); 
	printTable(&q1,0);
	printf("\n"); 
	int num_total_lines = (nb_proc+3); 
	int c_time = 0, wait_t = 0, total_t = 0,lines=1;
	total_t = calculate_simulation_time(q1.head) ; 
	printf("total time 2: %d \n", total_t);
	printf("This is a FiFo proc execution !\n");
	while (q1.head !=NULL)
	{
		tproc = dequeue(&q1);
		if (c_time < tproc->ta ) 
			{
				wait_t = tproc->ta - c_time ;
				printf(clear_line);
				printf("\rwaiting for %d \n", wait_t);
				fflush(stdout);
				update_bar(total_t, wait_t, c_time, E_RESET_C);
				update_time(total_t, wait_t, c_time, E_RESET_C);
				sleep(wait_t);
				printf(ESC CSI "%d" previousLine, 3);
				strcpy(Gproc->name, "waiting");
				Gproc->ta = c_time;
				Gproc->te = wait_t;
				Gproc->color = E_RESET_C;
				enqueue(&GUIq, Gproc);
				c_time += wait_t;
			}
			printf("\rExecuting now %s for %ds ...\n",tproc->name,tproc->te);
			update_bar(total_t,tproc->te,c_time,tproc->color);
			update_time(total_t,tproc->te,c_time,tproc->color);
			printf(ESC CSI "%d" previousLine,3);
			fflush(stdout);
			strcpy(Gproc->name, tproc->name);
			Gproc->ta = c_time;
			Gproc->te = tproc->te;
			Gproc->color = tproc->color;
			enqueue(&GUIq, Gproc);
			c_time+=tproc->te;
			// printf("Finished executing %s at %d\n", tproc->name, c_time);
			sleep(tproc->te);
			tproc->end = c_time;
			enqueue(&metrics_q, tproc);
			lines ++ ; 
	}
	printf("\n\n\nDone !\n");
	printTable_metrics(&metrics_q, nb_proc);
	char *title = "FiFo Execution";
	create_widget(&GUIq,title);
	while (GUIq.head != NULL)
	{
		Gproc = dequeue(&GUIq);
	}
	free(Gproc);
	return;
}
