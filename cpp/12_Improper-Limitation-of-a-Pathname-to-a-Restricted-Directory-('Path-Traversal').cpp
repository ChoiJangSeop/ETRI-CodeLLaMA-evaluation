// code#13
// cwe: Improper Limitation of a Pathname to a Restricted Directory ('Path Traversal')

#include <iostream>
#include <fstream>

int main() {
    std::string filePath = "safe/file.txt";
    std::ifstream file(filePath);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cout << "Error: File does not exist or is not readable." << std::endl;
    }

    return 0;
}
