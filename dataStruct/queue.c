#include<stdio.h>
#include "queue.h"
#include<stdlib.h>
void init_queue (queue *q ) { 
	q->head = NULL ; 
	q->tail = NULL ;
} 


bool enqueue ( queue *q, Process *proc ) 
{ 
	node* nwnode = (node *)malloc( sizeof(node));
	if (nwnode == NULL ) 
		return false; 
	nwnode->proc = *proc ; 
	nwnode->next = NULL; 
	if ( q->tail == NULL && q->head == NULL) 
	{ 
		q->tail= q->head = nwnode ; 
		return true  ; 
	} 
	q->tail->next = nwnode ; 
	q->tail = nwnode ; 
	// if the lis is empty 

return  true;
} 
Process* dequeue ( queue *q) 
{	Process *proc = malloc(sizeof(Process));
	if (proc == NULL)
		return NULL; 

	if (q->head == NULL) return  NULL ;
	node  *tmp = q->head ; 
	*proc = tmp->proc; 
	if (q->tail == q->head ) 
		q->tail = q->head = NULL ;
	else { 
	q->head = q->head->next ; 
	}	
	free( tmp) ; 	

	return proc ;	
		 
}

void display(queue *q) {
    node *tmp = q->head;
    while (tmp != NULL) {
        printf("%d", tmp->proc.te);
        tmp = tmp->next;
        printf(" | ");
    }
}

static void swap(Process* a,Process* b)
{
	Process temp; 
	temp =*a; 
	*a=*b; 
	*b=temp;
}
void queue_bsort(queue *q)
{ 
	node *i,*j ; 

	//bool state=false;
//	i=q; 
//	j=i->nxt; 
	for (i=q->head;i!=NULL;i=i->next)
	{
	  for (j=i->next;j!=NULL;j=j->next)
	  {
		{
		  if (j->proc.ta < i->proc.ta)
		  	swap(&(j->proc), &(i->proc)); 
		}
	  }
	}

return; 
}


bool is_empty(queue* q) {
    return q->head == NULL;
}


// Fonction pour ajouter un processus à une file triée par priorité
queue *enfilerTrieeParPriorite(queue *f, Process p) {
    node *nouveauElement = (node *)malloc(sizeof(node));
    nouveauElement->proc = p;
    nouveauElement->next = NULL;

    if (f == NULL || f->head == NULL || p.priority > f->head->proc.priority) {
        // Cas spécial : le nouveau processus a une priorité plus élevée que tous les autres
        nouveauElement->next = f->head;
        f->head = nouveauElement;
    } else {
        node *courant = f->head;
        while (courant->next != NULL && p.priority <= courant->next->proc.priority) {
            courant = courant->next;
        }
        nouveauElement->next = courant->next;
        courant->next = nouveauElement;
    }

    return f;
}

// Fonction pour extraire les processus de la file initiale et les placer dans une autre file
queue *extraireParTempsEtPriorite(queue *f, int tempsActuel) {
    queue *fileExtraite = NULL;

    while (f != NULL && f->head != NULL && f->head->proc.ta <= tempsActuel) {
        Process processusCourant = f->head->proc;

        // Ajouter le processus à la file extraite triée par priorité
        fileExtraite = enfilerTrieeParPriorite(fileExtraite, processusCourant);

        // Supprimer le processus de la file initiale
        node *temp = f->head;
        f->head = f->head->next;
        free(temp);
    }

    return fileExtraite;
}

