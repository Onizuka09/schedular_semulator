#include "scheculing_algorithm.h"
typedef struct QueueNode{
    queue* queue;
    struct QueueNode* next;
} QueueNode;
typedef struct LinkedListOfQueues {
    QueueNode* head;
} LinkedListOfQueues;
QueueNode* insert_at_head_list_queue(LinkedListOfQueues **list, QueueNode *node_to_insert) {
    node_to_insert->next = *list;
    *list = node_to_insert;
    return node_to_insert;
}
QueueNode *create_new_node_list_queue(queue *value) {
    QueueNode *result = malloc(sizeof(QueueNode));
    result->queue = value;
    result->next = NULL;
    return result;
}
void print_linked_list_of_queues(LinkedListOfQueues *list) {
    if (list == NULL) {
        printf("List is NULL\n");
        return;
    }
    QueueNode *current = list->head;
    while (current != NULL) {
        if (current->queue != NULL && current->queue->head != NULL) {
            printf("%d - ", current->queue->head->proc.priority);
        } else {
            printf("NULL - ");
        }
        current = current->next;
    }
    printf("\n");
}
void init_linked_list_of_queues(LinkedListOfQueues *list) {
    list->head = NULL;
}
void Check_insert_and_sort(node** head2, node** chead, int* l2, int curs) {
    while (*chead != NULL && (*chead)->proc.ta <= curs) {
        node* tmp2 = create_new_node((*chead)->proc);
        insert_at_head(head2, tmp2);
        (*l2)++;
        *chead = (*chead)->next;
    }
    linkedlist_bubbleSortpriority(head2,l2);
}
int calculateNumPriorities(node* head2) {
    if (head2 == NULL) {
        return 0;  
    }
    int numPriorities = 0;
    int* priorityArray = NULL;
    node* current = head2;
    while (current != NULL) {
        int priority = current->proc.priority;
        int found = 0;
        for (int i = 0; i < numPriorities; ++i) {
            if (priorityArray[i] == priority) {
                found = 1;
                break;
            }
        }
        if (!found) {
            priorityArray = realloc(priorityArray, (numPriorities + 1) * sizeof(int));
            if (priorityArray == NULL) {
                fprintf(stderr, "Memory allocation error.\n");
                exit(EXIT_FAILURE);
            }
            priorityArray[numPriorities++] = priority;
        }
        current = current->next;
    }
    free(priorityArray);
    return numPriorities;
}
void join_team(LinkedListOfQueues* lq, node* Head)
{
}
LinkedListOfQueues create_linked_list_of_queues(int numPriorities) {
    LinkedListOfQueues list;
    init_linked_list_of_queues(&list);
    for (int i = 0; i < numPriorities; ++i) {
        queue *newQueue = malloc(sizeof(queue));
        if (newQueue == NULL) {
            fprintf(stderr, "Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }
        init_queue(newQueue); 
        QueueNode *newNode = create_new_node_list_queue(newQueue); 
        insert_at_head_list_queue(&list, newNode); 
    }
    return list; 
}
int* get_repeated_priorities(node* head, int* numPriorities) {
    if (head == NULL || numPriorities == NULL) {
        printf("Invalid input parameters.\n");
        return NULL;
    }
    int* priorityArray = NULL;
    int count = 0;
    int* visitedArray = (int*)calloc(100, sizeof(int)); 
    node* current = head;
    while (current != NULL) {
        int priority = current->proc.priority;
        if (!visitedArray[priority]) {
            visitedArray[priority] = 1;
            node* checkCurrent = current->next;
            while (checkCurrent != NULL) {
                if (checkCurrent->proc.priority == priority) {
                    priorityArray = realloc(priorityArray, (count + 1) * sizeof(int));
                    if (priorityArray == NULL) {
                        fprintf(stderr, "Memory allocation error.\n");
                        exit(EXIT_FAILURE);
                    }
                    priorityArray[count++] = priority;
                    break;
                }
                checkCurrent = checkCurrent->next;
            }
        }
        current = current->next;
    }
    *numPriorities = count;
    free(visitedArray);
    return priorityArray;
}
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
void assign_priorities(LinkedListOfQueues* teamList, int priorities[], int numPriorities) {
    if (teamList == NULL) {
        printf("teamList is NULL\n");
        return;
    }
    QueueNode* current = teamList->head;
    int i = 0;
    while (current != NULL) {
        if (i < numPriorities) {
            current->queue->id = priorities[i++];
        } else {
            break;
        }
        current = current->next;
    }
}
void  insert_liknedlist_of_queue_at_id(LinkedListOfQueues* teamList,Process *proc, int id )
{
    while (teamList->head!= NULL)
    {
    }
}
LinkedListOfQueues* join_team(LinkedListOfQueues* teamList, node* lk,int* p_arr,int size_p) {
    node *i;
    node *j;
    int counter=0; 
    int p=0; 
    Process *pr; 
    while (counter !=size_p)
    {
        p = *(p_arr + counter);
        for (i = lk; i != NULL; i = i->next)
        {
                if (i->proc.priority == p )
                {
                    pr = &(i->proc);
                    insert_liknedlist_of_queue_at_id(teamList,pr, p);
                }
        }
        counter ++; 
    }
}
void main()
    {
        int qtm, nb_proc = 0;
        printf("Quantum value ? ");
        scanf("%d", &qtm);
        node *tmp;
        node *Head = NULL;
        char *csv = CSV_file_name;
        Head = Read_csv_file(csv, &nb_proc);
        printf("nbr proc: %d\n", nb_proc);
        printf("nbr proc: %d\n", nb_proc);
        printTable_linkedList(Head, 0);
        linkedlist_bubbleSort(&Head, nb_proc);
        printf("\nlinked list loula sorted by ta\n");
        printlist(Head);
        int nbP = calculateNumPriorities(Head);
        LinkedListOfQueues teamlist = create_linked_list_of_queues(nbP);
        int *priorityArray = get_repeated_priorities(Head, &nbP);
        bubbleSort(priorityArray, nbP);
        assign_priorities(&teamlist, priorityArray, nbP);
        while (teamlist.head != NULL)
        {
            if (teamlist.head->queue != NULL)
            {
                if (teamlist.head->queue->id != NULL)
                {
                    printf("\n%d", teamlist.head->queue->id);
                }
                else
                {
                    break;
                }
            }
            teamlist.head = teamlist.head->next;
        }
        int current_time = Head->proc.ta;
        node *Chead = Head;
        node *waitlist;
        int l2 = 0;
        int lastnode;
        while (current_time < lastnode)
        {
            while (Head != NULL)
            {
                if (Head->proc.ta <= current_time)
                {
                    node *tmp2 = create_new_node(Head->proc);
                    insert_at_head(&waitlist, tmp2);
                    l2++;
                    Head = Head->next;
                }
            }
            linkedlist_bubbleSortpriority(&waitlist, l2);
            join_team(&teamlist, waitlist);
            if (waitlist->proc.priority > teamlist.head->queue->id && waitlist != NULL)
            {
                waitlist->proc.remaining_time--;
                current_time++;
                if (waitlist->proc.remaining_time == 0)
                {
                    waitlist = waitlist->next;
                    l2--;
                }
            }
            else if (teamlist.head->queue->head->proc.remaining_time > 0 && teamlist.head->queue->head->proc.remaining_qtm != qtm)
            {
                teamlist.head->queue->head->proc.remaining_time--;
                current_time++;
                if (teamlist.head->queue->head->proc.remaining_time == 0)
                {
                    dequeue(&teamlist.head->queue);
                    if (is_empty(teamlist.head->queue))
                    {
                        teamlist.head = teamlist.head->next;
                    }
                }
                else
                {
                    dequeue(&teamlist.head->queue);
                    enqueue(&teamlist.head->queue);
                }
            }
        }
    }
    linkedlist_bubbleSortpriority(&waitlist,l2);
    join_team(&teamlist,waitlist);
    if (waitlist->proc.priority > teamlist.head->queue->id && waitlist!= NULL){
        waitlist->proc.remaining_time--;
        current_time++;
        if (waitlist->proc.remaining_time==0){
            waitlist=waitlist->next;
            l2--;
        }
    } else 
    {
        if (teamlist.head->queue->head->proc.remaining_time>0  &&  teamlist.head->queue->head->proc.remaining_qtm != qtm){
            teamlist.head->queue->head->proc.remaining_time--;
            current_time++;
            if (teamlist.head->queue->head->proc.remaining_time==0){
               dequeue(&teamlist.head->queue);
               if ( is_empty(teamlist.head->queue) ){
                teamlist.head=teamlist.head->next;}
            }else {
                 dequeue(&teamlist.head->queue);
                 enqueue(&teamlist.head->queue);}
    } 
   }
while ( waitlist!=NULL || teamlist !=NULL){
    if (waitlist->proc.priority > teamlist.head->queue->id && waitlist!=NULL){
        current_time +=  (waitlist->proc.te) - (waitlist->proc.remaining_time) ;
        waitlist->proc.remaining_time = 0 ;
        waitlist=waitlist->next;
        l2--;
    }else if (waitlist->proc.priority < teamlist.head->queue->id && teamlist!=NULL){
        current_time += (teamlist.head->queue->head->proc.te) - (teamlist.head->queue->head->proc.remaining_time);
        teamlist.head->queue->head->proc.remaining_time=0;
        dequeue(&teamlist.head->queue);
        if ( is_empty(teamlist.head->queue) ){
                teamlist.head=teamlist.head->next;}
    }
}
