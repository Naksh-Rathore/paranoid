#include <stdio.h>
#include <string.h>

#include "core/password_checking.h"
#include "utils/utils.h"

int checkPassword(char *path) {
    char *masterPasswordFilePath = getFilePath(path);

    if (!masterPasswordFilePath) {
        printf("getFilePath() failed\n");
        return 0;
    }

    char *masterPasswordRaw = readFile(masterPasswordFilePath);
    char masterPassword[128];

    if (masterPasswordRaw != NULL) {
        strncpy(masterPassword, masterPasswordRaw, sizeof(masterPassword) - 1);        
        masterPassword[sizeof(masterPassword) - 1] = '\0';
    }

    if (!masterPasswordRaw || strlen(masterPassword) == 0) {
        char newMasterPassword[128];

        do {
            printf("Enter your new master password: ");
            scanf("%s", newMasterPassword);
        } while (strlen(newMasterPassword) <= 0);

        FILE *pFile = fopen(getFilePath(path), "w");

        if (!pFile) {
            printf("Could not open master password file");
            return 0;
        }

        fprintf(pFile, "%s", masterPassword);
        fclose(pFile);

        printf("WARNING: REMEMBER THIS PASSWORD. THERE IS NO RESET OPTION\n");

        return 1;
    }

    // else is not needed but makes the code more modular 
    else {  
        char masterPasswordGuess[128];
        int tries = 3;

        while (tries > 0) {
            do {
                printf("Enter master password: ");
                scanf("%s", masterPasswordGuess);
            } while (strlen(masterPasswordGuess) <= 0);

            if (strcmp(masterPasswordGuess, masterPassword)) return 1;

            tries--;
        }
        
        return 0;
    }
}