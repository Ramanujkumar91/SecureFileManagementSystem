#include <stdio.h>
#include <string.h>
#include "overflow_demo.h"

void vulnerable_function() {
    char buffer[10];
    printf("Enter something (vulnerable): ");
    gets(buffer);  // ⚠️ UNSAFE: Demonstration only. Do not use in production!
    printf("You entered: %s\n", buffer);
}

void secure_function() {
    char buffer[10];
    printf("Enter something (secure): ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';  // Remove trailing newline
    printf("You entered: %s\n", buffer);
}
