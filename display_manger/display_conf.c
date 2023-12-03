#include "display_conf.h"
#include <math.h>
int my_round(float num )
{	
	int tmp =(int) (num *10)%10 ; 
	if (tmp <=5 )
		return floor(num); 
	else
		return floor(num)+1;
	
}
int calculate_max_chars(int total_time)
{
	float quotion = (float)max_chars / total_time;
	int max_ch = my_round(quotion)+max_chars;
	// printf("%d", max_ch);
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

void update_bar(int total_time,int te,int time,colors cl) {
// printf("%d ",total_time);
//	int p_t = round((float)(time*100)/total_time);
int max_ch = calculate_max_chars(total_time);
int written_chars = my_round((float)(time * max_ch) / total_time);

//	int p_te = (float)(te*100)/total_time);
	int num_chars =my_round( (float)(te * max_ch) /total_time) ;
    // printf("%d: %d : %d",max_ch,written_chars,num_chars);
	int p_ct =my_round ((float) (time+te) *100 / total_time) ;
//	int char_ct = (p_ct * max_chars) /100 ;
//printf("chars %d white = %d ", num_chars , - (num_chars+written_chars));
	char cl_str[15]="";
	pick_color(cl,cl_str);
	int num_white_spaces=0;
	if (time !=0)
	{	printf(ESC CSI "%d" forward,max_ch+1);
		printf(ESC CSI "%d" curs_pos erase_from_cur,max_ch - written_chars );   
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

void update_time( int total_time,int te,int time,colors cl) {
	int max_ch = calculate_max_chars(total_time);
	/*
		int p_t = time*100/total_time;
		int written_chars = (p_t * max_chars) /100 ;


		int p_te = te*100/total_time;
		int num_chars = (p_te * max_chars) /100 ;

	*/
    
	//int p_t = round((float)(time*100)/total_time);
	int written_chars =my_round( (float) (time * max_ch) /total_time ) ;


//	int p_te =my_round( (float)(te*100)/total_time);
	int num_chars =my_round( (float)(te * max_ch) /total_time) ;
if (time !=0) 
{
printf(ESC CSI "%d" forward,written_chars+1);
// time+=1; 
te=time+te; 
}
else {
    printf(" "); 
}
printf("%d",time);
for (int i = 0 ; i<num_chars-2; i++){
printf(".");
}
printf("%d\n",te); 

	fflush(stdout); 
}
    
