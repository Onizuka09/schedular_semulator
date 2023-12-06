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

void update_bar_amani_copie(int total_time, int time_done) {
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
	int nbr=0;
	float MOYTR=0;
	float MOYTA=0;
	int tre=0,tat =0;

int main() {
   
	printf("How many processes do you need? ");
	scanf("%d", &nbr);
	// struct Process* currentProcess = NULL;
	int currentTime = 0;//temps actuel en s
	int completed = 0;//nombre de processur terminé

	node* tmp;
	node *tete = NULL;
	node *chead = tete;
	Process pr;
   // Process currentProcess;
	
   

	for (int i = 0; i < nbr; i++) {
		printf("Enter the name of process %d: ", i + 1);
		scanf("%s", pr.name);
		printf("Enter the arrival date of process %d: ", i + 1);
		scanf("%d", &pr.ta);
		printf("Enter the CPU units of process %d: ", i + 1);
		scanf("%d", &pr.te);
		tmp = create_new_node(pr);
		insert_at_head(&tete, tmp);
	}

	printf("Unsorted linked list: ");
	printlist(tete);
	linkedlist_bubbleSort(&tete, nbr);
	printf("Sorted linked list: ");
	printlist(tete);
	printf("Shortest Remaining Time (SRT) Scheduling:\n");

/////////////////////////////////////////////////////////

	queue file;
	init_queue(&file);//file d'attente lel process fi instant pour prendre le min %tex
	pr.remaining_time= pr.te;
	
	//enqueue(&file,&tete->proc);
/* int curs =tete->proc.ta;
	printf("curs = %d",curs);
	printf("\n");
   tete = tete->next;

	pr.remaining_time= pr.te;
   */
	while (completed < nbr)
	{
		while (chead != NULL && chead->proc.ta == currentTime &&  chead->proc.remaining_time>0 ) {
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
return MOYTA;
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
	