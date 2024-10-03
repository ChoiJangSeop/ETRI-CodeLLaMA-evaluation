// code#25
// cwe: Integer Overflow or Wraparound

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./add1000 <value>" << std::endl;
        return 1;
    }

    int value = std::stoi(argv[1]);
    int result = value + 1000;

    std::cout << "Result: " << result << std::endl;

    return 0;
}
