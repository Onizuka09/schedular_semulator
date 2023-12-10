//
// Created by amani on 05/12/23.
//

#include "scheculing_algorithm.h"
// Define a node structure for the linked list of queues
typedef struct QueueNode{
    queue* queue;
    struct QueueNode* next;
} QueueNode;

// Define a linked list structure for queues
typedef struct LinkedListOfQueues {
    QueueNode* head;
} LinkedListOfQueues;

// Function to insert a new node at the head of the linked list of queues
QueueNode* insert_at_head_list_queue(LinkedListOfQueues **list, QueueNode *node_to_insert) {
    node_to_insert->next = *list;
    *list = node_to_insert;
    return node_to_insert;
}
// Function to create a new node for the linked list of queues
QueueNode *create_new_node_list_queue(queue *value) {
    QueueNode *result = malloc(sizeof(QueueNode));
    result->queue = value;
    result->next = NULL;
    return result;
}
// Function to print the linked list of queues
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
//na3ml fonction te7sebli 9adeh andi men group bch naamlou
// this function was tested seprately 
int calculateNumPriorities(node* head2) {
    if (head2 == NULL) {
        return 0;  // No priorities if the list is empty
    }

    int numPriorities = 0;
    int* priorityArray = NULL;

    // Iterate through head2 and count unique priorities
    node* current = head2;
    while (current != NULL) {
        int priority = current->proc.priority;

        // Check if the priority is already counted
        int found = 0;
        for (int i = 0; i < numPriorities; ++i) {
            if (priorityArray[i] == priority) {
                found = 1;
                break;
            }
        }

        // If the priority is not found, count it and add it to the array
        if (!found) {
            priorityArray = realloc(priorityArray, (numPriorities + 1) * sizeof(int));
            if (priorityArray == NULL) {
                fprintf(stderr, "Memory allocation error.\n");
                exit(EXIT_FAILURE);
            }
            priorityArray[numPriorities++] = priority;
        }

        // Move to the next node
        current = current->next;
    }

    // Free the memory allocated for the priorityArray
    free(priorityArray);

    return numPriorities;
}

void join_team(LinkedListOfQueues* lq, node* Head)
{


}





//TO DO ...

//ne5dem fonction tasna3li linkedlist of numPriorities quues 
//this fun was tested 
LinkedListOfQueues create_linked_list_of_queues(int numPriorities) {
    LinkedListOfQueues list;
    init_linked_list_of_queues(&list);

    for (int i = 0; i < numPriorities; ++i) {
        queue *newQueue = malloc(sizeof(queue));
        if (newQueue == NULL) {
            fprintf(stderr, "Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }
        init_queue(newQueue); // Initialize a new queue

        QueueNode *newNode = create_new_node_list_queue(newQueue); // Create a new node
        insert_at_head_list_queue(&list, newNode); // Insert the new node at the head of the list
    }

    return list; // Return the linked list of queues
}

//lazem na3mel fonction tparcouri 3al head w tstoki f tableu el priority ily bch n3mlhom f groupe
int* get_repeated_priorities(node* head, int* numPriorities) {
    if (head == NULL || numPriorities == NULL) {
        // Handle the error or return early
        printf("Invalid input parameters.\n");
        return NULL;
    }

    int* priorityArray = NULL;
    int count = 0;

    // Create an array to mark visited priorities
    int* visitedArray = (int*)calloc(100, sizeof(int)); // Assuming priorities are less than 100

    // Iterate through the linked list and collect repeated priorities
    node* current = head;
    while (current != NULL) {
        int priority = current->proc.priority;

        // If the priority is not marked as visited, mark it and add to the array
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

        // Move to the next node
        current = current->next;
    }

    *numPriorities = count;

    // Free the allocated memory for visitedArray
    free(visitedArray);

    return priorityArray;
}


// tawa lazem nsortyyh 
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
//lazem na3mel fonction tparcouri al teamlist w ta3ty kol queue  id  men table of priority ily sna3tou
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
            // Handle the case where there are more queues than priorities
            //printf("Not enough priorities to assign to all queues\n");
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
//ne5dem function ta9ra mel head2 w thot kol process fel queue ily 5assa byh kenou share pr maa had a5er w tfas5ou mel head2 sinon kenou andou unique pr mata3ml chy
LinkedListOfQueues* join_team(LinkedListOfQueues* teamList, node* lk,int* p_arr,int size_p) {
    node *i;
    node *j;
    int counter=0; 
    // int check
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
        //	read csv file
        char *csv = CSV_file_name;
        Head = Read_csv_file(csv, &nb_proc);
        printf("nbr proc: %d\n", nb_proc);
        printf("nbr proc: %d\n", nb_proc);
        printTable_linkedList(Head, 0);
        linkedlist_bubbleSort(&Head, nb_proc);
        printf("\nlinked list loula sorted by ta\n");
        printlist(Head);
        /*******************************************************************************/
        // ne7seb 9adeh andi men groupe
        int nbP = calculateNumPriorities(Head);
        // tawa nasn3 linkedlist of queus fer8a de taiile nbP
        LinkedListOfQueues teamlist = create_linked_list_of_queues(nbP);
        int *priorityArray = get_repeated_priorities(Head, &nbP);
        // Sort the array
        bubbleSort(priorityArray, nbP);
        // Assign priorities to each queue in teamList
        assign_priorities(&teamlist, priorityArray, nbP);
        // print list
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
        // algo
        int current_time = Head->proc.ta;
        node *Chead = Head;
        node *waitlist;
        int l2 = 0;
        int lastnode;
        // bech ykounou fi wost while curs < last node
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
            // tawa wait list fyha el processes ily mawjoudin andi fel current time
            // tawa na3mlelha sort hasb el priority
            linkedlist_bubbleSortpriority(&waitlist, l2);
            // tawa bch nasn3 men wait list groups w nhothom fel teamlist
            join_team(&teamlist, waitlist);
            // tawa bch n9aren awel elemtn fel wait list b awel elemnt f awl queu fel teamlist
            if (waitlist->proc.priority > teamlist.head->queue->id && waitlist != NULL)
            {
                // ne5dem priority with interruption adiya
                waitlist->proc.remaining_time--;
                current_time++;
                if (waitlist->proc.remaining_time == 0)
                {
                    // printf("\n process %s" , Head2->proc.name);
                    // printf("is terminated");
                    waitlist = waitlist->next;
                    l2--;
                }
                // round robin
            }
            else if (teamlist.head->queue->head->proc.remaining_time > 0 && teamlist.head->queue->head->proc.remaining_qtm != qtm)
            {
                // ye5dem one unit
                teamlist.head->queue->head->proc.remaining_time--;
                current_time++;
                // nchouf remaining time kenou 0 na3mlou dequee
                if (teamlist.head->queue->head->proc.remaining_time == 0)
                {
                    dequeue(&teamlist.head->queue);
                    if (is_empty(teamlist.head->queue))
                    {
                        teamlist.head = teamlist.head->next;
                    }
                    // ken remaining time te3ou mahouch 0 lazem na3mlou dequeue w ba3d enqueue bch n7awlou f a5er queue
                }
                else
                {
                    dequeue(&teamlist.head->queue);
                    enqueue(&teamlist.head->queue);
                }
            }
        }
        // tawa andi kol woslou w teamlist sorted   ne5dem bel te mch b unit by unit bch tji el update bar mrigla
        //......
    }








/*TEST get_repeated_priorities
int* priorityArray = get_repeated_priorities(Head, &nbP);
// Sort the array
    bubbleSort(priorityArray, nbP);

    if (priorityArray != NULL) {
        printf("Table of Repeated Priorities:\n");
        for (int i = 0; i < nbP; ++i) {
            printf("%d ", priorityArray[i]);
        }
        printf("\n");

        // Free the allocated memory for priorityArray
        free(priorityArray);
    }
*/











































