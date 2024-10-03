// code#14
// cwe: Improper Neutralization of Special Elements used in an OS Command ('OS Command Injection')

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* executeCommand(char* command) {
    char* output = NULL;
    FILE* pipe = popen(command, "r");
    if (pipe != NULL) {
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
            output = realloc(output, strlen(output) + strlen(buffer) + 1);
            strcat(output, buffer);
        }
        pclose(pipe);
    }
    return output;
}

void printUserInfo(char* username) {
    char command[1024];
    sprintf(command, "cat /etc/passwd | grep %s", username);
    char* output = executeCommand(command);
    if (output != NULL) {
        char* token = strtok(output, ":");
        while (token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, ":");
        }
        free(output);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./passwd_grep <username>\n");
        return 1;
    }
    char* username = argv[1];
    printUserInfo(username);
    return 0;
}
