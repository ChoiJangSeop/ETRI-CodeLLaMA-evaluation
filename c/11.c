// code#11
// cwe: Improper Limitation of a Pathname to a Restricted Directory ('Path Traversal')

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filePath[100];
    char fileName[100];
    char safeDirectory[100] = "/safe/";
    char errorMessage[100] = "File not found.";

    printf("Enter the file name: ");
    scanf("%s", fileName);

    strcat(safeDirectory, fileName);
    strcat(safeDirectory, ".txt");

    FILE *file = fopen(safeDirectory, "r");

    if (file != NULL) {
        char line[100];
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("%s", errorMessage);
    }

    return 0;
}
