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
        if (sscanf(buffer, "%19[^,], %d, %d, %d", p.name, &p.te, &p.ta, &p.priority) == 4) {
            // Create a new node and insert it into the linked list
            tmp=create_new_node(p);
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


    queue file;
    init_queue(&file);

    
    enqueue(&file,&Head->proc);
    int curs = Head->proc.ta;
    printf("curs = %d",curs);
    printf("\n");
    Head = Head->next;
    int te;

    while (!is_empty(&file) || Head != NULL ) {
        if (!is_empty(&file)) {

            Process *p1 = dequeue(&file);
            te=p1->te;
            if (p1->te >= qtm) {
                p1->execution_time = qtm;
            } else {
                p1->execution_time = p1->te;
            }
            printf("____________________________________________________________");
            printf("\n");
            printf(" at t =  %d : ",curs);
            update_bar_amani(p1->te,p1->execution_time);
            printf("Process %s is executing for %d units \n", p1->name,p1->execution_time);
            
            

            p1->te -= p1->execution_time;

            //printf("\n");
            curs =  curs + p1->execution_time;

            printf("\n");

            while (Head != NULL && Head->proc.ta <= curs) {
                enqueue(&file, &Head->proc);
                Head = Head->next;
            }

            if (p1->te > 0) {
                enqueue(&file, p1);
            } else {
                printf("Process %s is terminated\n", p1->name);
                tempRot = tempRot + (curs-p1->ta);
                temAtt = temAtt + (tempRot-te);
                printf("%d",temAtt);
                printf("\n");
                printf("________________________________________________________");
                printf("\n");
            }
        }else{
            enqueue(&file,&Head->proc);
            curs = Head->proc.ta;
            Head = Head->next;
        }

    }
    int tempRotMoy = tempRot/nb_proc;
    int temAttMoy = temAtt/nb_proc;
printf("temp de rotation moy = %d ",tempRotMoy);
printf("temp d'attente moy = %d ",temAttMoy);
}
