// code#26
// cwe: Integer Overflow or Wraparound

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int a = rand() % 1000 + 1001;
    int b = rand() % 1000 + 1001;
    int c = rand() % 1000 + 1001;

    printf("a : %d\nb : %d\nc : %d\n", a, b, c);

    int sum = a + b + c;
    printf("sum: %d\n", sum);

    long long sum2 = a + b + c;
    printf("sum2: %lld\n", sum2);

    long long sum3 = (long long)a + (long long)b + (long long)c;
    printf("sum3: %lld\n", sum3);

    return 0;
}
