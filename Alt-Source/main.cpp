// External imports
#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/time.h>
#include <string.h>
#include <map>
#include <vector>
// Internal imports
#include "Alarm.h"
#include "Entry.h"
#include "Camera.h"
#include "Asset.h"
#include "Car.h"
#include "MD5.h"
// string namespace
using std::string;

// iostream namespace
using std::cin;
using std::cout;
using std::endl;

// fstream namespace
using std::ofstream;

// sstream namespace
using std::istringstream;

// Global Variables :(
struct timeval tv;
string admin_user = "NEDRY";
string admin_password = "602a2fb3c804262da455d0e57df95e2b";
bool loggedin = false;

// Visitor controls
Alarm visitorAlarm("ALL CLEAR");
Entry visitorDoor;
Camera visitorCamera("ONLINE");

// Park controls
Alarm parkAlarm("ALL CLEAR");
Entry parkDoor;
Camera parkCamera("ONLINE");

// Lab controls
Alarm labAlarm("ALL CLEAR");
Entry vaultDoor;
Camera vaultCamera("ONLINE");

// Car storage vector
std::vector<Car> cars;

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
    string hashResult = md5(password);

    if ((admin_user == username) && (admin_password == hashResult))
    {
        cout << "\nWELCOME BACK, " << username << endl
             << endl;
        loggedin = true;
    }

    return loggedin;
}

// TODO:  Write function
void visitor_controls()
{
    cout << "VISITOR CONTROLS\n";

    string status = "All clear";
    visitorAlarm.setMessage(status);
    visitorAlarm.printMessage();
}

// TODO:  Write function
void park_controls(ofstream &log)
{
    int input;

    do
    {
        // Print help menu
        cout << "[1] - Alarm System \n[2] - Entry Controls \n[3] - Car Tracking \n[4] - Inventory \n[0] - QUIT\n";

        cin >> input;
        log << input << endl;

        switch (input)
        {
        case 1:
            parkAlarm.printMessage();
            break;
        case 2:
            cout << "Current Status" << endl;
            cout << "Section 1 secure" << endl;
            cout << "Section 2 secure" << endl;
            cout << "Section 3 secure" << endl;
            cout << "Section 4 secure" << endl;
            cout << "Park Perimeter secure" << endl;
            break;
        case 3:
        {
            Car car001("CAR001", -10, -10, 2, 4, 100);
            cars.push_back(car001);
            Car car002("CAR002", -10, 10, 4, 10, 97);
            cars.push_back(car002);
            Car car003("CAR003", 10, -10, 10, 20, 84);
            cars.push_back(car003);
            Car car004("CAR004", 10, 10, 7, 16, 32);
            cars.push_back(car004);

            for (std::vector<Car>::iterator i = cars.begin(); i != cars.end(); i++)
            {
                i->printCarInfo();
            }
        }
        break;
        case 4:
        {
            Asset a1("Dilophosaurus", 23.0, 4.0);
            Asset a2("Dilophosaurus", 21.0, 16.0);
            Asset a3("Dilophosaurus", 12.0, 6.0);
            cout << "Assets 1-3 can be found in this section: ";
            cout << a1.getLocation() << endl;
            Asset a4("T-Rex", 15.0, -17.0);
            cout << "Asset 4 can be found in this section: ";
            cout << a4.getLocation() << endl;
            Asset a5("Triceratops", -12.0, -12.0);
            Asset a6("Triceratops", -22.0, -22.0);
            cout << "Assets 5-6 can be found in this section: ";
            cout << a5.getLocation() << endl;
            Asset a7("Raptor", -18.0, 9.0);
            Asset a8("Raptor", -18.0, 7.0);
            Asset a9("Raptor", -16.0, 5.0);
            Asset a10("Raptor", -12.0, 9.0);
            cout << "Assets 7-10 can be found in this section: ";
            cout << a7.getLocation() << endl;
        }
        break;
        default:
            cout << "EXITING PARK CONTROLS\n ";
            break;
        }
    } while (input);
}

// Prints valid lab controls
void lab_controls()
{
    cout << "LAB CONTROLS" << endl;
    cout << "alarmstatus --lab\n";
    cout << "unlockdoor --lab\n";
    cout << "lockdoor --lab\n";
    cout << "camerastatus --lab\n";
    cout << "genesummary --lab\n";
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
    cout << "Enter HELP at any time to see menus and QUIT to end program" << endl;

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
            park_controls(log);
            break;
        case 3:
            lab_controls();
            break;
        case 99:
            // This repaces the code previously here to help with debuging
            check_alarms();
            break;
        case 0:
            break;
        default:
            cout << "Invalid instruction.\n";
            break;
        }
    } while (input);
}

void getGenes()
{
    cout << "Gene Sequence:" << endl;
    cout << "===================================================" << endl;

    char base[4] = {'T', 'G', 'C', 'A'};

    for (int i = 0; i < 200; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            for (int k = 0; k < 10; ++k)
            {
                cout << base[rand() % 4];
            }
            cout << "\t";
        }
        cout << endl;
    }
    cout << "===================================================" << endl;
}

// Splits the input into the location, object, command 
void split_input(string input, string *location, string *object, string *command)
{
    string temp;

    istringstream ss(input);

    ss >> *location;
    ss >> *object;
    ss >> *command;
}


// Convert text command to a function call for an Alarm
bool alarm_command(string command, Alarm *alarm) {
    if (command == "status") {
        cout << "[STATUS] Alarm:" << endl;
        alarm->printMessage();
    } else {
        return false;
    }

    return true;
}


// Convert text command to a function call for an Entry
bool entry_command(string command, Entry *entry) {
    if (command == "open") {
        entry->open();
    } else if (command == "close") {
        entry->close();
    } else if (command == "lock") {
        entry->lock();
    } else if (command == "unlock") {
        entry->unlock();
    } else if (command == "status") {
        entry->status();
    } else {
        return false;
    }

    return true;
}


// Convert text command to a function call for an Alarm
bool camera_command(string command, Camera *camera) {
    if (command == "status") {
        cout << "[STATUS] Camera:" << endl;
        camera->displayFeed();
    } else {
        return false;
    }

    return true;
}


// Select the correct command for the given input
bool do_command(string location, string object, string command) {
    Alarm *alarm;
    Entry *entry;
    Camera *camera;

    // Select the correct Alarm, Entry, and Camera object for the location
    if (location == "vc") {
        alarm = &visitorAlarm;
        entry = &visitorDoor;
        camera = &visitorCamera;
    } else if (location == "park") {
        alarm = &parkAlarm;
        entry = &parkDoor;
        camera = &parkCamera;
    } else if (location == "lab") {
        alarm = &labAlarm;
        entry = &vaultDoor;
        camera = &vaultCamera;
    } else {
        return false;
    }

    // Select the correct command function for the given object
    if (object == "alarm") {
        return alarm_command(command, alarm);
    } else if (object == "entry") {
        return entry_command(command, entry);
    } else if (object == "camera") {
        return camera_command(command, camera);
    } else if (object == "status") {
        return (
            camera_command(object, camera) &&
            alarm_command(object, alarm) &&
            entry_command(object, entry)
        );
    }

    // Special case functions
    if (location == "lab" && object == "genesummery") {
        getGenes();
    }
}


// The primary control loop of the program
void control_loop(ofstream &log)
{
    string input;

    // Get the user input
    cout << ">> ";
    getline(cin, input);

    // Log the user input
    log << input << endl;

    // Split the user input into three parts
    string location;
    string object;
    string command;

    split_input(input, &location, &object, &command);

    // Exit when the user types quit
    if (command == "QUIT")
    {
        return;
    }

    // Run the correct command
    if (command == "HELP")
    {
        menus(log);
    }
    else
    {
        do_command(location, object, command);
    }

    // Continues to loop until "QUIT" is entered
    control_loop(log);
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
    {
        cout << "TOO MANY ATTEMPTS" << endl;
    }

    log.close();

    return 0;
}