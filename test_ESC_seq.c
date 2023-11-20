#include <stdio.h>

#define ESC "\033"
#define CSI "[" 
#define backspace "D"

int main() {
   printf("hello world");
     // Move cursor back by 4 positions
    //printf("\033[K") ; 
     printf(ESC CSI "%d" backspace "\033[K",0);   
fflush(stdout);
char *s= "################################";
int chas = sizeof(s)*;
printf("%d\n",chas);
    return 0;
}
