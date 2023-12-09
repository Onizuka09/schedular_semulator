//
// Created by amani on 05/12/23.
//



int calculate_simulation_time(node *head)
{
	int total_t = 0;
	node *n;
	Process p;
	n = head;
	while (n != NULL)
	{
		p = n->proc;
		if (total_t < p.ta)
		{
			total_t = p.ta;
		}
		total_t += p.te;
		n = n->next;
	}
	//free(n);
	return total_t;
}




int main() {

    int qtm , nb_proc=0;
    printf("Quantum value ? ");
    scanf("%d", &qtm);
     /* n7awel nhotha fel for loop*/
    node *tmp;
    node *Head =NULL;
    Process p ;
    int color; 

    // Open the CSV file for reading
    FILE *fpt;
    fpt = fopen("file_manipulation/File.csv", "r");
    if (fpt == NULL) {
        fprintf(stderr, "Error opening the file.\n");
        return 1;
    }

// Read the header line from the CSV file
    char buffer[100];
    fgets(buffer, sizeof(buffer), fpt);

    // Read the remaining lines from the CSV file
    while (fgets(buffer, sizeof(buffer), fpt) != NULL) {
        
        // Parse the CSV line
        if (sscanf(buffer, "%19[^,], %d, %d, %d,%d", p.name, &p.te, &p.ta, &p.priority,&color) == 5) {
            // Create a new node and insert it into the linked list
            p.color = intToColor(color);
            tmp=create_new_node(p);
            insert_at_head(&Head, tmp);
            nb_proc++;
            
        }
    }

printf("nbr proc: %d\n", nb_proc);
printTable_linkedList(Head,0);
linkedlist_bubbleSort(&Head,nb_proc);
printf("\nlinked list loula sorted by ta\n");
printlist(Head);

int curs = Head->proc.ta,c_time=0,wait_time=0;
int P;


    node *tmp2;
    node *Head2 =NULL;
    int l2=0;
    bool b = true;
    int total_t = calculate_simulation_time(Head);
    queue  QR;
    bool b2=true;
    bool b3 = false;

    //lahne yabda multilevel

while ( curs < total_t){
    printf(" curs = %d",curs);
    printf("\n");

     while ((Head != NULL) && (b==true)) {
        if (Head->proc.ta <= curs) {
            node* tmp2 = create_new_node(Head->proc);
            insert_at_head(&Head2, tmp2);
            l2++;
            Head = Head->next;
        }   
        else{ b=false;}
    }
    

    linkedlist_bubbleSortpriority(&Head2,l2);
    printf("wait list : \n");
    printlist(Head2);

//lazem na3mel parcours 3al wait list w nchouf les processus ily andhom nafs prieority m3a el process loul w n7othom fel queue QR


     while(Head2!=NULL && b2){
    P= Head2->proc.priority;
    if ( Head2->next->proc.priority==P){
        enqueue(&QR,&Head2->proc);
        Head2=Head2->next;
        b3=true;
    }
    else{b2=false;}

    }
    //nexicuty awl wahda mel qr
    if (b3){
        //nexicuty awl wahda mel qr
        curs++;
    }
    else {
        //nexicuty awl process fel waitlist 
    Head2->proc.te--;
    printf("\n process  %s",Head2->proc.name);
    printf(" is exucuting for 1 unit\n");

    curs++;
    b=true;
    if (Head2->proc.te==0){
        printf("\n process %s " , Head2->proc.name);
        printf(" is terminated");
        Head2=Head2->next;
        l2--;

    }

    }




    
    
    
}
 

    
    
}




