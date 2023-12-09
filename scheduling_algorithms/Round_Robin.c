//
// Created by amani on 18/11/23.
//

#include "scheculing_algorithm.h"

void Round_Robin_algo (void ) {

	int qtm , nb_proc=0 , tempRot=0 , temAtt =0;
	printf("Quantum value ? ");
	scanf("%d", &qtm);
	 /* n7awel nhotha fel for loop*/

	node *tmp;
	node *Head =NULL;

	//	read csv file 

	char *csv = CSV_file_name;
	Head = Read_csv_file(csv, &nb_proc);

	//mod1
	node* CHead=Head;
	printf("nbr proc: %d\n", nb_proc);



	// tri lel linked list
	linkedlist_bubbleSort(&CHead,nb_proc);

printTable_linkedList(CHead,0);  // Round-robin scheduling simulation
	printf("Round Robin simulation \n"); 
	int total_t;
	total_t = calculate_simulation_time(CHead);
	queue wait_list;
	init_queue(&wait_list);
	printf("Total simulation time %d \n",total_t );

    //upd
	enqueue(&wait_list,&CHead->proc);
	int c_time = 0,wait_time=0;  
	//upd
	int curs = CHead->proc.ta;
	printf("curs = %d",curs);
	printf("\n");
	//upd
	CHead = CHead->next;
	int te;
	//updt
	while (!is_empty(&wait_list) || CHead != NULL ) {
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
			if (p1->remaining_time >= qtm) {
				p1->execution_time = qtm;
			} else {
				p1->execution_time = p1->remaining_time;
			}

			fflush(stdout);
			printf("\rexecuting proc %s for %d \n", p1->name, p1->execution_time);

			update_bar(total_t, p1->execution_time, c_time, p1->color);
			update_time(total_t, p1->execution_time, c_time, p1->color);
			sleep(p1->execution_time);
			printf(ESC CSI "%d" previousLine, 3);

			p1->remaining_time -= p1->execution_time;

			curs =  curs + p1->execution_time;
			c_time += p1->execution_time;

//updt
			while (CHead != NULL && CHead->proc.ta <= curs) {
				enqueue(&wait_list, &CHead->proc);
				//UPT
				CHead = CHead->next;
			}

			if (p1->remaining_time > 0) {
				enqueue(&wait_list, p1);
			} else {
				tempRot = tempRot + (curs-p1->ta);
				temAtt = temAtt + (tempRot-p1->te);
				////////////modifier 1

			 p1->tf = curs;
                printf("Process %s completed at time %d\n", p1->name, p1->tf);
				////////////end modifier
	
			}
		}else{
			//UPDT
			enqueue(&wait_list,&CHead->proc);
			curs = CHead->proc.ta;
			c_time = CHead->proc.ta;
			CHead = CHead->next;
		}
		


	}
	
	printf("\n\n\n");
	printf("done\n");
	int tempRotMoy = tempRot / nb_proc;
	int temAttMoy = temAtt/nb_proc;
// printf("temp de rotation moy = %d \n",tempRotMoy);
// printf("temp d'attente moy = %d \n",temAttMoy);
printTable_linkedList(Head,0);
}
