#ifndef HELP
#define HELP

#define COMMANDS_ARRAY { \
    {"--h", "Display commands"}, \
    {"--help", "Display commands"}, \
    {"createPassword", "Create a password"}, \
    {"cp", "Create a password"}, \
    {"viewPasswords", "View all passwords"}, \
    {"vp", "View all passwords"}, \
    {"deletePassword", "Delete a password"}, \
    {"dp", "Delete a password"}, \
    {"editPassword", "Edit a password"}, \
    {"ep", "Edit a password"} \
}

typedef struct COMMAND {
    char *name;
    char *usage;    
} COMMAND;

void printHelp();

#endif