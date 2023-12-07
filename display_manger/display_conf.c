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
	int max_ch = (floor(quotion) +1 )*total_time;
	// printf("%d", max_ch);
	return max_ch;
}

void pick_color(colors color, char* ch_color) {
	switch (color)
	{
		case E_RESET_C:
			strcpy(ch_color, RESET);
			break;

		case E_BLACK_C:
			strcpy(ch_color, BLACK);
			break;
		
		case E_GREY_C:
			strcpy(ch_color, GREY);
			break;
		
		case E_RED_C:
			strcpy(ch_color, RED);
			break;

		case E_GREEN_C:
			strcpy(ch_color, GREEN);
			break;

		case E_YELLOW_C:
			strcpy(ch_color, YELLOW);
			break;

		case E_BLUE_C:
			strcpy(ch_color, BLUE);
			break;

		case E_PURPLE_C:
			strcpy(ch_color, PURPLE);
			break;

		case E_CYAN_C:
			strcpy(ch_color, CYAN);
			break;

		case E_BRIGHT_GREY_C:
			strcpy(ch_color, BRIGHT_GREY);
			break;

		case E_BRIGHT_RED_C:
			strcpy(ch_color, BRIGHT_RED);
			break;

		case E_BRIGHT_GREEN_C:
			strcpy(ch_color, BRIGHT_GREEN);
			break;

		case E_BRIGHT_YELLOW_C:
			strcpy(ch_color, BRIGHT_YELLOW);
			break;

		case E_BRIGHT_BLUE_C:
			strcpy(ch_color, BRIGHT_BLUE);
			break;

		case E_BRIGHT_PURPLE_C:
			strcpy(ch_color, BRIGHT_PURPLE);
			break;

		case E_BRIGHT_CYAN_C:
			strcpy(ch_color, BRIGHT_CYAN);
			break;

		default  :
			strcpy(ch_color, RESET);
		break;
	}



}

colors intToColor(int value) {
    switch (value) {
        case 1:
            return E_BLACK_C;
        case 2:
            return E_GREY_C;
        case 3:
            return E_RED_C;
		case 4:
			return E_GREEN_C;
		case 5:
			return E_YELLOW_C;
		case 6:
			return E_BLUE_C;
		case 7:
			return E_BLUE_C;
		case 8:
			return E_CYAN_C;
		case 9:
			return E_BRIGHT_GREY_C;
		case 10:
			return E_BRIGHT_RED_C;
		case 11:
			return E_BRIGHT_GREEN_C;
		case 12:
			return E_BRIGHT_YELLOW_C;
		case 13:
			return E_BRIGHT_BLUE_C;
		case 14:
			return E_BRIGHT_PURPLE_C;
		case 15:
			return E_BRIGHT_CYAN_C;
		default:
			return E_BLACK_C;
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

	printf(RESET"] %d%% done\n",p_ct);
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
    
