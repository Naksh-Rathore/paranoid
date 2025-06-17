#include <stdio.h>
#include "core/error.h"

void printErrorMessage(char *commandGiven) {
    printf("%s was not a correct command!\n", commandGiven);
    printf("Use --help or --h to get all the commands to use");
}
