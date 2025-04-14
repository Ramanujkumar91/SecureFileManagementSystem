#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "auth.h"
#include "file_ops.h"
#include "access_control.h"
#include "encryption.h"
#include "malware_scan.h"
#include "metadata.h"
#include "overflow_demo.h"

int main() {
    char username[50], password[50], filename[100];
    char choice;

    printf("Welcome to the Secure File Management System!\n");

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (!authenticate_user(username, password)) {
        printf("Authentication failed. Exiting.\n");
        return 1;
    }

    int code = generate_2fa_code();
    printf("2FA Code: %d\n", code);
    printf("Enter the 2FA code: ");
    int input_code;
    scanf("%d", &input_code);
    if (input_code != code) {
        printf("Invalid 2FA code. Exiting.\n");
        return 1;
    }

    while (1) {
        printf("\n===== Secure File Management System =====\n");
        printf("1. Read File\n");
        printf("2. Write File\n");
        printf("3. Delete File\n");
        printf("4. View File Metadata\n");
        printf("5. Scan File for Malware\n");
        printf("6. Vulnerable Buffer Overflow Demo\n");
        printf("7. Secure Buffer Handling Demo\n");
        printf("8. Logout\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter filename to read: ");
                scanf("%s", filename);
                if (has_permission(username, filename, 'r')) {
                    read_file(filename);
                } else {
                    printf("Access denied: No read permission.\n");
                }
                break;

            case '2':
                printf("Enter filename to write: ");
                scanf("%s", filename);
                if (has_permission(username, filename, 'w')) {
                    write_file(filename);
                } else {
                    printf("Access denied: No write permission.\n");
                }
                break;

            case '3':
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                if (has_permission(username, filename, 'w')) {
                    delete_file(filename);
                } else {
                    printf("Access denied: No delete permission.\n");
                }
                break;

            case '4':
                printf("Enter filename to view metadata: ");
                scanf("%s", filename);
                display_metadata(filename);
                break;

            case '5':
                printf("Enter filename to scan: ");
                scanf("%s", filename);
                scan_file_for_malware(filename);
                break;

            case '6':
                vulnerable_function();
                break;

            case '7':
                secure_function();
                break;

            case '8':
                printf("Logging out...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
