// code#3
// cwe: Out-of-bounds Write

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main() {
    std::ofstream outfile("output.txt");

    float num1 = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    float num2 = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    float num3 = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

    std::string num1Str = std::to_string(num1);
    std::string num2Str = std::to_string(num2);
    std::string num3Str = std::to_string(num3);

    std::string concatenatedStr = num1Str + num2Str + num3Str;

    outfile << concatenatedStr << std::endl;

    outfile.close();

    return 0;
}
