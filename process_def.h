#ifndef PROC_CONFIG_H
#define PROC_CONFIG_H

#define RED_TEXT    "\x1b[31m"
#define GREEN_TEXT  "\x1b[32m"
#define YELLOW_TEXT "\x1b[33m"
#define RESET_TEXT  "\x1b[0m"


typedef enum {
	green,
	yellow,
	red,
	reset,
}colors;

typedef struct { 
	int ta; 
	int te; 
	int priority; 
	char name[10] ;
	colors color;

}process_settings;

#endif 

