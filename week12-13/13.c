#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int queue_t[25];
	int q_size, head, k, max_range, diff_t;
	int seek = 0;
	float avg;
	printf("Enter the maximum range of disk:");
	scanf("%d", &max_range);
	printf("Enter the size of queue request:");
	scanf("%d", &q_size);
	printf("Enter the list of disk positions to be read:");
	for (int i = 1; i <= q_size; i++)
	{
		scanf("%d", &queue_t[i]);
	}
	printf("Enter the initial head position:");
	scanf("%d", &head);
	queue_t[0] = head;
	for (int j = 0; j <= q_size - 1; j++)
	{
		diff_t = abs(queue_t[j + 1] - queue_t[j]);
		seek += diff_t;
		printf("Disk head moves from %d to %d with seek %d\n", queue_t[j], queue_t[j + 1], diff_t);
	}
	printf("Total seek time: %d\n", seek);
	avg = seek / (float)q_size;
	printf("Average seek time: %f\n", avg);
	return 0;
}
