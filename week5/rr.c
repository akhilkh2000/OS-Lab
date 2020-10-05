#include <stdio.h>
#include<stdbool.h>

void runAllProcesses(int processes[], int n, int bt[], int wt[], int quantum) {
	int temp[n];
	for (int i = 0; i < n; i++)
		temp[i] = bt[i];
	int t = 0;
	while (1) {
		bool finished = true; //all processes done
		for (int i = 0; i < n; i++) {
			if (temp[i] > 0) {
				finished = false;
				if (temp[i] > quantum) {
					t += quantum; //total time
					temp[i] =  temp[i] - quantum; // subtract one quantum from burst
				}
				else {
					t = t + temp[i];
					wt[i] = t - bt[i]; //wait time for the process when its finished
					temp[i] = 0; //set its remaining time to 0 as it s done
				}
			}
		}

		//if after  full cycle all processes are done we exit
		if (finished == true)
			break;


	}
}

void calcTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
	for (int i = 0; i < n; i++) {
		tat[i] = wt[i] + bt[i];
	}
}


void roundRobin(int processes[], int n, int bt[], int quantum) {
	int wt[n], tat[n], totalWaitTime = 0, totalTurnAroundTime = 0;
	runAllProcesses(processes, n, bt, wt, quantum);
	calcTurnAroundTime(processes, n, bt, wt, tat);
	printf("Processes  Burst Time  Waiting Time  Turnaround Time\n");
	for (int i = 0; i < n; i++) {
		totalWaitTime += wt[i];
		totalTurnAroundTime += tat[i];
		printf("%d\t   %d\t\t%d\t      %d\n", i + 1, bt[i], wt[i], tat[i]);

	}

	printf("Average waiting time = %f", (float)totalWaitTime / n);
	printf("\nAverage turnaround time = %f\n", (float)totalWaitTime / n);


}

int main() {
	int processes[200];
	int n;
	int burst_time[200];
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Enter process number: ");
		scanf("%d", &processes[i]);
		printf("Enter burst time : ");
		scanf("%d", &burst_time[i]);
	}

	int quantum;
	printf("\nEnter the quantum: ");
	scanf("%d", &quantum);
	roundRobin(processes, n, burst_time, quantum);
	return 0;

}
