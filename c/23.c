// code#23
// cwe: Integer Overflow or Wraparound

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./add_offset <value>\n");
        return 1;
    }

    int value = atoi(argv[1]);
    int offset = 1000;
    int result = value + offset;

    printf("Result: %d\n", result);

    return 0;
}
