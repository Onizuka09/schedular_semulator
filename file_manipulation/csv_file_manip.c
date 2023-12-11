#include "csv_file_manip.h"
bool Create_CSV_file(char * file_name , char * header )
{
    FILE *fpt;
    fpt = fopen(file_name, "w+");
    if (fpt == NULL)
    {
        printf("unable to create file");
        exit(EXIT_FAILURE);
    }
    fprintf(fpt,header);
    fclose(fpt);
    return true;
}
node* Read_csv_file(char* file_name,int *nbr)
{
    node *tmp;
    node *tete = NULL;
    Process pr;
    FILE *fpt;
    fpt = fopen(file_name, "r");
    if (fpt == NULL)
    {
        fprintf(stderr, "Error opening the file.\n");
        exit(1);
    }
    char buffer[100];
    fgets(buffer, sizeof(buffer), fpt);
    int color = 0;
    while (fgets(buffer, sizeof(buffer), fpt) != NULL)
    {
        if (sscanf(buffer, "%19[^,], %d, %d, %d,%d", pr.name, &pr.ta, &pr.te, &pr.priority, &color) == 5)
        {
            pr.color = intToColor(color);
            pr.remaining_time=pr.te;
            tmp = create_new_node(pr);
            insert_at_head(&tete, tmp);
            (*nbr) ++;
        }
    }
    fclose(fpt);
    return tete;  
}
void print_csv_file_processes(char* file_name){
    node * head; 
    int nb = 0 ;
    head = Read_csv_file(file_name,&nb);
    printTable_linkedList(head, nb); 
}
bool fill_csv_file(char* file_name )
{
    FILE *fpt;
    if (fpt = fopen(file_name, "a"))
    {
        init_rand();
        int nb_proc = generate_num_proc();
        Process *pr = (Process *)malloc(nb_proc * sizeof(Process));
        int *color_tab = malloc(nb_proc * sizeof(int));
        if (color_tab == NULL)
             exit(EXIT_FAILURE);
        memset(color_tab, 0, nb_proc * sizeof(int));
        int cl = 0; 
        for (int i = 0; i < nb_proc; i++)
        {
            random_process_generation(&pr[i], nb_proc);
            cl=generate_color(color_tab, i);
            color_tab[i] = cl; 
            sprintf(pr[i].name, "P%d", i + 1);
            fprintf(fpt, "%s, %d, %d, %d, %d\n", pr[i].name, pr[i].te, pr[i].ta, pr[i].priority,cl);
            }
            fclose(fpt);
            free(pr);
            return true;
        }
        return false;
}
bool is_file_exits(char* file_name )
{
    FILE *fpt;
    if (fpt == fopen(file_name, "r"))
    {
        fclose(fpt);
        return true;
    }
    return false; 
}
