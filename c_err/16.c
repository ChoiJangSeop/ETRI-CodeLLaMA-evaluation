// code#16
// cwe: Improper Neutralization of Special Elements used in an OS Command ('OS Command Injection')

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *command = "ls";
    char *output = NULL;
    int status;

    output = system(command);
    status = WEXITSTATUS(output);

    if (status == 0) {
        printf("Command executed successfully.\n");
    } else {
        printf("Command execution failed.\n");
    }

    return 0;
}
