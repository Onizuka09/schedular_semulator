#include "global_config.h"

int my_round(float num)
{
<<<<<<< HEAD
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
=======
	int tmp = (int)(num * 10) % 10;
	if (tmp <= 5)
		return floor(num);
	else
		return floor(num) + 1;
>>>>>>> main
}
void init_rand(void)
{
	srand((unsigned int)time(NULL));
}

int generate_num_proc(void)
{
	// int time();

	int nb_proc = (rand() % MAX_num_proc) + 1;
	return nb_proc;
}
int generate_color(int *tab,int nb_proc){
	// int time();
	// srand((unsigned int)time(NULL));
	int color;
	color = (rand() % TOTAL_CL )+ 1;
	for (int i = 0; i < nb_proc; i++)
	{ 
		if (*(tab+i)==color)
		{
			i = 0;
			color = (rand() % TOTAL_CL) + 1;
			continue;
		}
	}
	color <= 0 ? color = 1 : color;
	return color;
}
void  random_process_generation(Process* proc,int nb_proc)
{
	// int time();
	// srand((unsigned int)time(NULL));
	proc->te = (rand() % max_TE) + 1;
	proc->te <= 0 ? proc->te = 1 : proc->te;
	// Arrival date
	proc->ta = (rand() % max_TA);
	proc->ta <= 0 ? proc->ta = 1 : proc->ta;
	// Priority
	proc->priority = rand() % nb_proc + 1;
	proc->priority <= 0 ? proc->priority = 1 : proc->priority;
}

int calculate_simulation_time(node *head)
{
	int total_t = 0;
	node *n;
	Process p;
	n = head;
	while (n != NULL)
	{
		p = n->proc;
		if (total_t < p.ta)
		{
			total_t = p.ta;
		}
		total_t += p.te;
		n = n->next;
	}
	free(n);
	return total_t;
}