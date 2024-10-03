// code#17
// cwe: Improper Neutralization of Special Elements used in an OS Command ('OS Command Injection')

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void executeCommand(char* command) {
    char* args[2];
    args[0] = "ls";
    args[1] = command;
    execvp(args[0], args);
}

void print(char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

int main() {
    char* command = ".";
    print("Executing ls command with argument: %s\n", command);
    executeCommand(command);
    return 0;
}
