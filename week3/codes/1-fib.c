#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main() {

	int first = 0 , second = 1, next = first + second;
	int n;

	printf("\nEnter the limit of fibinacci : ");
	fflush(stdout);
	scanf("%d", &n);
	//creates new child process
	pid_t pid = fork();

	if (pid < 0) {
		printf("Failed to create child process!\n");
		exit(0);
	}

	if (pid == 0) {
		// it is a child process

		printf("Fib sequence is being generated in child process .. \n\n");
		printf("%d %d ", first, second);
		n -= 2;
		while (n) {
			next = first + second;
			printf("%d ", next);
			first = second;
			second = next;
			n--;
			if (n == 0)
				printf("\n Child process finished execution!");
		}

	}
	else {

		//wait for child
		wait(NULL);

		printf("\nParent process ended after waiting for child !\n");
	}

	return 0;


}