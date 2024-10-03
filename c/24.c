// code#24
// cwe: Integer Overflow or Wraparound

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./add1000 <value>\n");
        return 1;
    }

    int value = atoi(argv[1]);
    int result = value + 1000;

    printf("Result: %d\n", result);

    return 0;
}
