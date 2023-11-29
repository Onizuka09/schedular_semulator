#ifndef DISPLAY_CON_H
#define  DISPLAY_CON_H
#include<stdio.h>
#include<string.h>
#include "../process_def.h"

#define max_chars 50 //max num of '#'  

// ANSI escape sequences 

#define ESC "\033"
#define CSI "[" 
#define previousLine "F" 
#define curs_pos "D" 
#define forward "C"
#define num_bars 1
#define delete_line "k"
#define delete_from_cur ESC CSI delete_line



void pick_color(colors color, char* ch_color) ;
colors intToColor(int value); 
void update_bar(int total_time,int te,int time,colors cl,int max_ch); 
void update_time( int total_time,int te,int time,colors cl,int max_ch) ;

/*-----------------------------------------------------------*/


#endif 

