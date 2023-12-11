#include "scheculing_algorithm.h"
void Round_Robin_algo (void ) {
	int qtm , nb_proc=0 , tempRot=0 , temAtt =0;
	printf("Quantum value ? ");
	scanf("%d", &qtm);
	queue GUIq;
	init_queue(&GUIq);
	Process *Gproc = malloc(sizeof(Process));
	node *tmp;
	node *Head =NULL;
	char *csv = CSV_file_name;
	Head = Read_csv_file(csv, &nb_proc);
	node* CHead=Head;
	printf("nbr proc: %d\n", nb_proc);
	linkedlist_bubbleSort(&CHead,nb_proc);
printTable_linkedList(CHead,0);  
	printf("Round Robin simulation \n"); 
	int total_t;
	total_t = calculate_simulation_time(CHead);
	queue wait_list;
	init_queue(&wait_list);
	printf("Total simulation time %d \n",total_t );
	enqueue(&wait_list,&CHead->proc);
	int c_time = 0,wait_time=0;  
	int curs = CHead->proc.ta;
	printf("curs = %d",curs);
	printf("\n");
	CHead = CHead->next;
	int te;
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
				strcpy(Gproc->name, "waiting");
				Gproc->ta = c_time;
				Gproc->te = wait_time;
				Gproc->color = E_RESET_C;
				enqueue(&GUIq, Gproc);
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
			strcpy(Gproc->name, p1->name);
			Gproc->ta = c_time;
			Gproc->te = p1->execution_time;
			Gproc->color = p1->color;
			enqueue(&GUIq, Gproc);
			p1->remaining_time -= p1->execution_time;
			curs =  curs + p1->execution_time;
			c_time += p1->execution_time;
			while (CHead != NULL && CHead->proc.ta <= curs) {
				enqueue(&wait_list, &CHead->proc);
				CHead = CHead->next;
			}
			if (p1->remaining_time > 0) {
				enqueue(&wait_list, p1);
			} else {
				tempRot = tempRot + (curs-p1->ta);
				temAtt = temAtt + (tempRot-p1->te);
			}
		}else{
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
	char *title = "Round-Robin Execution";
	create_widget(&GUIq,title);
	while (GUIq.head != NULL)
	{
		Gproc = dequeue(&GUIq);
	}
	free(Gproc);
}
