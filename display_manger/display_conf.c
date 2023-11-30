#include "display_conf.h"
#include <math.h>

int calculate_max_chars(int total_time)
{
    int max_ch = round((float)(max_chars/total_time))+max_chars;	
	
return max_ch;
}

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

void update_bar(int total_time,int te,int time,colors cl,int max_ch) {
// printf("%d ",total_time);
//	int p_t = round((float)(time*100)/total_time);
	int written_chars =round( (float) (time * max_ch) /total_time ) ;


//	int p_te = (float)(te*100)/total_time);
	int num_chars =round( (float)(te * max_ch) /total_time) ;
    //printf("num chars %d",num_chars);
	int p_ct =round ((float) (time+te) *100 / total_time) ;
//	int char_ct = (p_ct * max_chars) /100 ;
//printf("chars %d white = %d ", num_chars , - (num_chars+written_chars));
	char cl_str[15]="";
	pick_color(cl,cl_str);
	int num_white_spaces=0;
	if (time !=0)
	{	printf(ESC CSI "%d" forward,max_ch+1);
		printf(ESC CSI "%d" curs_pos delete_from_cur,max_ch - written_chars );   
		fflush(stdout); 
		num_white_spaces=max_ch -( num_chars + written_chars );
        
	}
	else 
	{	num_white_spaces = max_ch - num_chars ;
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

void update_time( int total_time,int te,int time,colors cl,int max_ch) {

/* 
    int p_t = time*100/total_time;
	int written_chars = (p_t * max_chars) /100 ;


	int p_te = te*100/total_time;
	int num_chars = (p_te * max_chars) /100 ;

*/
    
	//int p_t = round((float)(time*100)/total_time);
	int written_chars =round( (float) (time * max_ch) /total_time ) ;


//	int p_te =round( (float)(te*100)/total_time);
	int num_chars =round( (float)(te * max_ch) /total_time) ;
if (time !=0) 
{
printf(ESC CSI "%d" forward,written_chars+2);
te=time+te; 
time+=1; 
}
else {
    printf(" "); 
}
printf("%d",time);
for (int i = 0 ; i<num_chars-1; i++){
printf(".");
}
printf("%d\n",te); 

	fflush(stdout); 
}
    
