#include "Entry.h"

using std::cin;
using std::cout;
using std::endl;

using std::getline;
using std::string;

Entry::Entry()
{
    locked = true;
    opened = false;
}

// Changed lock to use the ElectricalSystem password
void Entry::lock()
{
    cout << "Enter passcode: ";

    string passcode;
    getline(cin, passcode);

    if (passwordCorrect(passcode))
    {
        if (isOn())
        {
            locked = true;
            cout << "SUCCESS:  Entry locked" << endl;
        }
        else
        {
            cout << "ERROR:  Entry is powered down" << endl;
        }
    }
    else
    {
        cout << "ERROR:  Incorrect passoword" << endl;
    }
}


// Changed unlock to use the ElectricalSystem password
void Entry::unlock() {
    cout << "Enter passcode: ";

    string passcode;
    getline(cin, passcode);

    if (passwordCorrect(passcode)) {
        if (isOn()) {
            locked = false;
            cout << "SUCCESS:  Entry unlocked" << endl;
        } else {
            cout << "ERROR:  Entry is powered down" << endl;
        }
    } else {
        cout << "ERROR:  Incorrect passoword" << endl;
    }
}


// Do not require a password to open
void Entry::open()
{
    if (locked) {
        cout << "ERROR:  Entry is locked" << endl;
        return;
    }

    if (isOn()) {
        opened = true;
        cout << "SUCCESS:  Entry is open" << endl;
    } else {
        cout << "ERROR:  Entry is powered down" << endl;
    }
}


// Do not require a password to close
void Entry::close()
{
    if (locked) {
        cout << "ERROR:  Entry is locked" << endl;
        return;
    }

    if (isOn())
    {
        opened = false;
        cout << "SUCCESS:  Entry is closed" << endl;
    } else {
        cout << "ERROR:  Entry is powered down" << endl;
    }
}


// TODO:  What does opened do?
bool Entry::isOpen()
{
    return opened;
}


// Check if the entry is locked
bool Entry::isLocked()
{
    return locked;
}