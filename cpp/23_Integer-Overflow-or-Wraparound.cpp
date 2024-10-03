// code#24
// cwe: Integer Overflow or Wraparound

#include <iostream>

int main() {
    int value;
    std::cout << "Enter a value: ";
    std::cin >> value;

    int offset = 1000;
    int result = value + offset;

    std::cout << "Result: " << result << std::endl;

    return 0;
}
