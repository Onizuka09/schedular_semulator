#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#include "../display_manger/display_conf.h" 
#include "../process_config/global_config.h"
#include "../dataStruct/linkedlist.h"
#include "../dataStruct/queue.h"
#include "../process_def.h" 




int main() {
    int nbr;
    printf("How many processes do you need? ");
    scanf("%d", &nbr);
    // struct Process* currentProcess = NULL;
    int currentTime = 0;
    int completed = 0;

    node* tmp;
    node *tete = NULL;
    Process pr;
   // Process currentProcess;

    for (int i = 0; i < nbr; i++) {
        printf("Enter the name of process %d: ", i + 1);
        scanf("%s", pr.name);
        printf("Enter the CPU units of process %d: ", i + 1);
        scanf("%d", &pr.te);
        printf("Enter the arrival date of process %d: ", i + 1);
        scanf("%d", &pr.ta);
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
    init_queue(&file);
    enqueue(&file,&tete->proc);
    int curs =tete->proc.ta;
    printf("curs = %d",curs);
    printf("\n");
   tete = tete->next;


   
    
    
   
    while (completed < nbr) {
        while (tete != NULL && tete->proc.ta <= currentTime) {
           enqueue(&file,&tete->proc);
           tete =tete->next;
        }

        //struct Process mintempex = dequeue(&file);

// Corrected access to process information
if (mintempex.remaining_time > 0) {
    currentProcess = mintempex;
    printf("Executing process %s at time %d\n", currentProcess.name, currentTime);
    currentProcess.remaining_time--;

    if (currentProcess.remaining_time == 0) {
        completed++;
        printf("Process %s completed at time %d\n", currentProcess.name, currentTime);
    }

    while (!is_empty(&file)) {
    dequeue(&file);}
}}
   
   
    while (tete != NULL) {
        node* temp =tete;
       tete = tete->next;
        free(temp);
    }

   
}
