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
        if (sscanf(buffer, "%19[^,], %d, %d, %d", p.name, &p.te, &p.ta, &p.priority) == 4) {
            // Create a new node and insert it into the linked list
            tmp=create_new_node(p);
            insert_at_head(&Head, tmp);
            nb_proc++;
            
        }
    }



}