#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    // Definition of the Process structure representing a process with name, CPU units, priority, and arrival date.
    typedef struct Process{
        char* Name;
        int CPU_units;
        int priority;
        int Arrival_date;
    }Process;

    //create a csv file
    FILE *fpt;
    fpt = fopen("MyFile.csv", "w+");
    fprintf(fpt,"Process_Name, CPU_units, Arrival_date, Priority\n");

    int nb ;
    printf ("How many processes do you need? ");
    scanf("%d" ,&nb);

//Allocate memory for an array of processes.
Process* tab= malloc(nb * sizeof(Process*));

// lazem nasn3 nb process
for (  int i=1;i<=nb ;i++) {
 //Name of the process
    tab[i].Name = (char*)malloc(sizeof(char*));
    printf (" Name Of process number %d",i);
    scanf("%s" ,tab[i].Name);
//cpu units
    printf (" CPU units of process number %d",i);
    scanf("%d" ,&tab[i].CPU_units);
//Arrival date
    printf (" Arrival date  of process number %d",i);
    scanf("%d" ,&tab[i].Arrival_date);
//Priority
    printf ("priority  of process number %d",i);
    scanf("%d" ,&tab[i].priority);

fprintf(fpt, "%s, %d, %d, %d \n", tab[i].Name, tab[i].CPU_units, tab[i].Arrival_date, tab[i].priority);
}

    return 0;
}
