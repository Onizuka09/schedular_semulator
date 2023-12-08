#include <stdio.h>
#define RESET				"\x1b[0m"
#define BLACK              	"\x1b[1m"
#define GREY               	"\x1b[2m"
#define RED                	"\x1b[31m"
#define GREEN              	"\x1b[32m"
#define YELLOW             	"\x1b[33m"
#define BLUE           		"\x1b[34m"
#define PURPLE            	"\x1b[35m"
#define CYAN           		"\x1b[36m"
#define BRIGHT_GREY         "\x1b[90m"
#define BRIGHT_RED          "\x1b[91m"
#define BRIGHT_GREEN        "\x1b[92m"
#define BRIGHT_YELLOW       "\x1b[93m"
#define BRIGHT_BLUE     	"\x1b[94m"
#define BRIGHT_PURPLE       "\x1b[95m"
#define BRIGHT_CYAN     	"\x1b[96m"
typedef enum
{
	E_RESET_C,
	E_BLACK_C,
	E_GREY_C,
	E_RED_C,
	E_GREEN_C,
	E_YELLOW_C,
	E_BLUE_C,
	E_PURPLE_C,
	E_CYAN_C,
	E_BRIGHT_GREY_C,
	E_BRIGHT_RED_C,
	E_BRIGHT_GREEN_C,
	E_BRIGHT_YELLOW_C,
	E_BRIGHT_BLUE_C,
	E_BRIGHT_PURPLE_C,
	E_BRIGHT_CYAN_C,
	TOTAL_COLORS,
} colors;
#define TOTAL_CL (int)TOTAL_COLORS-1
int main(void)
{
	int i, j, n;
// printf("")
	printf("num: %d \n ", TOTAL_CL);
	printf(BLACK "hello world\n" RESET);

	printf(GREY "hello world\n" RESET);
	printf(RED "hello world\n" RESET);
	printf(GREEN "hello world\n" RESET);
	printf(YELLOW "hello world\n" RESET);
	printf(BLUE "hello world\n" RESET);
	printf(PURPLE "hello world\n" RESET);
	printf(CYAN "hello world\n" RESET);
	printf(BRIGHT_GREY "hello world\n" RESET);
	printf(BRIGHT_RED "hello world\n" RESET);
	printf(BRIGHT_GREEN "hello world\n" RESET);
	printf(BRIGHT_YELLOW "hello world\n" RESET);
	printf(BRIGHT_BLUE "hello world\n" RESET);
	printf(BRIGHT_PURPLE "hello world\n" RESET);
	printf(BRIGHT_CYAN "hello world\n" RESET);
	printf(RESET);
	return 0;
}
