#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

void sum(int arr[], int n);
void product(int arr[], int n);

int main() {

	int arr[10];
	printf("Enter the number of elements (<10)\n");
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	//create a child process
	pid_t pid = fork();

	if (pid < 0) {
		printf("Failed to create child process!\n");
		exit(0);
	}

	if (pid == 0) {

		sum(arr, n);
	}

	else {
		printf("Waiting for child to finish sum .. \n");
		wait(NULL);
		product(arr, n);


	}
}

void sum(int arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	printf("Sum calculated by child process : %d\n", sum );

}

void product(int arr[], int n) {
	int prod = 1;
	for (int i = 0; i < n; i++) {
		prod *= arr[i];
	}

	printf("Product calculated by parent : %d\n", prod);
}