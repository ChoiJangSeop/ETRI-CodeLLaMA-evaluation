// code#27
// cwe: Integer Overflow or Wraparound

#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, diff;

    num1 = rand() % 900 + 10;
    num2 = rand() % 900 + 10;

    diff = num1 - num2;

    printf("The difference between %d and %d is %d.\n", num1, num2, diff);

    return 0;
}
