
/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/02/2023 11:04:21 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int main()
{
printf("This is some text on the first line.\n");

    fflush(stdout);  // Flush the buffer to ensure the text is displayed before clearing the line
printf("\033[1F");
	printf("\033[0K");  // Escape sequence to clear the line

    fflush(stdout);  // Flush the buffer to ensure the text is displayed before clearing the line
    printf("This is new text on the cleared line.");
	return 0;
}



