// code#12
// cwe: Improper Limitation of a Pathname to a Restricted Directory ('Path Traversal')

#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}
