#include <stdio.h>
#include <ctype.h>
#include <clock.h>
#define SLOTX 6
#define CYCLEX 2
#define SLOT_T 5000

//extern void wakeup(void);
//syscall resched(void);
//restore_intr(void *);
//void clockinit(void);
//clockintr(void);
int tps,cycle=0,slot=0;

long int now , then; 
//clocktime = now;
//ulong hi = QUANTUM.clocktime;

void one() {
  printf("Task 1 running\n");
  sleep(1000);
}


void two() {
  printf("Task 2 running\n");
  sleep(1000);
}

void three() {
  printf("Task 3 running\n");
  sleep(1000);
}


/*void burn() {
 *   
 *     clock_t bstart = times(&n);
 *       
 *
 *         while ((( now = times(&n)) - then) < SLOT_T * tps / 1000) {
 *            
 *              }
 *
 *                printf (" brn time = %2.2dms\n\n", (times(&n)-bstart)*1000/tps);
 *                	  then = now;
 *                	  	  cycle = CYCLEX;
 *                	  	  	  }*/
void burn() { printf (" brn cycle \n ");}

void (*ttable[SLOTX][CYCLEX])() = {
{one, one},
{three, two},
{one, one},
{two, burn},
{one, one},
{burn,burn}};
 
command xsh_schedule(ushort stdout, ushort stdin, ushort stderr, ushort nargs, char *args[]) {
//clocktime now, then;
now = clocktime;
    tps = 100;
    printf("clock ticks/sec = %d\n\n", tps);
//    then = void clock_update(&n);
    while (1) {
      printf(" \n Starting a new hyperperiod \n");
      for (slot=0; slot <SLOTX; slot++)
        { printf ("\n Starting a new frame \n");
	for (cycle=0; cycle<CYCLEX; cycle++)
	  (*ttable[slot][cycle])();
	}}
  }        

