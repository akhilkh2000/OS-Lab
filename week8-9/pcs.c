#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#define BUFFER_SIZE 10

void *producer();
void *consumer();
sem_t empty, full ,lock; //init the semaphores
int buffer[BUFFER_SIZE]; //shared buffer

int in=0;int out=0;int count=0;
int main()
{
	sem_init(&lock,0,1); //(semaphore,pshared,value_to_assign). pshared - 0 (threads share data)
									  // -1 (processes share data)
	sem_init(&full,0,0); //number of slots filled , in start 0
	sem_init(&empty,0,BUFFER_SIZE); //empty init to BUFFER_SIZE indicates how many slots are empty 
	
	pthread_t thread1,thread2;
	
	pthread_create(&thread1,NULL,producer,NULL);
	pthread_create(&thread2,NULL,consumer,NULL);
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	exit(0);
}
void *producer()
{
	do{
		sem_wait(&empty); // producer cannot enter critical section when buffer is full (empty = 0)
		sem_wait(&lock); //used to provide mutual exclusion
		
		buffer[in]=in+1;
		printf("Producer : produced item %d\n",in+1);
		in=(in+1)%BUFFER_SIZE;
		count++;
		sem_post(&lock); //(unlock or signal while leaving critical section)
		sem_post(&full); // signal to consumer that buffer has some data (full will get incremented)
	}while(count<BUFFER_SIZE);
}
void *consumer()
{
	int item;
	do{
		sem_wait(&full); // wait / sleep when the buffer is empty or full = 0
		sem_wait(&lock);// mutual exclusion
		
		item=buffer[out];
		printf("Consumer : consumed item %d\n",item);
		out=(out+1)%BUFFER_SIZE;
		count--;
		sem_post(&lock);	//unlock while leaving critical section
		sem_post(&empty); // as it reads the buffer becomes more emptier it increments empty
		}while(count>0);	
		
}

