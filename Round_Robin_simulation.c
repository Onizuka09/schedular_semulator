//
// Created by amani on 18/11/23.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DataStructure.h"

int main() {

    int nb;
    printf("How many processes do you need? ");
    scanf("%d", &nb);
     /* n7awel nhotha fel for loop*/
    node *tmp;
    node *Head =NULL;
    Process p ;
     for (int i =0 ; i<nb;i++){
         printf("enter the name  the process n %d",i+1);
         scanf("%s",p.Name);
         printf("enter the CPU units of the process n %d",i+1);
         scanf("%d",&p.CPU_units);
         printf("enter the Arrival date of the process n %d",i+1);
         scanf("%d",&p.Arrival_date);
         tmp=create_new_node(p);
         insert_at_head(&Head, tmp);
     }
    printlist(Head);


     //tri lel linked list
    bubbleSort(&Head,nb);
    printf ("linked list is sorted : ");
    printlist(Head);


// Round-robin scheduling simulation


    queue file;
    init_queue(&file);
    int qtm = 3;

    enqueue(&file, Head->value);
    int curs = Head->value.Arrival_date;
    printf("curs = %d",curs);
    printf("\n");
    Head = Head->next;

    while (!is_empty(&file) || Head != NULL ) {
        if (!is_empty(&file)) {

            Process p1 = dequeue(&file);

            if (p1.CPU_units >= qtm) {
                p1.execution_time = qtm;
            } else {
                p1.execution_time = p1.CPU_units;
            }

            p1.CPU_units -= p1.execution_time;
            printf(" at t =  %d : ",curs);
            //printf("\n");
            curs =  curs + p1.execution_time;
            printf("Process %s is executing for %d units \n", p1.Name,p1.execution_time);
            printf("\n");


            while (Head != NULL && Head->value.Arrival_date <= curs) {
                enqueue(&file, Head->value);
                Head = Head->next;
            }

            if (p1.CPU_units > 0) {
                enqueue(&file, p1);
            } else {
                printf("Process %s is terminated\n", p1.Name);
                printf("\n");
            }
        }else{
            enqueue(&file, Head->value);
            curs = Head->value.Arrival_date;
            Head = Head->next;
        }

    }

}