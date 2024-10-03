// code#18
// cwe: Improper Neutralization of Special Elements used in an OS Command ('OS Command Injection')

#include <iostream>
#include <string>
#include <cstdlib>

std::string print(const std::string& format, ...) {
    std::string result;
    va_list args;
    va_start(args, format);
    result = std::vprintf(format.c_str(), args);
    va_end(args);
    return result;
}

std::string executeCommand(const std::string& command) {
    std::string result;
    std::string commandLine = "ls " + command;
    FILE* pipe = popen(commandLine.c_str(), "r");
    if (pipe != nullptr) {
        char buffer[128];
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            result += buffer;
        }
        pclose(pipe);
    }
    return result;
}

int main() {
    std::string command = print("-l %s", ".");
    std::string output = executeCommand(command);
    std::cout << output << std::endl;
    return 0;
}
