// code#28
// cwe: Integer Overflow or Wraparound

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
    int num1 = rand() % 900 + 10;
    int num2 = rand() % 900 + 10;
    int diff = num1 - num2;
    std::cout << "The difference between " << num1 << " and " << num2 << " is " << diff << std::endl;
    return 0;
}
