// code#10
// cwe: Improper Limitation of a Pathname to a Restricted Directory ('Path Traversal')

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("/safe/names.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char name[100];
    while (fgets(name, sizeof(name), file) != NULL) {
        printf("%s", name);
    }

    fclose(file);
    return 0;
}
