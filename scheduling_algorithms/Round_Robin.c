//
// Created by amani on 18/11/23.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



#include "../display_manger/display_conf.h" 

#include "../process_config/global_config.h"
#include "../dataStruct/linkedlist.h"
#include "../dataStruct/queue.h"
#include "../process_def.h" 
void update_bar_amani(int total_time, int time_done) {
	int percentage_done = time_done * 100 / total_time;
	int num_chars = (percentage_done * max_chars) / 100;

	// Choose color based on the progress percentage
	const char *color_code;
	if (percentage_done < 50) {
		color_code = RED_TEXT;
	} else if (percentage_done < 80) {
		color_code = YELLOW_TEXT;
	} else {
		color_code = GREEN_TEXT;
	}

	// Print the colored progress bar
	printf("%s[", color_code);
	for (int i = 0; i < num_chars; ++i) {
		printf("#");
	}
	for (int i = 0; i < max_chars - num_chars; ++i) {
		printf(" ");
	}
	printf("] %d%% done%s\n", percentage_done, RESET_TEXT);
	fflush(stdout);
}
int calculate_simulation_time(node *head)
{
	int total_t = 0;
	node *n;
	Process p;
	n = head;
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

int main() {

	int qtm , nb_proc=0 , tempRot=0 , temAtt =0;
	printf("Quantum value ? ");
	scanf("%d", &qtm);
	 /* n7awel nhotha fel for loop*/
	node *tmp;
	node *Head =NULL;
	Process p ;
	int color; 

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
	while (fgets(buffer, sizeof(buffer), fpt) != NULL) {
		
		// Parse the CSV line
		if (sscanf(buffer, "%19[^,], %d, %d, %d,%d", p.name, &p.te, &p.ta, &p.priority,&color) == 5) {

			// Create a new node and insert it into the linked list
			p.color = intToColor(color);
			tmp = create_new_node(p);
			insert_at_head(&Head, tmp);
			nb_proc++;
			
		}
	}


	 
	printlist(Head);

	 //tri lel linked list
	linkedlist_bubbleSort(&Head,nb_proc);
	printf ("linked list is sorted : ");
	printlist(Head);


// Round-robin scheduling simulation

	int total_t;
	total_t = calculate_simulation_time(Head);
	queue wait_list;
	init_queue(&wait_list);
	printf("total time %d \n",total_t );

	enqueue(&wait_list,&Head->proc);
	int c_time = 0,wait_time=0;  
	int curs = Head->proc.ta;
	printf("curs = %d",curs);
	printf("\n");
	Head = Head->next;
	int te;
	while (!is_empty(&wait_list) || Head != NULL ) {
		if (!is_empty(&wait_list)) {
			Process *p1 = dequeue(&wait_list);
			if (c_time < p1->ta)
			{
				wait_time = p1->ta - c_time;
				printf(clear_line);
				fflush(stdout);
				printf("\rwaiting for %d \n", wait_time);

				update_bar(total_t, wait_time, c_time, reset);
				update_time(total_t, wait_time, c_time, reset);
				sleep(wait_time);
				printf(ESC CSI "%d" previousLine, 3);
				c_time += wait_time;

			}
			te=p1->te;
			if (p1->te >= qtm) {
				p1->execution_time = qtm;
			} else {
				p1->execution_time = p1->te;
			}
			// printf("____________________________________________________________");
			// printf("\n");
			// printf(" at t =  %d : ",curs);
			// update_bar_amani(p1->te,p1->execution_time);
			// printf("Process %s is executing for %d units \n", p1->name,p1->execution_time);
			
			printf(clear_line);
			fflush(stdout);
			printf("\rexecuting proc %s for %d \n", p1->name, p1->execution_time);

			update_bar(total_t, p1->execution_time, c_time, p1->color);
			update_time(total_t, p1->execution_time, c_time, p1->color);
			sleep(p1->execution_time);
			printf(ESC CSI "%d" previousLine, 3);

			p1->te -= p1->execution_time;

			//printf("\n");
			curs =  curs + p1->execution_time;
			c_time += p1->execution_time;

			// printf("\n");

			while (Head != NULL && Head->proc.ta <= curs) {
				enqueue(&wait_list, &Head->proc);
				Head = Head->next;
			}

			if (p1->te > 0) {
				enqueue(&wait_list, p1);
			} else {
				// printf("Process %s is terminated\n", p1->name);
				tempRot = tempRot + (curs-p1->ta);
				temAtt = temAtt + (tempRot-te);
				// printf("%d",temAtt);
				// printf("\n");
				// printf("________________________________________________________");
				// printf("\n");
			}
		}else{
			enqueue(&wait_list,&Head->proc);
			curs = Head->proc.ta;
			Head = Head->next;
		}

	}
	
	printf("\n \n \n ");
	printf("done\n");
	int tempRotMoy = tempRot / nb_proc;
	int temAttMoy = temAtt/nb_proc;
printf("temp de rotation moy = %d \n",tempRotMoy);
printf("temp d'attente moy = %d \n",temAttMoy);
}
