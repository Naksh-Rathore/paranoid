#include <stdio.h>
#include <string.h>

#include "core/help.h"
#include "core/error.h"
#include "utils/utils.h" 
#include "crud/crud_router.h"

int main(int argc, char **argv) {
    // Expand the COMMANDS_ARRAY macro into an array of COMMAND structs
    COMMAND commands[] = COMMANDS_ARRAY;
    int commandsLen = sizeof(commands) / sizeof(commands[0]);

    if (argc > 1) {
        if (containsCommand(commands, argv[1], commandsLen) == 0) {
            printErrorMessage(argv[1]);
            return 1;
        }

        if ((strcmp(argv[1], "--h") == 0 || strcmp(argv[1], "--help") == 0)) {
            printHelp();
        }

        crudRoute(argv[1]);
    }

    // Helps the user if there is nothing passed
    else {
        printHelp();
    }

    return 0;
}