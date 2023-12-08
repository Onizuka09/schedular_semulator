//
// Created by amani on 05/12/23.
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
	//free(n);
	return total_t;
}




int main() {

    int qtm , nb_proc=0;
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
            tmp=create_new_node(p);
            insert_at_head(&Head, tmp);
            nb_proc++;
            
        }
    }

printf("nbr proc: %d\n", nb_proc);
linkedlist_bubbleSort(&Head,nb_proc);
printTable_linkedList(Head,0);
printf("linked list loula sorted by ta\n");
printlist(Head);

int curs = 0,c_time=0,wait_time=0;

printf(" curs = %d",curs);
printf("\n");

    node *tmp2;
    node *Head2 =NULL;
    int l2=0;
    bool b = true;
    int total_t = calculate_simulation_time(Head);
    curs = Head->proc.ta;
     c_time = 0 ; 
    // wait list awel proc liked list
    // likend list pas
    while (curs < total_t)
    {
        // printf(" curs = %d",curs);
        // printf("\n");

        while ((Head != NULL) && (b == true))
        {
            if (Head->proc.ta <= curs)
            {
                node *tmp2 = create_new_node(Head->proc);
                insert_at_head(&Head2, tmp2);
                l2++;
                Head = Head->next;
            }
            else{ b=false;}
    }
    if (c_time < Head2->proc.ta)
    {
        wait_time = Head2->proc.ta - c_time;
        printf(clear_line);
        fflush(stdout);
        printf("\rwaiting for %d \n", wait_time);
        update_bar(total_t, wait_time, c_time, E_RESET_C);
        update_time(total_t, wait_time, c_time, E_RESET_C);
        printf(ESC CSI "%d" previousLine, 3);
        sleep(wait_time);
        c_time += wait_time;
        
    }

    linkedlist_bubbleSortpriority(&Head2,l2);
    //printlist(Head2);
    //nexicuty awl process fel waitlist 
    Head2->proc.te--;
    Head2->proc.execution_time=1;
    //printf("process  %s",Head2->proc.name);
    //printf(" is exucuting for 1 unit");

    printf(clear_line);
    fflush(stdout);
	printf("\rexecuting proc %s for %d \n", Head2->proc.name, Head2->proc.execution_time);
	update_bar(total_t, Head2->proc.execution_time, c_time, Head2->proc.color);
    update_time(total_t, Head2->proc.execution_time, c_time, Head2->proc.color);
    sleep(Head2->proc.execution_time);
	printf(ESC CSI "%d" previousLine, 3);

    curs++;
    c_time++;
    b = true;
    if (Head2->proc.te==0){
        //printf("\n process %s" , Head2->proc.name);
        //printf("is terminated");
        Head2=Head2->next;
        l2--;

    }
    
}
printf("\n\n\n");
printf("done !!\n");
}
