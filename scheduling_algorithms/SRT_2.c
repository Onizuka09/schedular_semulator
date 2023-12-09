#include "scheculing_algorithm.h"
int nbr = 0;
float MOYTR = 0;
float MOYTA = 0;
int tre = 0, tat = 0;

<<<<<<< HEAD
int main() {
   
	
=======
void SRT_algo(void ) {

>>>>>>> main

	node* tmp;
	node *tete = NULL;
	
	Process pr;

	char *csv = CSV_file_name;
	// Create_CSV_file(csv);
	// fill_csv_file(csv);
	tete = Read_csv_file(csv, &nbr);
	printf("nbr proc: %d\n", nbr);
	tmp = tete; 
	while (tmp!=NULL) // set up remaining time to be the same as te  
	{
		tmp->proc.remaining_time = tmp->proc.te;
		tmp = tmp->next; 
	}
	

	
	Process *c_proc, *w_proc;
	queue wait_list;
	queue q1;
	init_queue(&wait_list);
	init_queue(&q1);
	tmp = tete;
	while (tmp != NULL) // transfomr a linked list to a queue ; 
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
			c_time += te;
			w_proc->remaining_time -= te;
			if (w_proc->remaining_time != 0)
			{ 
				enqueue(&wait_list, w_proc);
			}
		}

		if (c_time < q1.head->proc.ta) // check for waiting time
		{
			wait_time = q1.head->proc.ta - c_time;
			printf(clear_line);
			fflush(stdout);
			printf("\rwaiting for %d \n", wait_time);

			update_bar(total_t, wait_time, c_time, E_RESET_C);
			update_time(total_t, wait_time, c_time, E_RESET_C);
			sleep(wait_time);
			printf(ESC CSI "%d" previousLine, 3);
			c_time += wait_time;
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
			sleep(te);
			c_time +=te;
			if (w_proc->remaining_time !=0)
			{	
				enqueue(&wait_list, w_proc);
				
			}
		}
	}
	queue_bsort_te(&wait_list);
		
	while (!is_empty(&wait_list))
	{ // fifo
		
		w_proc = dequeue(&wait_list);
		te = w_proc->remaining_time;
		printf(clear_line);
		fflush(stdout);
		printf("\rexcuting porc %s for %d\n", w_proc->name, te);
		fflush(stdout);
		update_bar(total_t, te, c_time, w_proc->color);
		update_time(total_t, te, c_time, w_proc->color);
		printf(ESC CSI "%d" previousLine, 3);
		sleep(te);
		c_time += te;
	}
	printf("\n\n\n");
	printf("done \n");
/*
			MOYTR =tre/nbr;
			MOYTA =tat /nbr;
			printf("MOYTR%f",MOYTR);
			*/

		return ;
}






	