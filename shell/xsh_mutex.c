#include <kernel.h>
#include <semaphore.h>
#include <stdio.h>
#include <tty.h>
#include <string.h>



#define INITSTK 1024
#define INITPRIO 20
void proc1();
void proc2();
void proc3();

semaphore synch12;
semaphore synch23;
semaphore synch31;
int counter = 0;

unsigned short lfsr = 0xACE1u;
unsigned bit;
unsigned rand()
  {
    bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
    return lfsr =  (lfsr >> 1) | (bit << 15);
  }
command xsh_mutex(ushort stdin, ushort stdout, ushort stderr,
                 ushort nargs, char *args[])
{
        synch12 = newsem(0);
        synch23 = newsem(0);
        synch31 = newsem(1);

        ready(create((void *)proc1, INITSTK, INITPRIO, "PROC1", 2, 0, NULL), RESCHED_NO);
        ready(create((void *)proc2, INITSTK, INITPRIO, "PROC2", 2, 0, NULL), RESCHED_NO);
        ready(create((void *)proc3, INITSTK, INITPRIO, "PROC3", 2, 0, NULL), RESCHED_NO);
        counter = 0;
	return OK;
}

void proc1(){
        while(counter < 50){
                sleep(rand()/200);
                wait(synch31);
                counter++;
                printf("\nNow in proc1, the count is %d\n", counter);
                signal(synch12);
		if(counter > 50){counter=0;}
        }
}
void proc2(){
        while(counter < 50){
                sleep(rand()/100);
                wait(synch12);
                counter++;
                printf("\nNow in proc2, the count is %d\n", counter);
                signal(synch23);
		if(counter > 50){ counter = 0;}
        }
}
void proc3(){
        while(counter < 50){
                sleep(rand()/300);
                wait(synch23);
                counter++;
                printf("\nNow in proc3, the count is %d\n", counter);
                signal(synch31);
		if(counter>50){counter=0;}
        }
}
