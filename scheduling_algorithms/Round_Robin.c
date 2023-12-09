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
#include "../file_manipulation/csv_file_manip.h"

int main() {

	int qtm , nb_proc=0 , tempRot=0 , temAtt =0;
	printf("Quantum value ? ");
	scanf("%d", &qtm);
	 /* n7awel nhotha fel for loop*/

	node *tmp;
	node *Head =NULL;

	//	read csv file 

	char *csv = CSV_file_name;
	Head = Read_csv_file(csv, &nb_proc);
	printf("nbr proc: %d\n", nb_proc);



	// tri lel linked list
	linkedlist_bubbleSort(&Head,nb_proc);
/*  
	printf ("linked list is sorted : ");
	printlist(Head);
*/
printTable_linkedList(Head,0);  // Round-robin scheduling simulation
	printf("Round Robin simulation \n"); 
	int total_t;
	total_t = calculate_simulation_time(Head);
	queue wait_list;
	init_queue(&wait_list);
	printf("Total simulation time %d \n",total_t );

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

				update_bar(total_t, wait_time, c_time, E_RESET_C);
				update_time(total_t, wait_time, c_time, E_RESET_C);
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

			fflush(stdout);
			printf("\rexecuting proc %s for %d \n", p1->name, p1->execution_time);

			update_bar(total_t, p1->execution_time, c_time, p1->color);
			update_time(total_t, p1->execution_time, c_time, p1->color);
			sleep(p1->execution_time);
			printf(ESC CSI "%d" previousLine, 3);

			p1->te -= p1->execution_time;

			curs =  curs + p1->execution_time;
			c_time += p1->execution_time;


			while (Head != NULL && Head->proc.ta <= curs) {
				enqueue(&wait_list, &Head->proc);
				Head = Head->next;
			}

			if (p1->te > 0) {
				enqueue(&wait_list, p1);
			} else {
				tempRot = tempRot + (curs-p1->ta);
				temAtt = temAtt + (tempRot-te);
	
			}
		}else{
			enqueue(&wait_list,&Head->proc);
			curs = Head->proc.ta;
			c_time = Head->proc.ta;
			Head = Head->next;
		}

	}
	
	printf("\n\n\n");
	printf("done\n");
	int tempRotMoy = tempRot / nb_proc;
	int temAttMoy = temAtt/nb_proc;
printf("temp de rotation moy = %d \n",tempRotMoy);
printf("temp d'attente moy = %d \n",temAttMoy);
}
