#include "scheculing_algorithm.h"
int nbr = 0;
float MOYTR = 0;
float MOYTA = 0;
int tre = 0, tat = 0;
void SRT_algo(void ) {
	node* tmp;
	node *tete = NULL;
	Process pr;
	queue GUIq;
	init_queue(&GUIq);
	queue metrics_q;
	init_queue(&metrics_q);
	Process *Gproc = malloc(sizeof(Process));
	char *csv = CSV_file_name;
	tete = Read_csv_file(csv, &nbr);
	printf("nbr proc: %d\n", nbr);
	tmp = tete; 
	Process *w_proc = (Process *)malloc(sizeof(Process));
	queue wait_list;
	queue q1;
	init_queue(&wait_list);
	init_queue(&q1);
	tmp = tete;
	while (tmp != NULL) 
	{
		enqueue(&q1,&tmp->proc);
		tmp= tmp->next;
	}
	queue_bsort_1(&q1);
	printTable(&q1, 0);
	int c_time = 0, te = 0, wait_time = 0,ta=0;
	int last_proc_ta = q1.tail->proc.ta;
	int total_t = calculate_simulation_time(q1.head);
	printf("Total simulation time %d\n", total_t);
	printf("\nShortest Remaining Time (SRT) Scheduling:\n");
	printf("%d \n", is_empty(&wait_list));
	while (q1.head != NULL)
	{
		ta = q1.head->proc.ta;
		while (!is_empty(&wait_list) && c_time <ta)
		{
			int diff = ta - c_time; 
			w_proc = dequeue(&wait_list);
			if (diff < w_proc->remaining_time )
			{
				te = diff; 
			}
			else {
				te = w_proc->remaining_time;
			}
			printf(clear_line);
			fflush(stdout);
			printf("\rexcuting porc %s for %d\n", w_proc->name, te);
			fflush(stdout);
			update_bar(total_t, te, c_time, w_proc->color);
			update_time(total_t, te, c_time, w_proc->color);
			printf(ESC CSI "%d" previousLine, 3);
			sleep(te);
			strcpy(Gproc->name, w_proc->name);
			Gproc->ta = c_time;
			Gproc->te = te;
			Gproc->color = w_proc->color;
			enqueue(&GUIq, Gproc);
			c_time += te;
			w_proc->remaining_time -= te;
			if (w_proc->remaining_time != 0)
			{ 
				enqueue(&wait_list, w_proc);
			}
			else 
			{
				w_proc->end = c_time ;
				enqueue(&metrics_q, w_proc);
			}
		}
		if (c_time < q1.head->proc.ta) 
		{
			wait_time = q1.head->proc.ta - c_time;
			printf(clear_line);
			fflush(stdout);
			printf("\rwaiting for %d \n", wait_time);
			update_bar(total_t, wait_time, c_time, E_RESET_C);
			update_time(total_t, wait_time, c_time, E_RESET_C);
			printf(ESC CSI "%d" previousLine, 3);
			strcpy(Gproc->name, "waiting");
			Gproc->ta = c_time;
			Gproc->te = wait_time;
			Gproc->color = E_RESET_C;
			enqueue(&GUIq, Gproc);
			c_time += wait_time;
			sleep(wait_time);
		}
		search_for_least_min_te(&q1, &wait_list, c_time);
		queue_bsort_te(&wait_list);
		w_proc = dequeue(&wait_list);
		if (c_time <= last_proc_ta)
		{
			te = 1;
			w_proc->remaining_time -=te;
			printf(clear_line);
			fflush(stdout);
			printf("\rexcuting porc %s for %d\n",w_proc->name ,te);
			fflush(stdout);
			update_bar(total_t, te, c_time, w_proc->color);
			update_time(total_t,te, c_time, w_proc->color);
			printf(ESC CSI "%d" previousLine, 3);
			strcpy(Gproc->name, w_proc->name);
			Gproc->ta = c_time;
			Gproc->te = te;
			Gproc->color = w_proc->color;
			enqueue(&GUIq, Gproc);
			sleep(te);
			c_time +=te;
			if (w_proc->remaining_time !=0)
			{	
				enqueue(&wait_list, w_proc);
			}
			else 
			{
				w_proc->end = c_time;
				enqueue(&metrics_q, w_proc);
			}
		}
	}
	queue_bsort_te(&wait_list);
	while (!is_empty(&wait_list))
	{ 
		w_proc = dequeue(&wait_list);
		te = w_proc->remaining_time;
		printf(clear_line);
		fflush(stdout);
		printf("\rexcuting porc %s for %d\n", w_proc->name, te);
		fflush(stdout);
		update_bar(total_t, te, c_time, w_proc->color);
		update_time(total_t, te, c_time, w_proc->color);
		printf(ESC CSI "%d" previousLine, 3);
		strcpy(Gproc->name, w_proc->name);
		Gproc->ta = c_time;
		Gproc->te = te;
		Gproc->color = w_proc->color;
		enqueue(&GUIq, Gproc);
		sleep(te);
		c_time += te;
		w_proc->end = c_time;
		enqueue(&metrics_q, w_proc);
	}
	printf("\n\n\n");
	printf("done \n");
	printTable_metrics(&metrics_q, nbr);
	char *title = "SRT (Preamtive) Execution";
	create_widget(&GUIq, title);
	while (GUIq.head != NULL)
	{
		Gproc = dequeue(&GUIq);
	}
	free(w_proc);
	free(Gproc);
	return;
}
