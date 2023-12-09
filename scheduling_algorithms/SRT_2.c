#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#include "../display_manger/display_conf.h" 
#include "../process_config/global_config.h"
#include "../dataStruct/linkedlist.h"
#include "../dataStruct/queue.h"
#include "../process_def.h"

node* mintempex;
Process currentProcess;

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
		if (tmp->head->proc.ta == time)
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

int nbr = 0;
float MOYTR = 0;
float MOYTA = 0;
int tre = 0, tat = 0;

int main() {
   
	// scanf("%d", &nbr);
	// struct Process* currentProcess = NULL;
	

	node* tmp;
	node *tete = NULL;
	// node *chead = tete;
	Process pr;
   // Process currentProcess;

	FILE *fpt;
	fpt = fopen("file_manipulation/File.csv", "r");
	if (fpt == NULL)
	{
		fprintf(stderr, "Error opening the file.\n");
		return 1;
	}

	// Read the header line from the CSV file
	char buffer[100];
	fgets(buffer, sizeof(buffer), fpt);

	// Read the remaining lines from the CSV file
	int color=0;
	while (fgets(buffer, sizeof(buffer), fpt) != NULL)
	{

		// Parse the CSV line
		if (sscanf(buffer, "%19[^,], %d, %d, %d,%d", pr.name, &pr.te, &pr.ta, &pr.priority,&color) == 5)
		{
			// Create a new node and insert it into the linked list
			pr.color = intToColor(color);
			tmp = create_new_node(pr);
			insert_at_head(&tete, tmp);
			nbr ++; 
		}
	}
	printf("nbr proc: %d\n", nbr);


	tmp = tete; 
	while (tmp!=NULL) // set up remaining time to be the same as te  
	{
		tmp->proc.remaining_time = tmp->proc.te;
		tmp = tmp->next; 
		/* code */
	}
	

	/////////////////////////////////////////////////////////
	
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
	// display(&q1);
	queue_bsort_1(&q1);
	/*
	printTable(&q1, 0);
	c_proc = dequeue(&q1);

	printf("\n\n");
	search_for_least_min_te(&q1, &wait_list, 8);
	
	// printf("%d", q1.tail->proc.te);
	printTable(&wait_list, 0);
*/
	printTable(&q1, 0);

	int c_time = 0, te = 0, wait_time = 0,ta=0;

	int last_proc_ta = q1.tail->proc.ta;
	int total_t = calculate_simulation_time(q1);
	printf("Total simulation time %d\n", total_t);
	printf("\nShortest Remaining Time (SRT) Scheduling:\n");
	printf("%d \n", is_empty(&wait_list));
	while (q1.head != NULL)
	{
		ta = q1.head->proc.ta;
		while (!is_empty(&wait_list) && c_time <ta)
		{
			// printf("a\n");
			w_proc = dequeue(&wait_list);
			if (ta< w_proc->remaining_time )
			{
				te = w_proc->remaining_time - ta; 
			}
			else {
				te = w_proc->remaining_time;
			}
			// printf("\rexcuting porc %s for %d\n", w_proc->name, te);
			// update_bar(total_time,te,c_time,w_proc->color);
			printf("\rexcuting porc %s for %d\n", w_proc->name, te);
			fflush(stdout);
			update_bar(total_t, te, c_time, w_proc->color);

			update_time(total_t, te, c_time, w_proc->color);
			printf(ESC CSI "%d" previousLine, 3);
			sleep(te);
			c_time += te;
		}

			// c_proc = dequeue(&q1) ;
		if (c_time < q1.head->proc.ta) // check for waiting time
		{
			wait_time = q1.head->proc.ta - c_time;
			printf(clear_line);
			fflush(stdout);
			printf("\rwaiting for %d \n", wait_time);
			
			update_bar(total_t, wait_time, c_time, reset);
			update_time(total_t, wait_time, c_time, reset);
			sleep(wait_time);
			printf(ESC CSI "%d" previousLine, 3);
			c_time += wait_time;
		}
		search_for_least_min_te(&q1, &wait_list, c_time);
		// if (!is_empty(&wait_list))
		queue_bsort_te(&wait_list);
		// printTable(&wait_list, 0);
		w_proc = dequeue(&wait_list);
		if (c_time <= last_proc_ta)
		{
			te = 1;
			w_proc->remaining_time -=te;
			printf("\rexcuting porc %s for %d\n",w_proc->name ,te);
			fflush(stdout);
			update_bar(total_t, te, c_time, w_proc->color);

			update_time(total_t,te, c_time, w_proc->color);

			printf(ESC CSI "%d" previousLine, 3);
			// update_bar(total_time, te, c_time, w_proc->color);
			sleep(te);
			c_time +=te;
			if (w_proc->remaining_time !=0)
			{	// printf("")
				enqueue(&wait_list, w_proc);
				
			// printf("%d ",c_time);
			}
		}
		}
		queue_bsort_te(&wait_list);
		// printf("a");
		while (!is_empty(&wait_list))
		{ // fifo
			// te=0;
			w_proc = dequeue(&wait_list);

			te = w_proc->remaining_time;
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

		// pr.remaining_time= pr.te;
		// chead->proc.remaining_time = 1;
		/*
			while (completed < nbr)
			{
				while (chead != NULL && chead->proc.ta == currentTime &&  chead->proc.remaining_time>0 )
				{
					enqueue(&file,&chead->proc);
					chead =chead->next;
				}
				while (!is_empty(&file))
				{
					Process *mintempex = dequeue(&file);// on fixé que le head de que est le min temps d'escution chaque fois
					printf("mintex= %d\n",mintempex->remaining_time);
					printf("pr= %d\n",pr.remaining_time);
					if (pr.remaining_time > mintempex->remaining_time&& mintempex->remaining_time > 0 && mintempex->ta == currentTime)
					{//si temps a executé du process actuelle superieur a min on inverse et on boucle jusqu'a le file est terminé
						pr=*mintempex;
						printf("Process %s avec le min de temps execution\n", pr.name);
						printf("nom du prcess avec min tex %s\n",pr.name);
					}
				}
				printf("p=%s\n ",pr.name);
				pr.execution_time++;
				printf("execution_time= %d\n",pr.te);
				pr.remaining_time--;
				printf("remaining_time= %d\n",pr.remaining_time);
				currentTime++;
				printf("currenttime= %d\n",currentTime);
				printf("____________________________________________________________");
				printf("\n");
				// printf(" at t =  %d : ",chead);
				update_bar_amani_copie(pr.te,pr.te);
				printf("Process %s is executing for %d units \n", pr.name,pr.te);
				if (mintempex->proc.remaining_time == 0)
				{
					tre= tre+currentTime-pr.ta;
					tat =tat +tre-pr.te;
					completed++;
					printf("completed%d",completed);
					printf("Process %s is terminated\n", pr.name);
					printf("\n");
					printf("________________________________________________________");
					printf("\n");
				}
			}
			MOYTR =tre/nbr;
			MOYTA =tat /nbr;
			printf("MOYTR%f",MOYTR);
			*/
		return 0;
}







//printf("le moyenne temps de rotat ion totale = %f\n", MOYTR);
//printf("le moyenne temps d'attente totale = %f\n", MOYTA);

   
   /*while (tete != NULL) {
		node* temp =tete;
	   tete = tete->next;
		free(temp);*/
	//}

  /*while (!is_empty(&file)) {
	dequeue(&file);
	}*/
	