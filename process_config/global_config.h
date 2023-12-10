#ifndef CONFIG_H
#define CONFIG_H
// #include"../display_manger/display_conf.h"
#include "../process_def.h" 
#include "../dataStruct/node.h"
// #include"../dataStruct/queue.h"
#include <math.h>
#include <stddef.h>
#include<stdbool.h>
#include <stdlib.h>
#include <time.h>
// void get_userInput(Process* proc);
// void printTable(queue *q1,int num_proc);
// void printTable_linkedList(node *head, int num_proc);
// void printTable_view(Process *proc, int num_proc);
void random_process_generation(Process *proc,int nb_proc);
int generate_color(int *tab, int nb_proc);
int my_round(float num);
int generate_num_proc(void);
void init_rand(void);
int calculate_simulation_time(node *head);
int temps_rotation(int tf, int ta);
int temps_attente(int tf, int ta, int te);
int MOY_TR(int tf, int ta, int nbr);
int MOY_TA(int tf, int ta, int te, int nbr);
/*----------------------------------------*/

#endif /* ifndef  */

