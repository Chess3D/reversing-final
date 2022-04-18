#include <iostream>
#include <fstream>
#include <sstream>

#include <string>

#include <Alarm.h>
#include <Entry.h>
#include <Camera.h>

using std::cout;
using std::cin;
using std::endl;

using std::ofstream;

using std::istringstream;

using std::string;


// Splits the input into the command and location
void split_input(string input, string *command, string *location) {
    string temp;

    istringstream ss(input);

    ss >> *command;
    ss >> *location;
}


// Run the correct command for the given set of systems
void do_command(string command, Alarm alarm, Entry door, Camera camera) {
    if (command == "alarmstatus") {
        alarm.printMessage();
    } else if (command == "lockdoor") {
        door.lock();
    } else if (command == "unlockdoor") {
        door.unlock();
    } else if (command == "camerastatus") {
        camera.displayFeed();
    } else if (command == "inventorysummary") {
        cout << "TODO:  Should something happen here?" << endl;
    }
}


// The primary control loop of the program
void control_loop(ofstream &log) {
    string input;

    // Get the user input
    cout << ">> ";
    getline(cin, input);

    // Log the user input
    log << input << endl;

    // Split the user input into two parts
    string command;
    string location;

    split_input(input, &command, &location);

    // Exit when the user types quit
    if (command == "QUIT") {
        return;
    }

    // Run the correct command
    if (command == "HELP") {
        menus(log);
    } else if (location == "--vc") {
        do_command(command, visitorAlarm, visitorDoor, visitorCamera);
    } else if (command == "--park") {
        do_command(command, parkAlarm, parkDoor, parkCamera);
    } else if (command == "--lab") {
        if (command == "genesummary") {
            getGenes();
        } else {
            do_command(command, labAlarm, vaultDoor, vaultCamera);
        }
    }

    // Continues to loop until "QUIT" is entered
    control_loop(log);
}