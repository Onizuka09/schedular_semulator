
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

  
     /* n7awel nhotha fel for loop*/
    node *tmp;
    node *Head =NULL;
    Process p ;
    int color, sum=0 ; 

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
            sum+= sum+p.te;
            
        }
    }

    printlist(Head);

     //tri lel linked list
    linkedlist_bubbleSort(&Head,8);
    printf ("linked list is sorted : ");
    printlist(Head);


  // priority non scheduling simulation
    queue file;
    init_queue(&file);
    queue fileExecute;
    init_queue(&fileExecute);
    node *tmp1;
    node *Head1 = NULL;

    enqueue(&file, &Head->proc);
    int curs = Head->proc.ta;
    printf("curs = %d", curs);
    printf("\n");

    while (!is_empty(&file) || Head != NULL) {
        if (!is_empty(&file)) {
            while (file.head->proc.ta <= curs) {
                printf(".......");
                Process *p1 = dequeue(&file);
                printf(".........");
                tmp1 = create_new_node_new(p1);
                insert_at_head(&Head1, tmp1);
                linkedlist_bubbleSortpriority(&Head1, 8);
                printf("linked list is sorted by priority: ");
                printlist(Head1);
              /*   Head1 = Head1->next; */
               file.head= file.head->next;
                update_bar_amani(sum, p1->te);
                printf("Process %s is executing for %d units \n", p1->name, p1->te);
                free(p1);
            }
            curs += Head1->proc.te;
        }

        // Assurez-vous que la file se vide correctement
        if (Head != NULL) {
            Head = Head->next;
        }
    }

    // ...

    return 0;
}
