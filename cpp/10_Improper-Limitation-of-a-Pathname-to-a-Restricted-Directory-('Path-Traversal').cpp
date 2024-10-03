// code#11
// cwe: Improper Limitation of a Pathname to a Restricted Directory ('Path Traversal')

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("safe/names.txt");
    std::string name;

    while (file >> name) {
        std::cout << name << std::endl;
    }

    return 0;
}
