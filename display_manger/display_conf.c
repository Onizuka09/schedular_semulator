#include "display_conf.h"

void pick_color(colors color, char* ch_color) {


    if (color == green)
        strcpy(ch_color, GREEN_TEXT);
    else if (color == red)
        strcpy(ch_color, RED_TEXT);
    else if (color == yellow)
        strcpy(ch_color, YELLOW_TEXT);
    else
        strcpy(ch_color, RESET_TEXT);
}

colors intToColor(int value) {
    switch (value) {
        case 0:
            return green;
        case 1:
            return yellow;
        case 2:
            return red;
        default:
            return reset;
    }
}

void update_bar(int total_time,int te,int time,colors cl) {

	int p_t = time*100/total_time;
	int written_chars = (p_t * max_chars) /100 ;


	int p_te = te*100/total_time;
	int num_chars = (p_te * max_chars) /100 ;

	int p_ct = (time+te) *100 / total_time;
	int char_ct = (p_ct * max_chars) /100 ;

	char cl_str[15]="";
	pick_color(cl,cl_str);
	int num_white_spaces=0;
	if (time !=0)
	{	printf(ESC CSI "%d" forward,max_chars);
		printf(ESC CSI "%d" backspace "\033[K",max_chars - written_chars - 1);   
		fflush(stdout); 
		num_white_spaces=max_chars -( num_chars + written_chars );
	}
	else 
	{	num_white_spaces = max_chars - num_chars ;
		printf("[");
	}
	printf("%s",cl_str);
	for (int i = 0 ; i<num_chars ; ++i ) 
	{	
		printf("#");
	}
	
	for (int i = 0; i<num_white_spaces; ++i )
	{	 
		printf(" ");
	}

	printf(RESET_TEXT"] %d%% done\n",p_ct);
	fflush(stdout); 
}

void update_time( int total_time,int te,int time,colors cl) {

	int p_t = time*100/total_time;
	int written_chars = (p_t * max_chars) /100 ;


	int p_te = te*100/total_time;
	int num_chars = (p_te * max_chars) /100 ;


if (time !=0) 
{
printf(ESC CSI "%d" forward,written_chars+1);
te=time+te; 
time+=1; 
}
else {
    printf(" "); 
}
printf("%d",time);
for (int i = 0 ; i<num_chars-2; i++){
printf(".");
}
printf("%d",te); 

	fflush(stdout); 
}
    
