#include <stdio.h>
#include <stdlib.h> // Required for the system() function

int main() {
    printf("Attempting to shut down the system...\n");

    // Execute the 'shutdown -P now' command to power off the system immediately
    // -P or --poweroff option ensures the system powers down
    // 'now' specifies immediate execution
    int status = system("shutdown -P now");

    // Check the return status of the system() call (optional but good practice)
    if (status == -1) {
        perror("Error executing shutdown command");
    } else if (status != 0) {
        printf("Shutdown command returned non-zero status: %d\n", status);
        printf("This might indicate a permission issue or command failure.\n");
    }

    printf("If the system does not shut down, you might need root privileges.\n");

    return 0;
}
