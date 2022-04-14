#include <iostream>
#include <fstream>

#include <sys/time.h>

#include <string>

using std::cout;
using std::cin;
using std::endl;

using std::string;
using std::strcmp;
using std::getline;

using std::ofstream;

// Global Variables :(
struct timeval tv;
string admin_user = "NEDRY";
bool loggedin = false;


// TODO:  Write function
string logdata(sting &input) {
    return input;
}

bool validate(string &username, string &password) {
    if (!strcmp(admin_user, username) && ) {
        loggedin = true;
    }

    return loggedin;
}

int main() {
    cout << "Welcome to InGen" << endl;
    cout << "Proud leader in Genetics since 1990" << endl << endl;

    string username;
    string password;

    ofstream log("sessionlog.txt");

    // Not in original code
    if (!log.is_open()) {
        cout << "ERROR:  Log file could not be opened" << endl;
        return 1;
    }

    for (unsigned int i = 0; i < 3; ++i) {
        
        // Get username
        cout << "User Name:  ";
        cin >> username;

        // Get password
        cout << "Password:  ";
        cin.ignore();
        getline(cin, password);

        // Get time
        gettimeofday(&tv, 0);

        // Add to time, username, and password to the session log
        log << "TIME: " << tv.tv_sec << endl;
        log << "USER: " << username << endl;
        log << "PASS: " << password << endl;

        if (!validate(username, password)) {
            
        }
    }

    log.close();

    return 0;
}