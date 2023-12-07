#include "global_config.h"
/*
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
*/

int my_round(float num)
{
	int tmp = (int)(num * 10) % 10;
	if (tmp <= 5)
		return floor(num);
	else
		return floor(num) + 1;
}
	