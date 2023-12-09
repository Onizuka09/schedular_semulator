
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../display_manger/display_conf.h" 

#include "../process_config/global_config.h"
#include "../dataStruct/linkedlist.h"
#include "../dataStruct/queue.h"
#include "../process_def.h"
#include "../file_manipulation/csv_file_manip.h"

int main() {

  
     /* n7awel nhotha fel for loop*/
    node *tmp;
    node *Head =NULL;
    queue q1; 
    init_queue(&q1);
    Process p ;
    int color, sum=0 ; 
    int nb_proc=0, nb_proc1=0;
    queue wait_list;
    init_queue(&wait_list);
    Process *c_proc, *w_proc;
   
	int nbr = 0; 
	char *csv = CSV_file_name;
	// Create_CSV_file(csv);
	// fill_csv_file(csv);
	Head = Read_csv_file(csv, &nbr);
	printf("nbr proc: %d\n", nbr);
	tmp = Head;
	while (tmp != NULL) // transfomr a linked list to a queue ; 
	{
		enqueue(&q1,&tmp->proc);
		tmp= tmp->next;
	}
	queue_bsort_2(&q1);

 printTable(&q1,0);




    int c_time = 0, te = 0, wait_time = 0,ta=0;

	int last_proc_ta = q1.tail->proc.ta;
	int total_t = calculate_simulation_time(q1.head);
	printf("Total simulation time %d\n", total_t);
	printf("\nPriority:\n");
	printf("%d \n", is_empty(&wait_list));
    while (q1.head != NULL)
	{
        ta = q1.head->proc.ta;

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
		queue_bsort_priority(&wait_list);

       while (!is_empty(&wait_list))
			w_proc = dequeue(&wait_list);
 
			te = w_proc->te;
			printf("\rexcuting porc %s for %d\n", w_proc->name, te);
			fflush(stdout);
			update_bar(total_t, te, c_time, w_proc->color);

			update_time(total_t, te, c_time, w_proc->color);

			printf(ESC CSI "%d" previousLine, 3);
			sleep(te);
			c_time += te;
            search_for_least_min_te(&q1, &wait_list, c_time);
		    queue_bsort_priority(&wait_list);
			}

    }

        printf("\n\n\n");
		printf("done \n");


    return 0;
}
