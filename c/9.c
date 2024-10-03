// code#9
// cwe: Out-of-bounds Write

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./trim_trailing_whitespace <string>\n");
        return 1;
    }

    char *trimmed_string = argv[1];
    int length = strlen(trimmed_string);

    // Trim trailing whitespace characters
    while (length > 0 && isspace(trimmed_string[length - 1])) {
        trimmed_string[length - 1] = '\0';
        length--;
    }

    printf("Trimmed string: %s\n", trimmed_string);

    return 0;
}
