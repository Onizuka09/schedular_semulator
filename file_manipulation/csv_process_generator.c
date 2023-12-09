#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../process_def.h"
#include "csv_file_manip.h"

int main() {
    // create a csv file
    char *csv = CSV_file_name; 
    Create_CSV_file(csv);
    fill_csv_file(csv);
    node *tete;
    int nb=0;
    
    // printTable_linkedList(tete, 0);
    char buffer[300];
    tete = Read_csv_file(csv,&nb);
    printf("%d \n", nb);
    printTable_linkedList(tete, 0);
    return 0;
    }
