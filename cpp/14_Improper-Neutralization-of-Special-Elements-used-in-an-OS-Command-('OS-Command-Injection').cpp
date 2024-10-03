// code#15
// cwe: Improper Neutralization of Special Elements used in an OS Command ('OS Command Injection')

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

string executeCommand(string command) {
    string output;
    FILE *fp;
    char buffer[1024];

    fp = popen(command.c_str(), "r");
    if (fp == NULL) {
        cout << "Failed to execute command" << endl;
        return "";
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        output += buffer;
    }

    pclose(fp);

    return output;
}

void printUserInfo(string username) {
    string command = "cat /etc/passwd | grep " + username;
    string output = executeCommand(command);

    if (output.empty()) {
        cout << "User not found" << endl;
        return;
    }

    string userInfo;
    stringstream ss(output);
    getline(ss, userInfo, ':'); // Get username
    getline(ss, userInfo, ':'); // Get password
    getline(ss, userInfo, ':'); // Get user ID
    getline(ss, userInfo, ':'); // Get group ID
    getline(ss, userInfo, ':'); // Get user info
    getline(ss, userInfo, ':'); // Get home directory
    getline(ss, userInfo, ':'); // Get shell

    cout << "Username: " << username << endl;
    cout << "Password: " << userInfo <<
