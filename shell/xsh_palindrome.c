/**
 * * @file xsh_echo.c
 * * @provides xsh_echo
 * *
 * * $Id$
 * */
/* Embedded XINU, Copyright (C) 2007. All rights reserved. */

#include <kernel.h>
#include <stdio.h>
#include <string.h>

/**
* Shell command checks for palindrome.
* @param stdin descriptor of input device
* @param stdout descriptor of output device
* @param stderr descriptor of error device
* @param args array of arguments
* @return OK for success, SYSERR for syntax error
*/

int length;
command xsh_palindrome(ushort stdout, ushort stdin, ushort stderr, ushort nargs, char *args[])
{

int counter,i = 0;
int flag = 1;

char stringarray[50];
strcpy(stringarray,args[1]);


	for (counter = 0; stringarray[counter]!= '\0'; counter++){
		length = length +1;
	}



/* Output help, if '--help' argument was supplied */
if (nargs == 2 && strncmp(args[1],"--help",6) == 0)
{
fprintf(stdout, "Usage: clear\n");
fprintf(stdout, "Clears the terminal.\n");
fprintf(stdout, "\t--help\t display this help and exit\n");
return SYSERR;
}


for (counter = 0; stringarray[counter] != '\0' && flag; counter++) {
       
        if (stringarray[counter] != stringarray[length-counter-1]){
            
	    	
	   
	    flag = 0;
	    break;
        }
    }
    if (flag) {
        printf("yes");
    }
    else {
        printf("no");
    }
	fprintf(stdout, "\n");	
length = 0;
flag = 1;
return OK;
}
