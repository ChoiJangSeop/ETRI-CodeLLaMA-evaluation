// code#6
// cwe: Out-of-bounds Write

#include <iostream>
#include <cstdlib>

int main() {
    // Allocate two chunks of memory each of size 10
    int* chunk1 = (int*)malloc(10 * sizeof(int));
    int* chunk2 = (int*)malloc(10 * sizeof(int));

    // Copy the contents of the first chunk into the second chunk
    for (int i = 0; i < 10; i++) {
        chunk2[i] = chunk1[i];
    }

    // Print the contents of the second chunk
    std::cout << "Contents of chunk2: ";
    for (int i = 0; i < 10; i++) {
        std::cout << chunk2[i] << " ";
    }
    std::cout << std::endl;

    // Free the memory allocated to the first chunk
    free(chunk1);

    // Print the contents of the second chunk
    std::cout << "Contents of chunk2 after freeing chunk1: ";
    for (int i = 0; i < 10; i++) {
        std::cout << chunk2[i] << " ";
    }
    std::cout << std::endl;

    // Free the memory allocated to the second chunk
    free(chunk2);

    return 0;
}
