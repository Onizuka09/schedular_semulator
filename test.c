#include <stdio.h>
//num_line = (nb_proc + 1) *2 
//num_col = (num_titles+1)*2
//
void draw_devider() 
{
}
int main() 
{

int total_x=4;	
for (int temp = 1; temp <= total_x*4+6; temp++) {
    if (temp==5)
        printf("+");
    printf("-");
}
printf("\n");

	return 0; 
}


