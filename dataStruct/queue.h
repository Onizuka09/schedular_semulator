#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"
#include<stdbool.h>

typedef  struct { 
	node* head ; 
	node* tail ;
 } queue; 

void init_queue (queue *q );

bool enqueue ( queue *q, Process *proc ) ;

Process* dequeue ( queue *q) ;

// Déclaration de la fonction d'enfilement trié par priorité
queue *enfilerTrieeParPriorite(queue *f, Process p);

// Déclaration de la fonction d'extraction triée par temps et priorité
queue *extraireParTempsEtPriorite(queue *f, int tempsActuel);


// void swap(Process* a,Process* b);

void queue_bsort(queue *q);
void display(queue *q);
bool is_empty(queue* q); 
#endif /* ifndef  */
