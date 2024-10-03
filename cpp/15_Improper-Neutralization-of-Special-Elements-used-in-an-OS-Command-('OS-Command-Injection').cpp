// code#16
// cwe: Improper Neutralization of Special Elements used in an OS Command ('OS Command Injection')

#include <iostream>
#include <string>
#include <cstdlib>

int runCommand(std::string command) {
    int status = system(command.c_str());
    return status;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./a.out <username>" << std::endl;
        return 1;
    }

    std::string command = "id " + std::string(argv[1]);
    int status = runCommand(command);

    std::cout << "Exit status: " << status << std::endl;

    return 0;
}
