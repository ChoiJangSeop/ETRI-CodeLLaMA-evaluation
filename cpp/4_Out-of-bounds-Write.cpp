// code#5
// cwe: Out-of-bounds Write

#include <iostream>

int main() {
    int* chunk1 = new int[10];
    int* chunk2 = new int[10];

    for (int i = 0; i < 10; i++) {
        chunk1[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        chunk2[i] = chunk1[i];
    }

    for (int i = 0; i < 10; i++) {
        std::cout << chunk2[i] << " ";
    }

    delete[] chunk1;
    delete[] chunk2;

    return 0;
}
