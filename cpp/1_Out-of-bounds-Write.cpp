// code#2
// cwe: Out-of-bounds Write

#include <iostream>
#include <string>
#include <cstdlib>

std::string floatToString(float num) {
    std::string str = std::to_string(num);
    return str;
}

int main() {
    float a = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    float b = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    float c = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

    std::string str_a = floatToString(a);
    std::string str_b = floatToString(b);
    std::string str_c = floatToString(c);

    std::string result = str_a + str_b + str_c;

    std::cout << "Result: " << result << std::endl;

    return 0;
}
