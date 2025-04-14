// file_ops.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encryption.h"

void read_file(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    printf("Contents of %s:\n", filename);
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(decrypt_char(ch));
    }
    fclose(fp);
}

void write_file(const char* filename) {
    FILE* fp = fopen(filename, "a");  // Change to "w" if overwrite is desired
    if (!fp) {
        perror("Error opening file");
        return;
    }

    // Flush stdin to avoid skipping fgets if called after scanf
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    char buffer[1024];
    printf("Enter text (end with a blank line):\n");
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (strcmp(buffer, "\n") == 0)
            break;

        for (int i = 0; buffer[i] != '\0'; i++) {
            fputc(encrypt_char(buffer[i]), fp);
        }
    }
    fclose(fp);
    printf("Data written and encrypted successfully.\n");
}

void delete_file(const char* filename) {
    if (remove(filename) == 0) {
        printf("File deleted successfully.\n");
    } else {
        perror("Error deleting file");
    }
}
