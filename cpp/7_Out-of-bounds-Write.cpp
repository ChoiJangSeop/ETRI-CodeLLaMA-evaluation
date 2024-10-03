// code#8
// cwe: Out-of-bounds Write

#include <iostream>
#include <string>

int main() {
    std::string userInput;
    std::cout << "Enter a string: ";
    std::getline(std::cin, userInput);

    if (std::cin.fail()) {
        std::cout << "Invalid input." << std::endl;
        return 1;
    }

    if (userInput.length() != 1) {
        std::cout << "Invalid input." << std::endl;
        return 1;
    }

    for (int i = userInput.length() - 1; i >= 0; i--) {
        if (userInput[i] == ' ') {
            userInput.erase(i, 1);
        }
    }

    for (int i = 0; i < userInput.length(); i++) {
        if (userInput[i] == '\n') {
            userInput.erase(i, 1);
        }
    }

    userInput.append(1, '\0');

    std::cout << "Trimmed string: " << userInput << std::endl;

    return 0;
}
