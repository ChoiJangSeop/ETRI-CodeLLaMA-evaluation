// code#29
// cwe: Integer Overflow or Wraparound

int main() {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += getMonthlySales(i);
    }
    // Print the total sales for the first quarter
    printf("Total sales for the first quarter: %d\n", sum);
    return 0;
}

int getMonthlySales(int month) {
    // Implement logic to calculate monthly sales
    int monthlySales = 0;
    switch (month) {
        case 0:
            monthlySales = 100;
            break;
        case 1:
            monthlySales = 200;
            break;
        case 2:
            monthlySales = 300;
            break;
        default:
            monthlySales = 0;
            break;
    }
    return monthlySales;
}
