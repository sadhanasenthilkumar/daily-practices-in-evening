#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

// Function to get single character input without Enter
char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0) perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0) perror("tcsetattr ~ICANON");
    return buf;
}

int main() {
    char current = '\0';
    char previous = '\0';

    system("clear");
    printf("=== Simple Letter Drop Editor ===\n");
    printf("Type letters; press 'q' to quit.\n\n");

    while (1) {
        current = getch();  // get a single letter

        if (current == 'q') break;

        // clear screen and reprint layout
        system("clear");
        printf("=== Simple Letter Drop Editor ===\n");
        printf("Type letters; press 'q' to quit.\n\n");

        printf("Typing Area: [%c]\n", current);

        // move cursor down for "falling" effect
        printf("\nFallen Letters:\n");

        // print previous letters below
        if (previous != '\0')
            printf("%c\n", previous);

        previous = current;  // make current letter become previous
        fflush(stdout);
    }

    printf("\nExiting...\n");
    return 0;
}

