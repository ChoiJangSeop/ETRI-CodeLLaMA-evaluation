// code#28
// cwe: Integer Overflow or Wraparound

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMonthlySales() {
    int sales;
    sales = rand() % 100000;
    return sales;
}

int main() {
    int sales[12];
    int i;
    int quarterSales[4];

    srand(time(NULL));

    for (i = 0; i < 12; i++) {
        sales[i] = getMonthlySales();
    }

    for (i = 0; i < 4; i++) {
        quarterSales[i] = 0;
    }

    for (i = 0; i < 12; i++) {
        quarterSales[i / 3] += sales[i];
    }

    printf("Quarterly Sales:\n");
    for (i = 0; i < 4; i++) {
        printf("Quarter %d: $%d\n", i + 1, quarterSales[i]);
    }

    return 0;
}
