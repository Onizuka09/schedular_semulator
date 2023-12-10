  #include "linkedlist.h"

  #include <stdio.h>
  #include<stdlib.h>
node *create_new_node(Process value){
        node *result = malloc(sizeof(node));
        result->proc = value;
        result->next =NULL;
        return result;
}

node *create_new_node_new(Process *value){
        node *result = malloc(sizeof(node));
        result->proc = *value;
        result->next =NULL;
        return result;
}
node *insert_at_head(node **head, node *node_to_insert){
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}
void printlist(node *head){
    node *temporary = head;
    while (temporary !=NULL){
        //printf("%d -" , temporary->value.Arrival_date);
        printf("%d - ", temporary->proc.ta);
        temporary = temporary->next;
    }
    printf("\n");
}
//***********************************************************
// sort list
/*Function to swap the nodes */
static  node* swap( node* ptr1,  node* ptr2)
{
     node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

/* Function to sort the list */
int linkedlist_bubbleSort( node** head, int count)
{
     node** h;
    int i, j, swapped;

    for (i = 0; i <= count; i++) {

        h = head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++) {

             node* p1 = *h;
             node* p2 = p1->next;

            if (p1->proc.ta > p2->proc.ta) {

                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }

        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
     return 0;
}


/* Function to sort the list */
int linkedlist_bubbleSortpriority( node** head, int count)
{
     node** h;
    int i, j, swapped;

    for (i = 0; i <= count; i++) {

        h = head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++) {

             node* p1 = *h;
             node* p2 = p1->next;

            if (p1->proc.priority < p2->proc.priority) {

                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }
            else if (p1->proc.priority == p2->proc.priority){
                if (p1->proc.ta > p2->proc.ta) {

                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }

            }

            h = &(*h)->next;
        }

        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
     return 0;
}




int temps_rotation( int tf,int ta){
return tf-ta;
}


int temps_attente(int tf , int ta, int te ){
    int tr = temps_rotation(  tf, ta);
return tr-te;
}
 
 int MOY_TR(int tf,int ta ,int nbr){
 int mtr=0;
   float moyenne_tr;
 for(int i=0, i<nbr ,i++){
//read tf 
//read ta 
mtr+= temps_rotation(  tf, ta);


}
moyenne_tr= mtr/nbr;
return moyenne_tr;



 }

 int MOY_TA(int tf , int ta, int te ,int nbr){
   int mta=0;
   float moyenne_ta;
for(int i=0, i<nbr ,i++){
//read tf 
//read ta 
// read te 
mta+= temps_attente(  tf, ta,te);


}
moyenne_ta= mta/nbr;
return moyenne_ta;


 }