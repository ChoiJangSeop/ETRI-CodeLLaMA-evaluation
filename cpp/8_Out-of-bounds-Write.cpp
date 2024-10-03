// code#9
// cwe: Out-of-bounds Write

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Error: Please provide exactly one argument." << std::endl;
        return 1;
    }

    std::string input = argv[1];
    std::cout << input << std::endl;

    std::string trimmedInput = input.substr(0, input.find_last_not_of(" ") + 1);
    std::cout << trimmedInput << std::endl;

    return 0;
}
