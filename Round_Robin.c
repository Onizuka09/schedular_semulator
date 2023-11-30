//
// Created by amani on 18/11/23.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#include "display_manger/display_conf.h" 
#include "process_config/global_config.h"
#include "dataStruct/linkedlist.h"
#include "dataStruct/queue.h"
#include "process_def.h" 
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

    int nb ,qtm;
    printf("How many processes do you need? ");
    scanf("%d", &nb);
    printf("Quantum value ? ");
    scanf("%d", &qtm);
     /* n7awel nhotha fel for loop*/
    node *tmp;
    node *Head =NULL;
    Process p ;
    int color; 
     for (int i =0 ; i<nb;i++){
         printf("enter the name  the process n %d: ",i+1);
         scanf("%s",p.name);
         printf("enter the CPU units of the process n %d: ",i+1);
         scanf("%d",&p.te);
         printf("enter the Arrival date of the process n %d: ",i+1);
         scanf("%d",&p.ta);
         printf("enter the color%d: ",i+1);
         scanf ("%d",&color);
         p.color = intToColor(color);
         tmp=create_new_node(p);
         insert_at_head(&Head, tmp);
     }
    printlist(Head);

     //tri lel linked list
    linkedlist_bubbleSort(&Head,nb);
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
    

    while (!is_empty(&file) || Head != NULL ) {
        if (!is_empty(&file)) {

            Process *p1 = dequeue(&file);

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

}
