#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    printf("Running fake utility: 'Cool System Info Tool'\n");
    printf("Analyzing your system... this may take a moment.\n");
    
    // Set a delay
    sleep(5);
    
    // Perform the annoying, but harmless, action
    // In this case, repeatedly open a new terminal window
    for (int i = 0; i < 5; i++) {
        system("gnome-terminal &");
        // For other desktop environments, use xterm, konsole, etc.
    }
    
    printf("Analysis complete. An unexpected issue occurred. Closing.\n");
    return 0;
}

