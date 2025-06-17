#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "crud/crud_methods.h"
#include "utils/utils.h"
#include "core/password_checking.h"

void createPassword() {
    if (!checkPassword(".master_password.txt")) {
        printf("You finished all of your tries!");
        return;
    }

    char *passwordsFilePath = getFilePath(".passwords.txt");

    if (!passwordsFilePath) {
        printf("Failed to get passwords file path.\n");
        return;
    }

    FILE *pFile = fopen(passwordsFilePath, "a");

    if (!pFile) {
        printf("Failed to open password file");
        return;
    }
    
    char password[128];
    char site[128];

    do {
        printf("Site: ");
        scanf("%s", site);

        printf("Password: ");
        scanf("%s", password);

    } while (!strlen(password) || !strlen(site)); // Checks strings, not pointers for nullability

    fprintf(pFile, "%s: %s\n", site, password);

    fclose(pFile);

    printf("Password successfully added!");
}

void viewPasswords() {
    if (!checkPassword(".master_password.txt")) {
        printf("You finished all of your tries!");
        return;
    }

    char *passwordsFilePath = getFilePath(".passwords.txt");
    char *content;

    if (!passwordsFilePath) {
        printf("Failed to get passwords file path.\n");
        return;
    }

    content = readFile(passwordsFilePath);

    if (content == NULL) {
        printf("Could not read passwords file");
    }

    if (strcmp(content, "") == 0) {
        printf("No passwords saved!\n");
        return;
    }

    printf("Passwords \n%s", content);
}

void deletePassword() {
    if (!checkPassword(".master_password.txt")) {
        printf("You finished all of your tries!");
        return;
    }

    FILE *file, *temp;

    char *passwordsPathRaw = getFilePath(".passwords.txt");
    if (!passwordsPathRaw) return;

    // copy immediately to local buffer to save it
    char passwordsFilePath[512];
    strcpy(passwordsFilePath, passwordsPathRaw);

    char *tempPathRaw = getFilePath(".temp____passwords.txt");
    if (!tempPathRaw) return; 

    char tempFilename[512];
    strcpy(tempFilename, tempPathRaw);

    char buffer[2048];
    char siteToDelete[128];

    printf("Enter the site whose password you want to delete: ");
    scanf("%127s", siteToDelete); 

    file = fopen(passwordsFilePath, "r");
    temp = fopen(tempFilename, "w");

    if (file == NULL || temp == NULL) {
        printf("Error opening file(s).\n");
        return;
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        if (strncmp(buffer, siteToDelete, strlen(siteToDelete)) == 0 && buffer[strlen(siteToDelete)] == ':') {
            continue; 
        }

        fputs(buffer, temp);
    }

    fclose(file);
    fclose(temp);

    if (remove(passwordsFilePath) != 0) {
        printf("Failed to delete the original file");
        return;
    }

    if (rename(tempFilename, passwordsFilePath) != 0) {
        printf("Rename failed");
        return;
    }

    printf("Password removed successfully!\n");
}

void editPassword() {
    if (!checkPassword(".master_password.txt")) {
        printf("You finished all of your tries!");
        return;
    }

    FILE *file, *temp;

    char *passwordsPathRaw = getFilePath(".passwords.txt");
    if (!passwordsPathRaw) return;

    char passwordsFilePath[512];
    strcpy(passwordsFilePath, passwordsPathRaw);

    char *tempPathRaw = getFilePath(".temp____passwords.txt");
    if (!tempPathRaw) return; 

    char tempFilename[512];
    strcpy(tempFilename, tempPathRaw);

    char buffer[2048];
    char siteToEdit[128];

    printf("Enter the site whose password you want to edit: ");
    scanf("%127s", siteToEdit); 

    file = fopen(passwordsFilePath, "r");
    temp = fopen(tempFilename, "w");

    if (file == NULL || temp == NULL) {
        printf("Error opening file(s).\n");
        return;
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        if (strncmp(buffer, siteToEdit, strlen(siteToEdit)) == 0 && buffer[strlen(siteToEdit)] == ':') {
            char newPassword[256];

            printf("Enter new password for %s: ", siteToEdit);
            scanf("%s", newPassword);

            fprintf(temp, "%s: %s\n", siteToEdit, newPassword);
        } 

        else {
            fputs(buffer, temp);
        }
    }

    fclose(file);
    fclose(temp);

    if (remove(passwordsFilePath) != 0) {
        printf("Failed to delete the original file");
        return;
    }

    if (rename(tempFilename, passwordsFilePath) != 0) {
        printf("Rename failed");
        return;
    }

    printf("Password edited successfully!\n");
}