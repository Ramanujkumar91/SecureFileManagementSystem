#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include "metadata.h"

void display_metadata(const char* filename) {
    struct stat fileStat;

    if (stat(filename, &fileStat) < 0) {
        perror("Error getting file metadata");
        return;
    }

    printf("\n--- File Metadata ---\n");
    printf("File: %s\n", filename);
    printf("Size: %lld bytes\n", (long long)fileStat.st_size);
    printf("Last Accessed: %s", ctime(&fileStat.st_atime));
    printf("Last Modified: %s", ctime(&fileStat.st_mtime));
    printf("Created: %s", ctime(&fileStat.st_ctime));
    printf("----------------------\n");
}
