#include "global_config.h"
void get_userInput(Process* proc){ 
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

void printTable_view(Process* proc, int num_proc){
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
		Process proc = tmp->proc; 
		//printf("Proc: %s has arrived executing it now for: %d \n", proc->name, proc->te);
		printTable_view(&proc,num_proc);
		printf("\n");
		tmp=tmp->next;
    }
	printf("\n");
}
void printTable_linkedList(node *head, int num_proc)
{
	node *tmp = head;
	printf("P_name\tTa\tTe\tPriority\n");
	while (tmp != NULL)
	{
		Process proc = tmp->proc;
		// printf("Proc: %s has arrived executing it now for: %d \n", proc->name, proc->te);
		printTable_view(&proc, num_proc);
		printf("\n");
		tmp = tmp->next;
	}
	printf("\n");
}
