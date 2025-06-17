#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utils/utils.h"

int containsCommand(COMMAND commands[], char *command, int commandsLen) {
    for (int i = 0; i < commandsLen; i++) {
        if (strcmp(command, commands[i].name) == 0) {
            return 1;
        }
    }

    return 0;
}

char *getFilePath(char *appendation) {
    const char *homeDrive = getenv("HOMEDRIVE");
    const char *homePath = getenv("HOMEPATH");

    if (homeDrive && homePath) {
        static char fullPath[512];  // static so it survives after return
        snprintf(fullPath, sizeof(fullPath), "%s%s\\%s", homeDrive, homePath, appendation);
        
        return fullPath;
    }

    return NULL;
}

char *readFile(char *path) {
    static char content[2048];  
    char buffer[1024];

    content[0] = '\0';

    FILE *pFile = fopen(path, "r");

    if (!pFile) {
        return NULL;
    }

    while (fgets(buffer, sizeof(buffer), pFile)) {
        strcat(content, buffer);
    }

    fclose(pFile);

    return content;
}