    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int main() {
        FILE *fp;
        char buffer[1024];
        char command[] = "speedtest-cli --simple"; // Use --simple for concise output

        // Open the command for reading
        fp = popen(command, "r");
        if (fp == NULL) {
            perror("Failed to run command");
            return 1;
        }

        // Read the output line by line
        printf("Internet Speed Test Results:\n");
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            printf("%s", buffer);
        }

        // Close the file pointer
        pclose(fp);

        return 0;
    }
