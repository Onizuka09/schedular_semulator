#ifndef DISPLAY_CON_H
#define  DISPLAY_CON_H
#include<stdio.h>
#include<string.h>
#include "../process_def.h"
#include "../dataStruct/queue.h"
#include "../process_config/global_config.h"
#define max_chars 60 //max num of '#'  

// ANSI escape sequences 

#define ESC "\033"
#define CSI "[" 
#define previousLine "F" 
#define curs_pos "D" 
#define forward "C"
#define num_bars 1
#define erase_in_line "K"
#define erase_from_cur ESC CSI erase_in_line
#define clear_line ESC CSI erase_in_line

void pick_color(colors color, char* ch_color) ;
colors intToColor(int value); 
void update_bar(int total_time,int te,int time,colors cl); 
void update_time( int total_time,int te,int time,colors cl) ;

void printTable(queue *q1, int num_proc);
void printTable_linkedList(node *head, int num_proc);
void printTable_view(Process *proc, int num_proc);
void printTable_metrics(queue *q, int num_proc);
/*-----------------------------------------------------------*/

#endif 

