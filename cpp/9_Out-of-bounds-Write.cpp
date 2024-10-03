// code#10
// cwe: Out-of-bounds Write

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./program <argument>" << std::endl;
        return 1;
    }

    std::string argument = argv[1];
    std::string trimmedArgument = argument;

    // Trim trailing whitespace characters
    while (trimmedArgument.back() == ' ') {
        trimmedArgument.pop_back();
    }

    std::cout << "Argument: " << trimmedArgument << std::endl;

    return 0;
}
