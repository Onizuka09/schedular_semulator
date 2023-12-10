#include "global_config.h"

int my_round(float num)
{
	int tmp = (int)(num * 10) % 10;
	if (tmp <= 5)
		return floor(num);
	else
		return floor(num) + 1;
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
	do {
	color = (rand() % TOTAL_CL )+ 1;
	for (int i = 0; i < nb_proc; i++)
	{ 
		if (*(tab+i)==color)
		{
			i = 0;
			color = (rand() % TOTAL_CL) + 1;
			// continue;
		}
	}
	} while ((color <= 0));
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