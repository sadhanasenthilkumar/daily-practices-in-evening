#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/statvfs.h>

#define PROC_MEMINFO "/proc/meminfo"

void display_ram_info() {
    FILE *meminfo_file = fopen(PROC_MEMINFO, "r");
    if (meminfo_file == NULL) {
        perror("Error opening /proc/meminfo");
        return;
    }

    long total_mem_kb = 0, free_mem_kb = 0;
    char line[256];

    while (fgets(line, sizeof(line), meminfo_file)) {
        if (sscanf(line, "MemTotal: %ld kB", &total_mem_kb) == 1) {
            // Found total memory, continue scanning for free memory
        } else if (sscanf(line, "MemAvailable: %ld kB", &free_mem_kb) == 1) {
            // Found available memory
        }
    }

    fclose(meminfo_file);

    if (total_mem_kb > 0) {
        long used_mem_kb = total_mem_kb - free_mem_kb;
        printf("--- RAM Information ---\n");
        printf("Total Physical Memory: %ld MB\n", total_mem_kb / 1024);
        printf("Used Physical Memory: %ld MB\n", used_mem_kb / 1024);
        printf("Free Physical Memory: %ld MB\n\n", free_mem_kb / 1024);
    } else {
        printf("Error reading RAM information from %s.\n\n", PROC_MEMINFO);
    }
}

void display_hard_disk_info() {
    // Check space for the root directory. Modify as needed.
    const char *mount_path = "/";
    struct statvfs vfs;

    if (statvfs(mount_path, &vfs) == 0) {
        unsigned long long total_space_gb = (unsigned long long)vfs.f_blocks * vfs.f_frsize / (1024 * 1024 * 1024);
        unsigned long long free_space_gb = (unsigned long long)vfs.f_bfree * vfs.f_frsize / (1024 * 1024 * 1024);
        unsigned long long used_space_gb = total_space_gb - free_space_gb;

        printf("--- Hard Disk Information (Mount Point: %s) ---\n", mount_path);
        printf("Total Disk Space: %llu GB\n", total_space_gb);
        printf("Used Disk Space: %llu GB\n", used_space_gb);
        printf("Free Disk Space: %llu GB\n\n", free_space_gb);
    } else {
        perror("Error retrieving hard disk information");
    }
}

int main() {
    display_ram_info();
    display_hard_disk_info();
    return 0;
}

