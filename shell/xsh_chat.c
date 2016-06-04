#include <kernel.h>
#include <device.h>
#include <stdlib.h>
#include <shell.h>
#include <stdio.h>
#include <string.h>
#include <tty.h>

_Bool chatstatus = 1;
char * accounts[3] = {"admin" , "user" , "randomguy"};
char * pwds[3] = {"xp1", "xp2" , "xp3"};
int i =0 ;
char input_id[];
char input_pwd[];
char logout[] = "logout";
char line1[15];



command xsh_chat(ushort stdout, ushort stdin, ushort stderr, ushort nargs, char *args[]){

	fprintf(stdout, "Enter your ID :");
	read(stdin, input_id, 30);
	fprintf(stdout, "Enter your password :");
	read(stdin, input_pwd, 30);
	

	for( i = 0; i < 2 ; i++){
		if(strncmp(accounts[i], input_id, 3) == 0 && strncmp(pwds[i], input_pwd, 3) == 0){
			fprintf(stdout, "\n--------------\n");
			fprintf(stdout, "log in sucess!!\n");
			fprintf(stdout, "---------------\n");
			fprintf(stdout, "Welcome %s !!!!! \n\n" , accounts[i]);
			fprintf(stdout, "Type logout to quit! \n\n");
			input_id[3]= '\0';
			chatstatus = 1;
			break;
		}
	}
		//fprintf(stdout,"%d",chatstatus);
	if ((chatstatus ==  0)){
		fprintf(stdout, "\n-------------\n");
		fprintf(stdout, "LOG IN FAILED\n");
		fprintf(stdout, "--------------\n\n");
}
else{
	//fprintf(stdout , "time to write the rest\n");
	//fprintf(stdout, " %d ", chatstatus);

	while(chatstatus ){
		//fprintf(stdout, " HELLO");
		if(stdin == CONSOLE){	
		//	fprintf(stdout, " HELLO1");
			read(stdin, line1, 30); 
			if(strncmp(line1, logout , 6) == 0){fprintf(stdout, "logging off!\n");fprintf(TTY1,"Admin has logged off :(\n"); chatstatus = 0 ; break;}
			fprintf(TTY1, "admin: %s", line1);
			//fprintf(CONSOLE,"admin: %s", line1);
			bzero(line1, sizeof(line1));
		}
		else if(stdin == TTY1){
		//	fprintf(stdout, " HELLO2");
			read(stdin,line1,30);
			if(strncmp(line1,logout, 6) == 0) {fprintf(stdout, "logging off!\n");fprintf(TTY0, "user has logged off :(\n");chatstatus = 0; break;}
			fprintf(TTY0, "user: %s", line1);
			//fprintf(CONSOLE, "user: %s" , line1);
			bzero(line1, sizeof(line1));
		}
	}
}
return OK;
}
