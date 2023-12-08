#include "global_config.h"
static void Color_to_string(colors color, char *ch_color)
{
	switch (color)
	{
	case E_BLACK_C:
		strcpy(ch_color, BLACK "BLACK" RESET);
		break;

	case E_GREY_C:
		strcpy(ch_color, GREY"GREY"RESET);
		break;

	case E_RED_C:
		strcpy(ch_color, RED"RED"RESET);
		break;

	case E_GREEN_C:
		strcpy(ch_color, GREEN"GREEN"RESET);
		break;

	case E_YELLOW_C:
		strcpy(ch_color, YELLOW"YELLOW" RESET);
		break;

	case E_BLUE_C:
		strcpy(ch_color, BLUE"BLUE"RESET);
		break;

	case E_PURPLE_C:
		strcpy(ch_color, PURPLE"PURPLE"RESET);
		break;

	case E_CYAN_C:
		strcpy(ch_color, CYAN"CYAN"RESET);
		break;

	case E_BRIGHT_GREY_C:
		strcpy(ch_color, BRIGHT_GREY"BRIGHT_GREY"RESET);
		break;

	case E_BRIGHT_RED_C:
		strcpy(ch_color, BRIGHT_RED"BRIGHT_RED"RESET);
		break;

	case E_BRIGHT_GREEN_C:
		strcpy(ch_color, BRIGHT_GREEN"BRIGHT_GREEN"RESET);
		break;

	case E_BRIGHT_YELLOW_C:
		strcpy(ch_color, BRIGHT_YELLOW "BRIGHT_YELLOW"RESET);
		break;

	case E_BRIGHT_BLUE_C:
		strcpy(ch_color, BRIGHT_BLUE"BRIGHT_BLUE"RESET);
		break;

	case E_BRIGHT_PURPLE_C:
		strcpy(ch_color, BRIGHT_PURPLE"BRIGHT_PURPLE"RESET);
		break;

	case E_BRIGHT_CYAN_C:
		strcpy(ch_color, BRIGHT_CYAN"BRIGHT_CYAN"RESET);
		break;

	default:
		strcpy(ch_color, RESET"WHITE"RESET);
		break;
	}
}
	void get_userInput(Process * proc)
	{
		// proc->name = malloc(255);
		int cl = 0;
		printf("enter name: ");
		scanf("%s", proc->name);
		printf("enter ta: ");
		scanf("%d", &proc->ta);
		printf("enter te: ");
		scanf("%d", &proc->te);
		printf("enter priority: ");
		scanf("%d", &proc->priority);
		printf("enter color: ");
		scanf("%d", &cl);
		proc->color = intToColor(cl);
		printf("\n");
		return;
	}

	void printTable_view(Process * proc, int num_proc)
	{
		int col = 4, ligne = num_proc;
		char ch_color[50];
		// for (int i=0 ; i<col; ++i)
		//{
		printf("%s\t", proc->name);
		printf("%d\t", proc->ta);
		printf("%d\t", proc->te);
		printf("   %d\t", proc->priority);
		Color_to_string(proc->color, ch_color);
		printf("\t%s\t", ch_color);
	}
	void printTable(queue * q1, int num_proc)
	{
        printf("P_name\tTa\tTe\tPriority\tColor\n");
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
	printf("P_name\tTa\tTe\tPriority\tColor\n");
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
