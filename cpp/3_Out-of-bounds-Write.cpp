// code#4
// cwe: Out-of-bounds Write

#include <iostream>
#include <cstdlib>
#include <cstdio>

int main() {
    float randomFloat1 = rand() / (float)RAND_MAX;
    float randomFloat2 = rand() / (float)RAND_MAX;
    float randomFloat3 = rand() / (float)RAND_MAX;

    char string[100];
    char string2[100];
    char string3[100];

    sprintf(string, "%f", randomFloat1);
    sprintf(string2, "%f", randomFloat2);
    sprintf(string3, "%f", randomFloat3);

    std::cout << "String: " << string << std::endl;
    std::cout << "String2: " << string2 << std::endl;
    std::cout << "String3: " << string3 << std::endl;

    return 0;
}
