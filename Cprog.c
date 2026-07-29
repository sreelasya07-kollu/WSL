/*Develop a C program that demonstrates how a Linuxoperating system executes a command entered by a user that1. Accept a Linux command as input. 2. Create a childprocess using fork(). 3. Execute the command in the childprocess using an appropriate exec() system call. 4. Allow theparent process to wait for the child using wait (). 5. Displaythe Process ID (PID) of both parent and child processes.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {

    // Declare a variable to store the Linux command
    char command[100];

    // Accept Linux command from the user
    printf("Enter Linux command: ");
    scanf("%99s", command);

    // Create a child process
    pid_t pid = fork();

    // Check if fork() failed
    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }

    // Child process
    if (pid == 0) {
        printf("Child Process\n");
        printf("Child PID: %d\n", getpid());

        // Execute the Linux command
        execlp(command, command, NULL);

        // Display an error if execution fails
        printf("Command execution failed!\n");
        exit(1);
    }

    // Parent process
    else {
        printf("Parent Process\n");
        printf("Parent PID: %d\n", getpid());

        // Wait for the child process to complete
        wait(NULL);

        printf("Child process completed.\n");
    }

    // End of the program
    return 0;
}