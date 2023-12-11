#ifndef NODE_H
#define NODE_H 
#include "../process_def.h"
typedef struct node
{
    Process proc ;
    struct node* next   ;
}node;
#endif