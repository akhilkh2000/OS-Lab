#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char* argv[]) {

	pid_t pid;
	//create child process
	pid = fork();

	if (pid < 0) {
		printf("Failed to create child process!\n");
		exit(0);
	}

	if (pid == 0) {
		printf("Child process running ...\n" );
		//array to store executable of processes
		// so that we can call them using execvp()
		char* processes[] = {"./childexec", NULL};
		printf("Replacing child process with exec process!\n");
		execvp(processes[0], processes);
		/*We can also use other functions in exec family of functions
		to do similar switching of processes like execv()
		which takes the path of the file and has the prototype
		 -int execv(const char* path, *const arg v [ ] ) */


	}

	else {
		printf("Parent process waiting for child to finish...\n");
		wait(NULL);
		printf("Parent process finshed!\n");
	}

	return 0;
}