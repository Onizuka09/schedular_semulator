#ifndef NODE_H
#define NODE_H 
#include "../process_def.h"
typedef struct
{
    Process proc ;
    struct node* next   ;
}node;

#endif