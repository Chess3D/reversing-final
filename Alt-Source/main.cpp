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
string admin_password = "Mr. Goodbyte";
bool loggedin = false;


// TODO:  Has an unused input in disassembly (why?)
string logdata() {
    string output = "";
    output += "THANK YOU FOR USING THE INGEN SYSTEM\n";
    output += "WE APPRECIATE YOUR CONTRIBUTIONS\n";
    output += "TRY AGAIN LATER IF YOU WANT\n";
    output += "STORE THIS INFORMATION FOR YOUR RECORDS\n";

    return output;
}

// Validate the username and password
bool validate(string &username, string &password) {

    // TODO:  Password comparision done differently in source code 
    if (!strcmp(admin_user, username) && !strcmp(admin_password, password)) {
        loggedin = true;
    }

    return loggedin;
}

// Does not exist in the source code
// Used to clean up main function
void control_loop(ofstream &log) {
    string user_input = "";

    while (!strcmp("QUIT", user_input)) {
        cout << ">> ";
        cin >> user_input;
        log << user_input;

        if (!strcmp("HELP", user_input)) {
            
        } else {

        }
    }
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

        // Log the log message
        log << logdata();

        if (validate(username, password)) {
            control_loop(&log);
        }
    }

    log.close();

    return 0;
}