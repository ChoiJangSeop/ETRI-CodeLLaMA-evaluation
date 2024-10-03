// code#30
// cwe: Integer Overflow or Wraparound

#include <iostream>

int getMonthlySales(int month) {
    int sales;
    // Calculate the monthly sales for the given month
    // and store it in the sales variable
    return sales;
}

int main() {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        int monthlySales = getMonthlySales(i);
        sum += monthlySales;
    }
    std::cout << "Total sales for the first quarter: " << sum << std::endl;
    return 0;
}
