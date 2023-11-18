#include <stdio.h>
#include <stdlib.h>

typedef struct process
{
    int DA;      // Date d'arrivee (Arrival time)
    int TE;      // Temps d'execution (Execution time)
    int tempsej; // Temps de sejour (Turnaround time)
    int temfin;  
    int pol;     // Politique
    int priorite; 
    int reste;   
} process;

#define max_chars 50

void update_bar(int total_time, int time_done)
{
    int percentage_done = time_done * 100 / total_time;
    int num_chars = (percentage_done * max_chars) / 100;
    printf("[");
    for (int i = 0; i < num_chars; ++i)
    {
        printf("#");
    }
    for (int i = 0; i < max_chars - num_chars; ++i)
    {
        printf(" ");
    }

    printf("] %d%% done \n", percentage_done);
    fflush(stdout);
}

int main()
{
    int i, j, k,nb, s;
    process *proc;
    process permut;

    printf("Entrer le nombre de processus\n");

    if (scanf("%d", &nb) != 1 || nb <= 0)
    {
        printf("Nombre de processus invalide. Le programme se termine.\n");
        return 1;
    }

    
    proc = (process *)malloc(sizeof(process) * nb);

    s = 0;

    for (k = 0; k < nb; k++)
    {
        printf("entrer la date d'arrivee du processus (%d)\n", k+ 1);
        scanf("%d", &proc[k].DA);
        printf("entrer la duree d'execution du processus (%d)\n", k+ 1);
        scanf("%d", &proc[k].TE);
        s += proc[k].TE;
    }

    // Trier le tableau par ordre croissant de temps d'exécution
    for (i = 0; i < nb - 1; i++)
    {
        for (j = 0; j < nb - i - 1; j++)
        {
            if (proc[j].TE > proc[j + 1].TE)
            {
                // Échanger les éléments
                permut = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = permut;
            }
        }
    }

    int rest = s;
for (i = 0; i < nb; i++)
{
    printf("executing p%d avec te=%d\n", i, proc[i].TE);
    rest -= proc[i].TE;
    update_bar(s, rest);
}


    free(proc); // Libérer la mémoire allouée dynamiquement

    return 0;
}
