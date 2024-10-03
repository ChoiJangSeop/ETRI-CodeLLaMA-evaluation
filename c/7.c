// code#7
// cwe: Out-of-bounds Write

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./trim <string>\n");
        return 1;
    }

    char *trimmedString = argv[1];

    for (int i = strlen(trimmedString) - 1; i >= 0; i--) {
        if (trimmedString[i] == ' ') {
            trimmedString[i] = '\0';
        } else {
            break;
        }
    }

    for (int i = 0; i < strlen(trimmedString); i++) {
        if (trimmedString[i] == '\n') {
            trimmedString[i] = '\0';
        }
    }

    trimmedString[strlen(trimmedString)] = '\0';

    printf("%s\n", trimmedString);

    return 0;
}
