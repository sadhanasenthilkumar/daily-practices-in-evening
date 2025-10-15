#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Create a new process
    pid = fork();

    // Check for fork() error
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    // This is the parent process. It exits to make the child process appear "resident".
    if (pid > 0) {
        printf("Parent process exiting. Child is now running in the background...\n");
        // Exit the parent process
        exit(0);
    }

    // The child process continues from here.
    // It is now a background process, like a resident virus.

    // Open a file to "infect" or write to
    FILE *fp;
    fp = fopen("resident_output.log", "a");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    // Close standard file descriptors to detach from the terminal
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // This is the "resident" loop. It runs indefinitely.
    while (1) {
        // Log the output to the file
        fprintf(fp, "Resident process is still active...\n");
        fflush(fp); // Flush the buffer to ensure the message is written immediately
        sleep(5);   // Wait for 5 seconds before repeating
    }

    // The following code is unreachable but included for completeness.
    fclose(fp);
    return 0;
}

