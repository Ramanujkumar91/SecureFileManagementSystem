// access_control.c
#include <stdio.h>
#include <string.h>
#include "access_control.h"

#define DEBUG 0  // Set to 1 to enable debug prints

int has_permission(const char *username, const char *filename, char operation) {
    FILE *file = fopen("permissions.txt", "r");
    if (!file) {
        perror("Error opening permissions.txt");
        return 0;
    }

    char file_user[50], file_name[100], perms[10];
    while (fscanf(file, "%s %s %s", file_user, file_name, perms) == 3) {
        if (DEBUG) {
            printf("Checking: user=%s, file=%s, perms=%s\n", file_user, file_name, perms);
        }

        if (strcmp(username, file_user) == 0 && strcmp(filename, file_name) == 0) {
            if ((operation == 'r' && strchr(perms, 'r')) ||
                (operation == 'w' && strchr(perms, 'w'))) {
                fclose(file);
                return 1;
            }
        }
    }

    fclose(file);
    return 0;
}
