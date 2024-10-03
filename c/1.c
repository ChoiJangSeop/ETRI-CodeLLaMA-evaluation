// code#1
// cwe: Out-of-bounds Write

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* floatToString(float num) {
    char* str = malloc(sizeof(char) * 10);
    sprintf(str, "%f", num);
    return str;
}

int main() {
    srand(time(NULL));

    float a = (float)rand() / RAND_MAX;
    float b = (float)rand() / RAND_MAX;
    float c = (float)rand() / RAND_MAX;

    char* str_a = floatToString(a);
    char* str_b = floatToString(b);
    char* str_c = floatToString(c);

    printf("str_a: %s\n", str_a);
    printf("str_b: %s\n", str_b);
    printf("str_c: %s\n", str_c);

    free(str_a);
    free(str_b);
    free(str_c);

    return 0;
}
