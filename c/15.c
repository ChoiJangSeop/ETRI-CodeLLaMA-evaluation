// code#15
// cwe: Improper Neutralization of Special Elements used in an OS Command ('OS Command Injection')

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int runCommand(char* command) {
    int status;
    status = system(command);
    return status;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./a.out <username>\n");
        return 1;
    }

    char* command = "id ";
    command = strcat(command, argv[1]);

    int exitStatus = runCommand(command);

    if (exitStatus == 0) {
        printf("Command successful\n");
    } else {
        printf("Command failed\n");
    }

    return 0;
}
