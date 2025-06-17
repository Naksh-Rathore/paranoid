#include <stdio.h>
#include <string.h>

#include "crud/crud_router.h"
#include "crud/crud_methods.h"

void crudRoute(char *command) {
    if (strcmp(command, "vp") == 0 || strcmp(command, "viewpasswords") == 0) {
        viewPasswords();
        return;
    }

    if (strcmp(command, "cp") == 0 || strcmp(command, "createpassword") == 0) {
        createPassword();
        return;
    }

    if (strcmp(command, "ep") == 0 || strcmp(command, "editpassword") == 0) {
        editPassword();
        return;
    }

    if (strcmp(command, "dp") == 0 || strcmp(command, "deletepassword") == 0) {
        deletePassword();
        return;
    }

    // Fallback for an unknown command
    printf("[router] Unknown command: %s\n", command);
}
