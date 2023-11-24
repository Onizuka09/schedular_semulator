#ifndef CONFIG_H
#define CONFIG_H
#include"../display_manger/display_conf.h"

//#include"../dataStruct/queue.h"
typedef struct { 
	int ta; 
	int te; 
	int priority; 
	char name[10] ;
	colors color;

}process_settings;

void get_userInput(process_settings* proc);


/*----------------------------------------*/



#endif /* ifndef  */

