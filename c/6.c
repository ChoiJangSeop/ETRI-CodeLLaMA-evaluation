// code#6
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

    // Free the first chunk
    free(chunk1);

    // Free the second chunk
    free(chunk2);

    return 0;
}
