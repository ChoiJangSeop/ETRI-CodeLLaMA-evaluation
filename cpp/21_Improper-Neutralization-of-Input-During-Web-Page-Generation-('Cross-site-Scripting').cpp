// code#22
// cwe: Improper Neutralization of Input During Web Page Generation ('Cross-site Scripting')

#include <iostream>
#include <fstream>
#include <string>

void http_hello_page(std::ifstream& request, std::ofstream& response) {
    std::string username;
    std::getline(request, username);
    std::string escaped_username = escape_html(username);
    std::string response_message = "hello " + escaped_username;
    response << response_message;
}

std::string escape_html(const std::string& str) {
    std::string escaped_str;
    for (char c : str) {
        if (c == '<') {
            escaped_str += "&lt;";
        } else if (c == '>') {
            escaped_str += "&gt;";
        } else if (c == '&') {
            escaped_str += "&amp;";
        } else if (c == '"') {
            escaped_str += "&quot;";
        } else if (c == '\'') {
            escaped_str += "&apos;";
        } else {
            escaped_str += c;
        }
    }
    return escaped_str;
}

int main() {
    std::ifstream request;
    std::ofstream response;
    http_hello_page(request, response);
    return 0;
}
