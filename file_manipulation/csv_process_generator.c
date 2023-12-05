#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../process_def.h"


int main() {
    // create a csv file
    FILE *fpt;
    fpt = fopen("File.csv", "w+");
    fprintf(fpt, "Process_Name, te, ta, Priority\n");
    int time();
    srand((unsigned int)time(NULL));

    int nb_proc = rand() % 10 + 1;

    // Allocate memory for an array of processes.
    Process *tab = malloc(nb_proc * sizeof(Process));

    // lazem nasn3 nb process
    for (int i = 0; i < nb_proc; i++) {
        // Name of the process
        sprintf(tab[i].name, "P%d", i + 1);

        // cpu units
        tab[i].te = rand() % 10 + 1;

        // Arrival date
        tab[i].ta = rand() % 10 + 1;

        // Priority
        tab[i].priority = rand() % nb_proc + 1;

        fprintf(fpt, "%s, %d, %d, %d\n", tab[i].name, tab[i].te, tab[i].ta, tab[i].priority);
    }

    free(tab); 

    fclose(fpt);
    return nb_proc;
}
