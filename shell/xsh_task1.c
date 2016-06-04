#include <kernel.h>
#include <proc.h>
#include <semaphore.h>
#include <stdio.h>

/*semaphore mutex1;
mutex1 = newsem(0);
int counter = 0;

int main(){
semaphore mutex1 = newsem(0);
int counter = 0;
return OK;
}

ready(create((void*)proc1,INITSTK,INITPRIO,"PROC1",2,0,NULL), RESCHED_NO);
ready(create((void*)proc2,INITSTK,INITPRIO,"PROC2",2,0,NULL), RESCHED_NO);
ready(create((void*)proc3,INITSTK,INITPRIO,"PROC3",2,0,NULL), RESCHED_NO);
*/
void proc(){
while(1){
	sleep(rand()%10);
	wait(mutex1);
	counter++;
	signal(mutex1);
	}
}

void proc2(){
while(1){
	sleep(rand()%10);
	wait(mutex1);
	counter++;
	signal(mutex1);
	}
}

void proc3(){
while(1){
	sleep(rand()%10);
	wait(mutex1);
	counter++;
	signal(mutex1);
	}
}

/*int main(){
semaphore mutex1 = newsem(1);
int counter = 0;
	proc1();
	proc2();
	proc3();
	print("%d",counter);
	return 0;
}*/
