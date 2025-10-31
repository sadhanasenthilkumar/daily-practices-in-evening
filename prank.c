






#include <stdio.h>
#include <stdlib.h> // for system() (optional, for clearing screen)
#include <time.h>   // for time() (optional, for random seed)

int main() {
    printf("This is a harmless joke program.\n");
    printf("To close, simply press Ctrl+C in the console window.\n");
    printf("Starting the 'prank' in 3 seconds...\n");
    // Simple delay
    for (int i = 3; i > 0; i--) {
        printf("%d...\n", i);
        fflush(stdout); // Ensure immediate printing
        // A simple, non-blocking delay is complex in standard C,
        // so we'll just busy-wait or use an OS-specific function
        // for a real program. For this example, we'll skip the actual wait.
    }

    while (1) {
        printf("The system is attack by the viruse\n");
        // Add a small sleep here in a real program to avoid high CPU usage.
    }

    return 0;
}

