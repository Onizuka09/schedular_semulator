#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../display_manger/display_conf.h"
#include "../process_config/global_config.h"
#include "../dataStruct/linkedlist.h"
#include "../dataStruct/queue.h"
#include "../process_def.h"


void afficherFile(queue *file) {
    if (file == NULL || file->tail == 0) {
        printf("La file est vide.\n");
        return;
    }

    printf("Contenu de la file : ");
    node *actuel = file->head;
    while (actuel != NULL) {
        printf("%d ", actuel->proc);  // Assurez-vous de changer le type de valeur en fonction de votre implémentation
        actuel = actuel->next;
    }
    printf("\n");
}

void update_bar_priority(int total_time, int time_done) {
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
    node *tmp;
    node *Head = NULL;
    Process p , *proc;
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
            
            tmp = create_new_node(p);
            insert_at_head(&Head, tmp);
        }
    }

    printlist(Head);
    int sum = 0;
    for (tmp = Head; tmp != NULL; tmp = tmp->next) {
        sum += tmp->proc.te;
    }

    // Tri de la liste chaînée
    linkedlist_bubbleSort(&Head, 8);
    printf("Linked list is sorted: ");
    printlist(Head);

    sleep(2);
    printf("Total Time is %d\n", sum);

    int tempsActuel = 0;
    queue *fileParPriorite = extraireParTempsEtPriorite(Head, tempsActuel);

    afficherFile(fileParPriorite);

    /* proc = &fileParPriorite->head->proc;

    for (int i=0 ; i < proc->te+1; i++)
    {
         printf("#");
    }
    
    tempsActuel += proc->te;

     printf("\n\nDone!\n"); 

 */

















/*     
      // Exécuter les processus triés par priorité
    for (int tempsActuel = 0; tempsActuel < sum;) {
        // Extraire les processus de la file initiale et les placer dans la file triée par priorité
        queue *fileParPriorite = extraireParTempsEtPriorite(Head, tempsActuel);

        if (!is_empty(&fileParPriorite) ){
            // Exécuter le processus en tête de la file triée par priorité
            Process *processusEnCours = dequeue(fileParPriorite);

            // Afficher l'exécution du processus
            printf("Execution du processus %s pendant %d unités de temps\n", processusEnCours->name, processusEnCours->te);

            // Mise à jour du temps actuel
            tempsActuel += processusEnCours->te;

            // Afficher l'état des processus après l'exécution
            printf("Etat des processus après l'execution :\n");
            printlist(fileParPriorite->head);

            // Libérer la mémoire du processus en cours
            free(processusEnCours);
        } else {
            // S'il n'y a pas de processus à exécuter à ce moment, incrémentez simplement le temps actuel
            tempsActuel++;
        }

        // Mise à jour de la barre de progression
        update_bar_priority(sum, tempsActuel);
    }

    printf("\n\nDone!\n"); */

    // ... (Libération de la mémoire, etc.)

    return 0;
}
