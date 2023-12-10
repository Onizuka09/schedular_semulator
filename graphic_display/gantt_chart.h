#ifndef _AFFICHER_ 
#define _AFFICHER_
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#include "../dataStruct/queue.h"
#include "../process_def.h"
// #include <pthread.h>
#include <cairo/cairo.h>

typedef struct
{
    int red;
    int green;
    int blue;
} RGB;


void init_gtk(); 
void getRGB(colors col, RGB *rgb);
void create_widget(queue *q1,char *title);


#endif