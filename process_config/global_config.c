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

static void printTable_view(process_settings* proc, int num_proc){
int col=4  , ligne=num_proc; 
//for (int i=0 ; i<col; ++i)
//{
	printf("%s\t",proc->name);
	printf("%d\t",proc->ta);
	printf("%d\t",proc->te);
	printf("%d\t",proc->priority); 
}
void printTable(queue *q1,int num_proc){
        printf("P_name\tTa\tTe\tPriority\n");
	node *tmp = q1->head; 
    while (tmp!= NULL)
    {
		process_settings proc = tmp->proc; 
		//printf("Proc: %s has arrived executing it now for: %d \n", proc->name, proc->te);
		printTable_view(&proc,num_proc);
		printf("\n");
		tmp=tmp->nxt;
 
    }
}

