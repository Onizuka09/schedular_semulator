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
#define backspace "D" 
#define forward "C"
#define num_bars 1



void pick_color(colors color, char* ch_color) ;
colors intToColor(int value); 
void update_bar(int total_time,int current_time,int te,int time,colors cl); 
void update_time( int total_time,int current_time,int te,int time,colors cl) ;

/*-----------------------------------------------------------*/


#endif 
