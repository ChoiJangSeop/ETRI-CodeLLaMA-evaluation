// code#14
// cwe: Improper Neutralization of Special Elements used in an OS Command ('OS Command Injection')

#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
    std::string username;
    std::cout << "Enter username: ";
    std::cin >> username;

    std::string command = "getent passwd " + username;

    std::ofstream output("output.txt");

    // Execute command using system() function
    system(command.c_str());

    // Execute command using popen() function
    FILE* fp = popen(command.c_str(), "r");
    if (fp != NULL) {
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            output << buffer;
        }
        pclose(fp);
    }

    output.close();

    return 0;
}
