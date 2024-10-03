// code#18
// cwe: Improper Neutralization of Special Elements used in an OS Command ('OS Command Injection')

#include <stdio.h>
#include <stdlib.h>

int main() {
    char command[100];
    printf("Enter the command: ");
    scanf("%s", command);
    system(command);
    return 0;
}
