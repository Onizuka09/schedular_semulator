#ifndef CONFIG_H
#define CONFIG_H
#include"../display_manger/display_conf.h"
#include "../process_def.h" 
#include"../dataStruct/queue.h"
void get_userInput(process_settings* proc);

void printTable(queue *q1,int num_proc);

/*----------------------------------------*/



#endif /* ifndef  */
