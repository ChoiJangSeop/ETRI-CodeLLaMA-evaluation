// code#21
// cwe: Improper Neutralization of Input During Web Page Generation ('Cross-site Scripting')

#include <iostream>
#include <fstream>

void http_hello_page(std::ifstream& request, std::ofstream& response) {
    std::string username;
    std::getline(request, username);
    std::string response_message = "Hello " + username;
    response << response_message;
}

int main() {
    std::ifstream request;
    std::ofstream response;
    http_hello_page(request, response);
    return 0;
}
