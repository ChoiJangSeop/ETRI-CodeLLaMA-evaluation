// code#3
// cwe: Out-of-bounds Write

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    float randomFloat1 = rand() / (float)RAND_MAX;
    float randomFloat2 = rand() / (float)RAND_MAX;
    float randomFloat3 = rand() / (float)RAND_MAX;

    char string[100];
    char string2[100];
    char string3[100];

    sprintf(string, "%f", randomFloat1);
    sprintf(string2, "%f", randomFloat2);
    sprintf(string3, "%f", randomFloat3);

    printf("string: %s\n", string);
    printf("string2: %s\n", string2);
    printf("string3: %s\n", string3);

    return 0;
}
