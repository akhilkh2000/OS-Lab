#include <pthread.h>
#include <stdio.h>
#include<unistd.h>
#define BUFFER_SIZE 3

int buffer[BUFFER_SIZE];
int in, out;

void *Producer()
{
	int next_produced = 1;
	while (1)
	{

		printf("Job %d started\n", next_produced);
		next_produced++;
		while (((in + 1) % BUFFER_SIZE) == out)
			;
		buffer[in] = next_produced;
		in = (in + 1) % BUFFER_SIZE;
		sleep(1);
	}
}

void *Consumer()
{
	int next_consumed;
	while (1)
	{
		while (in == out)
			;
		next_consumed = buffer[out];
		out = (out + 1) % BUFFER_SIZE;
		printf("Job %d finished\n", next_consumed);
		sleep(1);
	}
}

int main()
{
	pthread_t producer_thread_id, consumer_thread_id;
	pthread_create(&producer_thread_id, NULL, Producer, NULL);
	pthread_create(&consumer_thread_id, NULL, Consumer, NULL);
	pthread_join(producer_thread_id, NULL);
	pthread_join(consumer_thread_id, NULL);
	return 0;
}