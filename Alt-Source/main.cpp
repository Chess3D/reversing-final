// External imports
#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <string.h>

// Internal imports
#include <Alarm.h>

// string namespace
using std::string;

// iostream namespace
using std::cout;
using std::cin;
using std::endl;

// fstream namespace
using std::ofstream;


// Global Variables :(
struct timeval tv;
string admin_user = "NEDRY";
string admin_password = "Mr. Goodbytes";
bool loggedin = false;

// TODO:  Has an unused input in disassembly (why?)
string logdata()
{
    string output = "";
    output += "THANK YOU FOR USING THE INGEN SYSTEM\n";
    output += "WE APPRECIATE YOUR CONTRIBUTIONS\n";
    output += "TRY AGAIN LATER IF YOU WANT\n";
    output += "STORE THIS INFORMATION FOR YOUR RECORDS\n";

    return output;
}

// Validate the username and password
bool validate(string &username, string &password)
{

    // TODO:  Password comparision done differently in source code
    if (!strcmp(admin_user.c_str(), username.c_str()) && !strcmp(admin_password.c_str(), password.c_str()))
    {
        loggedin = true;
    }

    return loggedin;
}

// TODO:  Write function
void visitor_controls()
{
    cout << "VISITOR CONTROLS";

    string status = "All clear";
    // ElectricSystem test = Alarm::Alarm((ElectricalSystem *)v27, status);
}

// TODO:  Write function
void park_controls()
{
}

// TODO:  Write function
void lab_controls()
{
}

// This was originally in menus but was moved here to make testing easier
void check_alarms()
{
    cout << "Checking alarms..." << endl;

    cout << "Lab:" << endl;
    labAlarm.printMessage();

    cout << "Visitor Center:" << endl;
    visitorAlarm.printMessage();

    cout << "Park:" << endl;
    parkAlarm.printMessage();
}

// Function changes
// 1. Moved the cin into the loop
// 2. Changed to do-while loop
// This prevents the code from being stuck in an infinite loop
void menus(ofstream &log)
{
    int input;

    do
    {
        // Print help menu
        cout << "[1] - Visitor Center\n";
        cout << "[2] - Park \n";
        cout << "[3] - Research Lab\n";
        cout << "[99] - Check Alarms\n";
        cout << "[0] - QUIT MENU\n";

        cin >> input;
        log << input << endl;

        switch (input)
        {
        case 1:
            visitor_controls();
            break;
        case 2:
            park_controls();
            break;
        case 3:
            lab_controls();
            break;
        case 99:
            // This repaces the code previously here to help with debuging
            check_alarms();
            break;
        default:
            "Invalid instruction.\n";
            break;
        }
    } while (input);
}


void getGenes() {
    cout << "Gene Sequence:" << endl;
    cout << "===================================================" << endl;

    char base[4] = {'T', 'G', 'C', 'A'};

    for (int i = 0; i < 200; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 10; ++k) {
                cout << base[rand() % 4];
            }
            cout << "\t";
        }
        cout << endl;
    }
    cout << "===================================================" << endl;
}


// Does not exist in the source code
// Used to clean up main function
void control_loop(ofstream &log)
{
    string user_input = "";

    while (strcmp("QUIT", user_input.c_str()))
    {
        cout << ">> ";
        cin >> user_input;
        log << user_input << endl;

        if (!strcmp("HELP", user_input.c_str()))
        {
            menus(log);
        }
        else
        {
            if (!strcmp("QUIT", user_input.c_str()))
            {
                return;
            }

            // TODO:  In source code
            // Remove?  Spaces are not read
            if (!strcmp("alarmstatus --vc", user_input.c_str()))
            {
                visitorAlarm.printMessage();
            }
            else if (!strcmp("unlockdoor --vc", user_input.c_str()))
            {
                vistorDoor.unlock();
            }
            else if (!strcmp("lockdoor --vc", user_input.c_str()))
            {
                visitorDoor.lock();
            }
            else if (!strcmp("camerastatus --vc", user_input.c_str()))
            {
                visitorCamera.displayFeed();
            }
            else if (!strcmp("inventorysummary --vc", user_input.c_str()))
            {
                if (!strcmp("alarmstatus --park", user_input.c_str()))
                {
                    parkAlarm.printMessage();
                }
                else if (!strcmp("camerastatus --park", user_input.c_str()))
                {
                    parkCamera.displayFeed();
                }
                else if (!strcmp("inventorysummary --park", user_input.c_str()))
                {
                    if (!strcmp("alarmstatus --lab", user_input.c_str()))
                    {
                        labAlarm.printMessage();
                    }
                    else if (!strcmp("unlockdoor --lab", user_input.c_str()))
                    {
                        vaultDoor.unlock();
                    }
                    else if (!strcmp("lockdoor --lab", user_input.c_str()))
                    {
                        vaultDoor.lock();
                    }
                    else if (!strcmp("camerastatus --lab", user_input.c_str()))
                    {
                        vaultCamera.displayFeed();
                    }
                    else if (!strcmp("genesummary --lab", user_input.c_str()))
                    {
                        getGenes();
                    }
                }
            }
        }
    }
}

int main()
{
    cout << "Welcome to InGen" << endl;
    cout << "Proud leader in Genetics since 1990" << endl
         << endl;

    string username;
    string password;

    ofstream log("sessionlog.txt");

    // Not in original code
    if (!log.is_open())
    {
        cout << "ERROR:  Log file could not be opened" << endl;
        return 1;
    }

    for (unsigned int i = 0; i < 3; ++i)
    {

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

        if (validate(username, password))
        {
            control_loop(log);
            break;
        }
    }
    if (!loggedin)
        cout << "TOO MANY ATTEMPTS" << endl;
    log.close();

    return 0;
}