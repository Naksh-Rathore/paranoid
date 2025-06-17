#include <stdio.h>
#include "core/help.h"

void printHelp() {
    COMMAND commands[] = COMMANDS_ARRAY;
    int commandsLen = sizeof(commands) / sizeof(commands[0]);

    printf("Commands \n");

    for (int i = 0; i < commandsLen; i++) {
        printf("%s: %s\n", commands[i].name, commands[i].usage);
    }
}