#include <stdio.h>
#include"process_def.h"
#include "scheduling_algorithms/scheculing_algorithm.h"
#include "file_manipulation/csv_file_manip.h"
#define num_choices 7
#define num_algos  6
const char *asciiArt =
	"\t███████  ██████ ██   ██ ███████ ██████  ██    ██ ██      ███████ ██████      ███████ ██ ███    ███ ██    ██ ██       █████  ████████  ██████  ██████  \n"
	"\t██      ██      ██   ██ ██      ██   ██ ██    ██ ██      ██      ██   ██     ██      ██ ████  ████ ██    ██ ██      ██   ██    ██    ██    ██ ██   ██ \n"
	"\t███████ ██      ███████ █████   ██   ██ ██    ██ ██      █████   ██████      ███████ ██ ██ ████ ██ ██    ██ ██      ███████    ██    ██    ██ ██████  \n"
	"\t     ██ ██      ██   ██ ██      ██   ██ ██    ██ ██      ██      ██   ██          ██ ██ ██  ██  ██ ██    ██ ██      ██   ██    ██    ██    ██ ██   ██ \n"
	"\t███████  ██████ ██   ██ ███████ ██████   ██████  ███████ ███████ ██   ██     ███████ ██ ██      ██  ██████  ███████ ██   ██    ██     ██████  ██   ██ \n";

	void
	clear_screen()
{
	printf("\033[2J\033[H");
	fflush(stdout);
}
void display_f(){
	char *file_name = CSV_file_name;
	print_csv_file_processes(file_name);
}
void Generate_processes ()
{
	printf("Generating ... \n");
	sleep(1);
	char *file_name = CSV_file_name;
	Create_CSV_file(file_name,CSV_file_header);
	fill_csv_file(file_name); 
	printf("Generated processes \n");
	display_f(file_name);
}

int get_user_choise(int defaul_choice)
{
	char ch;
	int choice;
	fflush(stdin);
	scanf("%c", &ch);
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
	if (ch == '\n')
	{
		choice = defaul_choice;
	}
	else
	{
		choice = ch - '0';
	}
	// printf("%c\n", ch);
	// printf("%d\n", ch);

	return choice;
}
void choice_loop (char *wlcm_str , void (*p_choice_function)(void) )
{	
	int a = 0; 
	do
	{
		printf("%s", wlcm_str); 
		p_choice_function();
		printf("1- <-return to menu *(default)\n");
		printf("2- re-run\n");
		printf(BLINK"$:"RESET);
		fflush(stdout);
		a = get_user_choise(1);
		clear_screen();
	} while (a == 2);
}
void p_menu_algorithms(void )
{
	printf("Please select an algorithm:) \n");
	printf("\t1: FIFO (default): \n");
	printf("\t2: Priority (non-preamptive):\n");
	printf("\t3: Round Robin :\n");
	printf("\t4: SRT (preamptive):\n");
	printf("\t5: Priority (preamptive): \n");
	printf("\t6: Multi Level:\n");
	printf("\t7: <-return to menu\n");
}
enum
{
	FIFO = 1,
	Priority,
	Round_Robin,
	SRT_p,
	Priority_p, 
	Multi_Level,
} algos;
void menu_algos(void)
{	char* st ; 	
	int select =0 ;
	do
	{	
		algo_start: p_menu_algorithms();
		printf("Enter a num: ");
		select = get_user_choise(FIFO);
		printf("\n");
		if (select < 1 || select > num_algos + 1)
		{
			printf("ERROR: you ever entered the wrong choice \nPlease enter a choice form 1..%d \n", num_algos + 1);
			goto algo_start;
		}
		switch (select)
		{
		case FIFO:
			clear_screen();
			st = "Excuting FiFo\n";
			choice_loop(st, &FIFO_algo);
			break;
		case Priority:
			clear_screen();
			st = "Excuting Priority (Non preamptive) \n";
			choice_loop(st, &Priority_algo);
			break;
		case Round_Robin:
			clear_screen();
			st = "Excuting Round Robin\n";
			choice_loop(st, &Round_Robin_algo);
			break;
		case SRT_p:
			clear_screen();
			st = "Excuting SRT (Preamptive)\n";
			choice_loop(st, &SRT_algo);
			break;
		case Priority_p:
			clear_screen();
			st = "Excuting Priority (Preamptive)\n";
			choice_loop(st, &Priority_Preamptive);
			break;
		case Multi_Level:
			clear_screen();
			st = "Excuting Multilevel\n";
			break;
		case 7:
			break;
		}
		} while (select != num_algos + 1);
}
void printMenu()
{
printf("Please enter a number from 1..%d to select a functionanlity :) \n",num_choices); 
printf("\t1: Generate CSV_file: \n"); 
printf("\t2: View Processes:\n");
printf("\t3: Simulate a schedular(Console):\n");
printf("\t4: Simulate a schedular (Graphical User Inteface):\n");
printf("\t5: View metrics:\n");
printf("\t6: Configuration:\n");
printf("\t7: exit (default)\n");
}

int main() 
{	
	init_gtk();
	clear_screen();
	int x;
	char *str;
	printf(PURPLE);
	printf(BLINK);
	printf("\n%s\n", asciiArt);
	printf(RESET);
	printf("Welocome to the scheduler simulator Application: \n");
	do
	{
	start:
		printMenu();
		printf("Enter a num: ");
		// printf("%d\n",x);
		x = get_user_choise(num_choices);
		printf("\n");
		if (x < 1 || x > num_choices)
		{
			printf("ERROR: you ever entered a wrong choice \nPlease enter a choice form 1..%d \n", num_choices);
			sleep(1);
			goto start;
		}
		switch (x)
		{
		case 1:
			clear_screen();
			str = "Processes generation\n";
			choice_loop(str, &Generate_processes);
			break;
		case 2:
			clear_screen();
			str = "CSV file content:\n ";
			choice_loop(str, &display_f);
			break;
		case 3:
			clear_screen();
			menu_algos();
			break;
		case 4:
			printf("\033[2J\033[H");
			fflush(stdout);
			printf("Choice 4");
			break;
		case 5:
			printf("Choice 5");
			break;
		case 7:
			printf("exiting ... \n");
			// printf("")
			sleep(1);
			break;
		}
		printf("\n");
		clear_screen();
	} while (x != num_choices);
	printf("GOOD BYE :)\n");
	return 0;
}
