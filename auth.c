// auth.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "auth.h"

int authenticate_user(char* username, char* password) {
    char stored_user[50], stored_pass[50];

    FILE* fp = fopen("users.txt", "r");
    if (!fp) {
        perror("Could not open users.txt");
        return 0;
    }

    while (fscanf(fp, "%s %s", stored_user, stored_pass) == 2) {
        if (strcmp(username, stored_user) == 0 && strcmp(password, stored_pass) == 0) {
            fclose(fp);
            return 1;  // Auth successful
        }
    }

    fclose(fp);
    return 0;
}

int generate_2fa_code() {
    srand(time(NULL));
    return rand() % 900000 + 100000;  // 6-digit OTP
}
