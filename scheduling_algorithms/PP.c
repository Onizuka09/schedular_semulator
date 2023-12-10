//
// Created by amani on 05/12/23.
//


#include "scheculing_algorithm.h"


void Priority_Preamptive(void) {

    int nb_proc=0;
    node *tmp;
    node *Head = NULL ;
    Process *Gproc = malloc(sizeof(Process));

    //	read csv file
    queue GUIq;
    init_queue(&GUIq);
    char *csv = CSV_file_name;
	Head = Read_csv_file(csv, &nb_proc);
	printf("nbr proc: %d\n", nb_proc);

    linkedlist_bubbleSort(&Head,nb_proc);
    printTable_linkedList(Head,0);
// printf("linked list loula sorted by ta\n");
// printlist(Head);

    int curs = 0,c_time=0,wait_time=0;

//printf(" curs = %d",curs);
//printf("\n");

    node *tmp2;
    node *Head2 =NULL;
    node *metrics_pp= NULL;
    queue metrics_q;
    Process* m_proc; 
    init_queue(&metrics_q);
    metrics_pp = Head;
    int l2=0;
    bool b = true;
    int total_t = calculate_simulation_time(Head);
    curs = Head->proc.ta;
    c_time = 0 ; 
    
    //TODO: create a function that get the last process arrival time 

    node* CHead = Head;
    while (CHead->next!=NULL)
    {
        CHead=CHead->next;

    }
    int last_node = CHead->proc.ta;
    CHead=Head;
    //printf("last node : %d",last_node);
    
printf("\n");


    while (curs <=last_node) // last p.ta in my list 
    {
        // printf(" curs = %d",curs);
        // printf("\n");
        

        while ((CHead != NULL) && (b == true))
        {
            if (CHead->proc.ta <= curs)
            {
                node *tmp2 = create_new_node(CHead->proc);
                insert_at_head(&Head2, tmp2);
                l2++;
                CHead = CHead->next;
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
        Head2->proc.burst_time = c_time;
        strcpy(Gproc->name, "waiting");
		Gproc->ta = c_time;
		Gproc->te = wait_time;
		Gproc->color = E_RESET_C;
		enqueue(&GUIq, Gproc);
        c_time += wait_time;
        }   
    else {
        Head2->proc.burst_time = c_time;
    }

    linkedlist_bubbleSortpriority(&Head2,l2);
    //printlist(Head2);
    //nexicuty awl process fel waitlist 
    // if ()
    Head2->proc.remaining_time--;
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

    
    strcpy(Gproc->name, Head2->proc.name);
    Gproc->ta = c_time;
    Gproc->te = Head2->proc.execution_time ;
    Gproc->color = Head2->proc.color;
    enqueue(&GUIq, Gproc);
    curs++;
    c_time++;
    b = true;
    if (Head2->proc.remaining_time==0){
        //printf("\n process %s" , Head2->proc.name);
        //printf("is terminated");
        //mtrc
        Head2->proc.end = c_time ;
        m_proc = &(Head2->proc);
        enqueue(&metrics_q,m_proc);
        // metrics_pp->proc.end = c_time;
        Head2=Head2->next;
        l2--;

    }
    
    
}
linkedlist_bubbleSortpriority(&Head2, l2);
while (Head2!= NULL){
    if (c_time == Head2->proc.ta)
    {
        Head2->proc.burst_time = c_time;
    }
    printf(clear_line);
    fflush(stdout);
    printf("\rexecuting proc %s for %d \n", Head2->proc.name, Head2->proc.remaining_time);
    update_bar(total_t, Head2->proc.remaining_time, c_time, Head2->proc.color);
    update_time(total_t, Head2->proc.remaining_time, c_time, Head2->proc.color);
    sleep(Head2->proc.remaining_time);
    printf(ESC CSI "%d" previousLine, 3);
    strcpy(Gproc->name, Head2->proc.name);
    Gproc->ta = c_time;
    Gproc->te = Head2->proc.remaining_time;
    Gproc->color = Head2->proc.color;
    enqueue(&GUIq, Gproc);
    // curs++;
    c_time += Head2->proc.remaining_time;
    //mtrcs
    metrics_pp->proc.end =c_time;
    Head2->proc.end = c_time;
    m_proc = &(Head2->proc);
    enqueue(&metrics_q, m_proc);
    Head2 = Head2->next; 
}
 
printf("\n\n\n");
printf("done !!\n");
// printTable_linkedList(Head,0);
printTable_metrics(&metrics_q,nb_proc);


return;
char *title = "Round-Robin Execution";

create_widget(&GUIq, title);
while (GUIq.head != NULL)
{
    Gproc = dequeue(&GUIq);
}
free(Gproc);
return;
}
