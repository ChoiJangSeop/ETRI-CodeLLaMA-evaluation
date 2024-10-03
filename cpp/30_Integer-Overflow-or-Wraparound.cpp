// code#31
// cwe: Integer Overflow or Wraparound

#include <iostream>

int main() {
    int totalSales = 0;
    totalSales += 1000;
    totalSales += 2000;
    totalSales += 3000;
    std::cout << "Total sales: " << totalSales << std::endl;
    return 0;
}
