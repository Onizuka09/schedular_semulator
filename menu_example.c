#include <stdio.h>

void printMenu()
{
printf("Welocome to process simultion app\n") ;
printf("\n"); 

printf("Please enter a number from 1..10 to select a functionanlity :) \n"); 
printf("\t1: item1\n"); 
printf("\t2: item2\n");
printf("\t2: item3\n");
printf("\t3: item4\n");
printf("\t4: item5\n");
printf("\t5: item6\n");
printf("\t6: exit\n");
}

int main() 
{	int x ;
do {
start:	printMenu(); 
	printf("Enter a num: ") ; 
	scanf("%d",&x);
	if ( x<1 || x > 7) 
	{
		printf(" you ever entered a wrong choice \nPlease enter a choice form 1..6 \n") ; 
		goto start; 
	} 
	switch (x) {
 	case 1:
		printf("Choice 1"); 
 		//TARGET
 		break;	
	case 2:
 		printf("Choice 2");		//TARGET
 		break;
	case 3:
		printf("Choice 3");//TARGET
 		break;
	case 4:
		printf("Choice 4");//TARGET
 		break;
	case 5:
		printf("Choice 5");//TARGET
 		break;

	case 6:
		printf("Choice 6");
 		break;

	case 7:
		printf("Choice 7");	//TARGET
 		break;
	default:
		printf("Choice 1");	// choice 
		//
		break;
 } 



}while (x!=6) ; 
printf("exited successfully \nThank you \n"); 
return 0;		
}
