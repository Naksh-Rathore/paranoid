#ifndef UTILS
#define UTILS

#include "core/help.h"

int containsCommand(COMMAND commands[], char *command, int commandsLen);
char *getFilePath();
char *readFile(char *path);

#endif