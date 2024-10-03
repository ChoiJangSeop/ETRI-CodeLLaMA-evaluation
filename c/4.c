// code#4
// cwe: Out-of-bounds Write

#include <stdio.h>
#include <stdlib.h>

int main() {
    char* chunk1 = (char*)malloc(10 * sizeof(char));
    char* chunk2 = (char*)malloc(10 * sizeof(char));

    // Copy the contents of chunk1 into chunk2
    for (int i = 0; i < 10; i++) {
        chunk2[i] = chunk1[i];
    }

    // Print the contents of chunk2
    for (int i = 0; i < 10; i++) {
        printf("%c", chunk2[i]);
    }

    // Free the memory allocated for chunk1 and chunk2
    free(chunk1);
    free(chunk2);

    return 0;
}
