// code#27
// cwe: Integer Overflow or Wraparound

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));

    int a = rand() % 1000 + 1001;
    int b = rand() % 1000 + 1001;
    int c = rand() % 1000 + 1001;

    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "c : " << c << std::endl;

    int sum = a + b + c;
    std::cout << "sum: " << sum << std::endl;

    long long sum2 = a + b + c;
    std::cout << "sum2: " << sum2 << std::endl;

    long long sum3 = (long long)a + (long long)b + (long long)c;
    std::cout << "sum3: " << sum3 << std::endl;

    return 0;
}
