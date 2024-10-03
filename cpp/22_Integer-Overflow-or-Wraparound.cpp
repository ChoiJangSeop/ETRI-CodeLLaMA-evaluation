// code#23
// cwe: Integer Overflow or Wraparound

#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter a value: ";
    std::cin >> input;

    int value = std::stoi(input);
    int result = value + 1000;

    std::cout << "Result: " << result << std::endl;

    return 0;
}
