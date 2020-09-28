#include <stdio.h>

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
int main() {
	int burstTimes[20], proc[20], wait[20], turnAroundTime[20];
	int n, totalWaitTime = 0, totalTurnAroundTime = 0, pos;
	//avg wait time and turn around time
	float avg_wait, avg_tat;
	printf("\n****Shortest Job First****\n");
	printf("Enter number of jobs:  ");
	scanf("%d", &n);
	printf("\n");

	for (int i = 0; i < n; i++) {
		printf("Enter Burst Time of %d Process: ", i + 1);
		scanf("%d", &burstTimes[i]);
		proc[i] = i + 1; //each process has value index+1
		printf("\n");
	}

	//sort according to times
	for (int i = 0; i < n; i++) {
		//selection sort
		pos = i;
		for (int j = i + 1; j < n; j++) {
			if (burstTimes[j] < burstTimes[pos])
				pos = j;
		}

		if (pos != i) {
			swap(&burstTimes[i], &burstTimes[pos]);
			swap(&proc[i], &proc[pos]);
		}

	}

	wait[0] = 0; //first proces doesnt need to wait
	for (int i = 1; i < n; i++) {
		//current process waits for prev process's wait time + its burst time
		wait[i] = wait[i - 1] + burstTimes[i - 1];
		totalWaitTime += wait[i];
	}

	//average wait time
	avg_wait = (float)totalWaitTime / n;

	// printf("\nProcess\t  Burst Time    \tWaiting Time\tTurnaround Time");
	printf("Job \t Burst Time \t Waiting Time \t Turnaround Time\n");
	for (int i = 0; i < n; i++) {
		//turn around time
		turnAroundTime[i] = burstTimes[i] + wait[i];
		totalTurnAroundTime += turnAroundTime[i];
		printf("%d \t %d \t\t %d \t\t %d\n", proc[i], burstTimes[i], wait[i], turnAroundTime[i]);

	}

	avg_tat = (float)(totalTurnAroundTime) / n;
	printf("\n\n\t\tAverage Waiting Time = %f", avg_wait);
	printf("\n\t\tAverage Turnaround Time = %f\n", avg_tat);
	printf("\n");


}