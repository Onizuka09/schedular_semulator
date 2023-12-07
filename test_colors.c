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

int main(void)
{
	int i, j, n;
// printf("")
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
