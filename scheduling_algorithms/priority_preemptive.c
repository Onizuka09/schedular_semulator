
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../display_manger/display_conf.h" 

#include "../process_config/global_config.h"
#include "../dataStruct/linkedlist.h"
#include "../dataStruct/queue.h"
#include "../process_def.h" 


int calculate_simulation_time(queue q)
{
	int total_t = 0;
	node *n; 
	Process p;
	n = q.head; 
	while (n != NULL)
	{
		p = n->proc;
		if (total_t < p.ta)
		{
			total_t = p.ta;
		}
		total_t += p.te;
		n = n->next;
	}
	free(n);
	return total_t;
}

void search_for_least_min_te(queue* q,queue* wait_list,int time) 
{	Process *p ;
	queue *tmp = (queue *)malloc(sizeof(queue));
	if (tmp == NULL)
	{
		// Handle the case where memory allocation fails
		// (e.g., print an error message and exit the program)
		fprintf(stderr, "Failed to allocate memory for queue.\n");
		exit(EXIT_FAILURE);
	}
	init_queue(tmp);
	tmp->head = q->head;
	while (tmp->head != NULL)
	{
		if (tmp->head->proc.ta <= time)
		{
			p = dequeue(tmp);
			q->head = tmp->head;
			// printTable_view(p,0);
			enqueue(wait_list, p);

		}
		else {
			tmp->head = tmp->head->next;
		}
	}
	free(tmp);
	return;
}

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
    Process *c_proc, *w_proc , *w_proc_copie;
    // Open the CSV file for reading
    FILE *fpt;
    fpt = fopen("file_manipulation/File.csv", "r");
    if (fpt == NULL) {
        fprintf(stderr, "Error opening the file.\n");
        return 1;
    }

    

// Read the header line from the CSV file
    char buffer[100];
    fgets(buffer, sizeof(buffer), fpt);

    // Read the remaining lines from the CSV file
    // int color; 
    while (fgets(buffer, sizeof(buffer), fpt) != NULL) {
        
        // Parse the CSV line
        if (sscanf(buffer, "%19[^,], %d, %d, %d,%d", p.name, &p.te, &p.ta, &p.priority,&color) == 5) {
            // Create a new node and insert it into the linked list
            p.color = intToColor(color);
            tmp=create_new_node(p);
            
            insert_at_head(&Head, tmp);
            nb_proc++;
            sum+= sum+p.te;
            
        }
    }
	while (tmp != NULL) // transfomr a linked list to a queue ; 
	{
		enqueue(&q1,&tmp->proc);
		tmp= tmp->next;
	}
	// display(&q1);
	queue_bsort_2(&q1);
    // printlist(Head);

     //tri lel linked list
    // linkedlist_bubbleSort(&Head,nb_proc);
    printTable(&q1,0);
    // printf ("linked list is sorted : ");
    // printlist(Head);



  // priority non scheduling simulation

    // queue fileExecute;
    // init_queue(&fileExecute);
    // node *tmp1;
    // node *Head1 = NULL;

    // enqueue(&file, &Head->proc);
    // int curs = Head->proc.ta;
    // printf("curs = %d", curs);
    // printf("\n");
    int c_time = 0, te = 0, wait_time = 0,ta=0;

	int last_proc_ta = q1.tail->proc.ta;
	int total_t = calculate_simulation_time(q1);
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
			
			 update_bar(total_t, wait_time, c_time, reset);
			update_time(total_t, wait_time, c_time, reset);
			/* sleep(wait_time); */
			printf(ESC CSI "%d" previousLine, 3);
			c_time += wait_time;
		}
        search_for_least_min_te(&q1, &wait_list, c_time);
		// if (!is_empty(&wait_list))
		queue_bsort_priority(&wait_list);
        // printf("\n")

       // printTable(&wait_list,0);
        //  printf("\n");
       while (!is_empty(&wait_list))
		{ // fifo
			// te=0;
			w_proc = dequeue(&wait_list);
 
			te = w_proc->te;
			printf("\rexcuting porc %s : ", w_proc->name);
			fflush(stdout);
			update_bar(total_t, te, c_time, w_proc->color);
			update_time(total_t, te, c_time, w_proc->color);

			printf(ESC CSI "%d" previousLine, 3);
			
			c_time += 1;
            search_for_least_min_te(&q1, &wait_list, c_time);
		    queue_bsort_priority(&wait_list);
            if ( wait_list.head->proc.priority > w_proc->priority){
                w_proc_copie=w_proc;
                te=  w_proc->te;
                w_proc_copie->te = te - c_time - 1;
                /* w_proc = dequeue(&wait_list);  */
                enqueue(&wait_list,w_proc_copie);
                queue_bsort_priority(&wait_list);

            }
            

			}

    }

        printf("\n\n\n");
		printf("done \n");
/*
    while (!is_empty(&file) || Head != NULL) {
        if (!is_empty(&file)) { 
            while (file.head->proc.ta <= curs) {
                printf(".......");
                Process *p1 = dequeue(&file);
                printf(".........");
                tmp1 = create_new_node(*p1);
                insert_at_head(&Head1, tmp1);
                nb_proc1++;
                linkedlist_bubbleSortpriority(&Head1, nb_proc1);

                printf("linked list is sorted by priority: ");
                printlist(Head1);
              //  Head1 = Head1->next; 
                file.head= file.head->next;
                update_bar_amani(sum, p1->te);
                printf("Process %s is executing for %d units \n", p1->name, p1->te);
                free(p1);
            }
            curs += Head1->proc.te;
        }

        // Assurez-vous que la file se vide correctement
        if (Head != NULL) {
            Head = Head->next;
        }
    }

*/

    return 0;
}
