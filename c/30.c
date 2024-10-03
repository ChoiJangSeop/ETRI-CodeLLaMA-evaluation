// code#30
// cwe: Integer Overflow or Wraparound

int main() {
    int totalSales = 0;
    totalSales += 1000;
    totalSales += 2000;
    totalSales += 3000;
    printf("Total sales: %d", totalSales);
    return 0;
}