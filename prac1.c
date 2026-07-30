#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
int main() {
    char command[100];
    // Step 1: Accept a Linux command from the user
    printf("Enter a Linux command: ");
    fgets(command, sizeof(command), stdin);
    // Remove the newline character
    command[strcspn(command, "\n")] = '\0';
    // Step 2: Create a child process
    pid_t pid = fork();
    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        // Child Process
        printf("\n--- Child Process ---\n");
        printf("Child PID  : %d\n", getpid());
        printf("Parent PID : %d\n", getppid());
        printf("Executing command: %s\n\n", command);

        // Step 3: Execute the Linux command
        execl("/bin/sh", "sh", "-c", command, (char *)NULL);
        // This line executes only if exec() fails
        perror("exec failed");
        exit(EXIT_FAILURE);
    }
    else {
        // Parent Process
        printf("\n--- Parent Process ---\n");
        printf("Parent PID : %d\n", getpid());
        printf("Child PID  : %d\n", pid);
        // Step 4: Wait for the child process
        wait(NULL);
        printf("\nChild process has finished execution.\n");
    }
    return 0;
}
