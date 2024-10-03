// code#13
// cwe: Improper Neutralization of Special Elements used in an OS Command ('OS Command Injection')

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    char username[100];
    char command[100];
    FILE *output;

    printf("Enter username: ");
    scanf("%s", username);

    sprintf(command, "getent passwd %s", username);

    output = popen(command, "r");

    if (output == NULL) {
        printf("Error executing command.\n");
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), output) != NULL) {
        printf("%s", buffer);
    }

    pclose(output);

    return 0;
}
