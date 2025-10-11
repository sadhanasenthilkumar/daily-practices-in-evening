#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h> // For perror

int main() {
    int fd_console;

    // Open the console device
    fd_console = open("/dev/console", O_WRONLY);
    if (fd_console == -1) {
        perror("Error opening console device");
        return 1;
    }

    // Turn Num Lock ON
    // The 0x4B32 is the KDSETLED ioctl command for setting keyboard LEDs.
    // The 0x02 is the LED_NUML flag for the Num Lock LED.
    if (ioctl(fd_console, 0x4B32, 0x02) == -1) {
        perror("Error setting Num Lock ON");
        close(fd_console);
        return 1;
    }
    printf("Num Lock ON\n");
    sleep(2); // Wait for 2 seconds

    // Turn Num Lock OFF
    // To turn off, pass 0x00, which means no LEDs are set.
    if (ioctl(fd_console, 0x4B32, 0x00) == -1) {
        perror("Error setting Num Lock OFF");
        close(fd_console);
        return 1;
    }
    printf("Num Lock OFF\n");
    sleep(2); // Wait for 2 seconds

    // Turn Num Lock ON again
    if (ioctl(fd_console, 0x4B32, 0x02) == -1) {
        perror("Error setting Num Lock ON again");
        close(fd_console);
        return 1;
    }
    printf("Num Lock ON again\n");

    // Close the console device
    close(fd_console);

    return 0;
}














