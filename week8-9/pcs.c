#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#define BUFFER_SIZE 10

void *producer();
void *consumer();
sem_t empty, full ,lock;
int buffer[BUFFER_SIZE];

int in=0;int out=0;int count=0;
int main()
{
	sem_init(&lock,0,1);
	sem_init(&full,0,0);
	sem_init(&empty,0,BUFFER_SIZE);
	
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
		sem_wait(&empty);
		sem_wait(&lock);
		
		buffer[in]=in+1;
		printf("Producer : produced item %d\n",in+1);
		in=(in+1)%BUFFER_SIZE;
		count++;
		sem_post(&lock);
		sem_post(&full);
	}while(count<BUFFER_SIZE);
}
void *consumer()
{
	int item;
	do{
		sem_wait(&full);
		sem_wait(&lock);
		
		item=buffer[out];
		printf("Consumer : consumed item %d\n",item);
		out=(out+1)%BUFFER_SIZE;
		count--;
		sem_post(&lock);	
		sem_post(&empty);
		}while(count>0);	
		
}

