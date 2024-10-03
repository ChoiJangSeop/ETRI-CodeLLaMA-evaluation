// code#20
// cwe: Improper Neutralization of Input During Web Page Generation ('Cross-site Scripting')

#include <stdio.h>
#include <stdlib.h>

void http_hello_page(FILE* request, FILE* response) {
    char username[100];
    fscanf(request, "%s", username);
    fprintf(response, "Hello %s", username);
}

int main() {
    return 0;
}

