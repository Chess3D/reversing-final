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
#include "Inventory.h"
#include "Asset.h"
#include "Car.h"
#include "MD5.h"
#include "Images.h"

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

// vector namespace
using std::vector;

// Global Variables :(
struct timeval tv;
string admin_user = "NEDRY";
string admin_password = "602a2fb3c804262da455d0e57df95e2b";
bool loggedin = false;

// Visitor controls
Alarm visitorAlarm("ALL CLEAR");
Entry visitorDoor;
Camera visitorCamera(visitor_image);
vector<Inventory> visitorInventory;

// Park controls
Alarm parkAlarm(0);
Entry parkDoor;
Camera parkCamera("ONLINE");
vector<Asset> parkInventory;

// Lab controls
Alarm labAlarm(1);
Entry vaultDoor;
Camera vaultCamera(lab_image);
vector<Inventory> labInventory;

// Car storage vector
vector<Car> cars;

// TODO:  Has an unused input in disassembly (why?)
string logdata()
{
    string output = "";
    output += "THANK YOU FOR USING THE INGEN SYSTEM\n";
    output += "WE APPRECIATE YOUR CONTRIBUTIONS\n";
    output += "TRY AGAIN LATER IF YOU WANT\n";
    output += "STORE THIS INFORMATION FOR YOUR RECORDS\n\n";

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
bool alarm_command(string command, Alarm *alarm)
{
    if (command == "status")
    {
        cout << "[STATUS] Alarm:" << endl;
        alarm->printMessage();
    }
    else
    {
        return false;
    }

    return true;
}

// Convert text command to a function call for an Entry
bool entry_command(string command, Entry *entry)
{
    if (command == "open")
    {
        entry->open();
    }
    else if (command == "close")
    {
        entry->close();
    }
    else if (command == "lock")
    {
        entry->lock();
    }
    else if (command == "unlock")
    {
        entry->unlock();
    }
    else if (command == "status")
    {
        entry->status();
    }
    else
    {
        return false;
    }

    return true;
}

// Convert text command to a function call for an Alarm
bool camera_command(string command, Camera *camera)
{
    if (command == "status")
    {
        cout << "[STATUS] Camera:" << endl;
        camera->displayFeed();
    }
    else
    {
        return false;
    }

    return true;
}

// Adds an Inventory to an inventory
bool inventory_add(vector<Inventory> *inventory)
{
    unsigned long serial;
    unsigned int lot;
    string date;

    cout << "Enter serial: ";
    cin >> serial;

    cout << "Enter lot: ";
    cin >> lot;

    cout << "Enter date: ";
    cin.ignore();
    getline(cin, date);

    try
    {
        inventory->push_back(Inventory(serial, lot, date));
    }
    catch (const char *e)
    {
        return false;
    }

    return true;
}

// Adds an Asset to an inventory
bool inventory_add(vector<Asset> *inventory)
{
    unsigned int id;

    string name;

    double x;
    double y;

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter x-corrdinate: ";
    cin >> x;

    cout << "Enter y-corrdinate: ";
    cin >> y;

    try
    {
        inventory->push_back(Asset(name, id, x, y));
    }
    catch (const char *e)
    {
        return false;
    }

    return true;
}

// Adds an Inventory to an inventory
bool inventory_remove(vector<Inventory> *inventory)
{
    unsigned long serial;

    if (inventory->empty())
    {
        cout << "[ERROR] Inventory is empty" << endl;
        return false;
    }

    cout << "Enter serial: ";
    cin >> serial;

    for (vector<Inventory>::iterator i = inventory->begin(); i != inventory->end(); i++)
    {
        if (i->getSerial() == serial)
        {
            inventory->erase(i);
            cout << "[SUCCESS] Item removed" << endl;
            return true;
        }
    }

    cout << "[ERROR] Item could not be removed" << endl;
    return false;
}

// Removes Asset from inventory
bool inventory_remove(vector<Asset> *inventory)
{
    unsigned int id;

    if (inventory->empty())
    {
        cout << "[ERROR] Inventory is empty" << endl;
        return false;
    }

    cout << "Enter ID: ";
    cin >> id;
    for (vector<Asset>::iterator i = inventory->begin(); i != inventory->end(); i++)
    {
        if (i->getID() == id)
        {
            inventory->erase(i);
            cout << "[SUCCESS] Item removed" << endl;
            return true;
        }
    }

    cout << "[ERROR] Item could not be removed" << endl;
    return false;
}

// Convert text command to a function call for an Inventory vector
bool inventory_command(string command, vector<Inventory> *inventory)
{
    if (command == "add")
    {
        return inventory_add(inventory);
    }
    else if (command == "remove")
    {
        return inventory_remove(inventory);
    }
    else if (command == "view")
    {
        if (inventory->size() == 0)
        {
            cout << "[ERROR] Inventory is empty" << endl;
            return false;
        }

        for (vector<Inventory>::iterator i = inventory->begin(); i != inventory->end(); i++)
        {
            i->printInventory();
        }
        return true;
    }

    return false;
}

// Convert text command to a function call for an Inventory vector
bool inventory_command(string command, vector<Asset> *inventory)
{
    if (command == "add")
    {
        return inventory_add(inventory);
    }
    else if (command == "remove")
    {
        return inventory_remove(inventory);
    }
    else if (command == "view")
    {
        if (inventory->size() == 0)
        {
            cout << "[ERROR] Inventory is empty" << endl;
            return false;
        }
        for (vector<Asset>::iterator i = inventory->begin(); i != inventory->end(); i++)
        {
            i->printAsset();
        }
        return true;
    }

    return false;
}

// Runs correct car command
bool car_command(string command, vector<Car> *cars)
{
    if (command == "track")
    {
        if (cars->size() == 0)
        {
            cout << "[ERROR] No cars to track" << endl;
            return false;
        }
        for (vector<Car>::iterator i = cars->begin(); i != cars->end(); i++)
        {
            i->printCarInfo();
        }
        return true;
    }

    return false;
}

// Select the correct command for the given input
bool do_command(string location, string object, string command)
{
    Alarm *alarm;
    Entry *entry;
    Camera *camera;

    void *inventory;

    // Select the correct Alarm, Entry, and Camera object for the location
    if (location == "help")
    {
        return do_command("all", "help", "");
    }
    if (location == "all")
    {
        bool success = do_command("vc", object, command);
        success = do_command("park", object, command) && success;
        success = do_command("lab", object, command) && success;

        return success;
    }
    else if (location == "vc")
    {
        alarm = &visitorAlarm;
        entry = &visitorDoor;
        camera = &visitorCamera;
        inventory = &visitorInventory;
        vector<Inventory> *inventory = &visitorInventory;
    }
    else if (location == "park")
    {
        alarm = &parkAlarm;
        entry = &parkDoor;
        camera = &parkCamera;
        inventory = &parkInventory;
    }
    else if (location == "lab")
    {
        alarm = &labAlarm;
        entry = &vaultDoor;
        camera = &vaultCamera;
        inventory = &labInventory;
    }
    else
    {
        return false;
    }

    // Manage location help commands
    if (object == "help")
    {
        string name = "";

        if (location == "vc")
        {
            name = "Visitor Center";
        }
        else if (location == "park")
        {
            name = "Park";
        }
        else if (location == "lab")
        {
            name = "Lab";
        }

        cout << "[HELP] " << name << endl;
        cout << "\t" << location << " alarm <status>" << endl;
        cout << "\t" << location << " entry <open / close / lock / unlock>" << endl;
        cout << "\t" << location << " camera <status>" << endl;
        cout << "\t" << location << " inventory <add / remove / view>" << endl;
        cout << "\t" << location << " status" << endl;

        if (location == "lab")
        {
            cout << "\t" << location << " genesummery" << endl;
        }
        else if (location == "park")
        {
            cout << "\t" << location << " car track" << endl;
        }
    }

    // Select the correct command function for the given object
    if (object == "alarm")
    {
        return alarm_command(command, alarm);
    }
    else if (object == "entry")
    {
        return entry_command(command, entry);
    }
    else if (object == "camera")
    {
        return camera_command(command, camera);
    }
    else if (object == "inventory")
    {
        if (location == "park")
        {
            return inventory_command(command, (vector<Asset> *)inventory);
        }
        return inventory_command(command, (vector<Inventory> *)inventory);
    }
    else if (object == "status")
    {
        bool success = camera_command(object, camera);
        success = alarm_command(object, alarm) && success;
        success = entry_command(object, entry) && success;

        return success;
    }

    // Special case functions
    if (location == "lab" && object == "genesummery")
    {
        getGenes();
    }

    if (location == "park" && object == "car")
    {
        return car_command(command, &cars);
    }

    return true;
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

    // Converts the input to lowercase
    string input_lower = "";
    for (int i = 0; i < input.size(); ++i)
    {
        input_lower += tolower(input.c_str()[i]);
    }

    // Split the user input into three parts
    string location;
    string object;
    string command;

    split_input(input_lower, &location, &object, &command);

    // Exit when the user types quit
    if (location == "quit")
    {
        return;
    }

    do_command(location, object, command);

    // Continues to loop until "QUIT" is entered
    control_loop(log);
}

// Adds cars to vector
void init_cars()
{
    Car car001("CAR001", -10, -10, 2, 4, 100);
    cars.push_back(car001);
    Car car002("CAR002", -10, 10, 4, 10, 97);
    cars.push_back(car002);
    Car car003("CAR003", 10, -10, 10, 20, 84);
    cars.push_back(car003);
    Car car004("CAR004", 10, 10, 7, 16, 32);
    cars.push_back(car004);
}

// add assets to vector
void init_assets()
{
    Asset a1("Dilophosaurus", 2342, 23.0, 4.0);
    Asset a2("Dilophosaurus", 5533, 21.0, 16.0);
    Asset a3("Dilophosaurus", 2345, 12.0, 6.0);
    Asset a4("T-Rex", 9983, 15.0, -17.0);
    Asset a5("Triceratops", 7842, -12.0, -12.0);
    Asset a6("Triceratops", 8741, -22.0, -22.0);
    Asset a7("Raptor", 1111, -18.0, 9.0);
    Asset a8("Raptor", 2222, -18.0, 7.0);
    Asset a9("Raptor", 8787, -16.0, 5.0);
    Asset a10("Raptor", 9907, -12.0, 9.0);
    parkInventory.push_back(a1);
    parkInventory.push_back(a2);
    parkInventory.push_back(a3);
    parkInventory.push_back(a4);
    parkInventory.push_back(a5);
    parkInventory.push_back(a6);
    parkInventory.push_back(a7);
    parkInventory.push_back(a8);
    parkInventory.push_back(a9);
    parkInventory.push_back(a10);
}

int main()
{
    // Initialize the car objects
    init_cars();

    // Initialize the asset objects
    init_assets();

    // Display initial prompt
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
        cout << endl;
        // Get time
        gettimeofday(&tv, 0);

        // Add to time, username, and password to the session log
        log << "TIME: " << tv.tv_sec << endl;
        log << "USER: " << username << endl;
        log << "PASS: *****" << endl;

        // Log the log message
        log << logdata();

        if (validate(username, password))
        {
            cout << "Enter HELP at any time to see menus and QUIT to end program" << endl;
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