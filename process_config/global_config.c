#include "global_config.h"
void get_userInput(process_settings* proc){ 
	//proc->name = malloc(255);
	int cl=0;
	printf("enter name: "); 
	scanf("%s",proc->name);
	printf("enter ta: "); 
	scanf("%d",&proc->ta);
	printf("enter te: "); 
	scanf("%d",&proc->te);
	printf("enter priority: "); 
	scanf("%d",&proc->priority);
	printf("enter color: ");
	scanf("%d",&cl);
	proc->color= intToColor(cl);
	printf("\n");
return ;
}
