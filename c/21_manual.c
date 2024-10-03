// code#21
// cwe: Improper Neutralization of Input During Web Page Generation ('Cross-site Scripting')

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* escape_html(char* str);

void http_hello_page(FILE* request, FILE* response) {
    char username[100];
    fgets(username, 100, request);
    username[strlen(username) - 1] = '\0'; // Remove newline character
    char* escaped_username = escape_html(username);
    char* response_message = "hello ";
    char* response_message_with_username = (char*)malloc(strlen(response_message) + strlen(escaped_username) + 1);
    strcpy(response_message_with_username, response_message);
    strcat(response_message_with_username, escaped_username);
    fputs(response_message_with_username, response);
    free(escaped_username);
    free(response_message_with_username);
}

char* escape_html(char* str) {
    char* escaped_str = (char*)malloc(strlen(str) * 6 + 1);
    int i = 0;
    int j = 0;
    while (str[i] != '\0') {
        if (str[i] == '<') {
            escaped_str[j++] = '&';
            escaped_str[j++] = 'l';
            escaped_str[j++] = 't';
            escaped_str[j++] = ';';
        } else if (str[i] == '>') {
            escaped_str[j++] = '&';
            escaped_str[j++] = 'g';
            escaped_str[j++] = 't';
            escaped_str[j++] = ';';
        } else if (str[i] == '&') {
            escaped_str[j++] = '&';
            escaped_str[j++] = 'a';
            escaped_str[j++] = 'm';
            escaped_str[j++] = 'p';
            escaped_str[j++] = ';';
        } else {
            escaped_str[j++] = str[i];
        }
        i++;
    }
    escaped_str[j] = '\0';
    return escaped_str;
}

int main() {
    return 0;
}
