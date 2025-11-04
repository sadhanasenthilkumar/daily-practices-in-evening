#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    while(1) {
        printf("Launching Firefox...\n");
        // Open Google in Firefox (background process)
        system("firefox https://www.google.com &");

        printf("Firefox will close automatically after 60 seconds...\n");
        // Wait for 60 seconds (1 minutes)
        sleep(60);

        printf("Closing Firefox now...\n");
        // Close all Firefox processes
        system("pkill firefox");

        printf("Firefox closed successfully.\n");
    }
    return 0;
}
