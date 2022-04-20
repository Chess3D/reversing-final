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
    cin.ignore();

    string passcode;
    getline(cin, passcode);

    if (passwordCorrect(passcode))
    {
        if (isOn())
        {
            locked = true;
        }
    }
    else
    {
        cout << "Passoword Incorrect" << endl;
    }
}

// Changed unlock to use the ElectricalSystem password
void Entry::unlock()
{
    cout << "Enter passcode: ";
    cin.ignore();

    string passcode;
    getline(cin, passcode);

    if (passwordCorrect(passcode))
    {
        if (isOn())
        {
            locked = false;
        }
    }
    else
    {
        cout << "Passoword Incorrect" << endl;
    }
}

// Do not require a password to open
void Entry::open()
{
    if (isOn() && !locked)
    {
        opened = true;
    }
}

// Do not require a password to close
void Entry::close()
{
    if (isOn())
    {
        opened = false;
    }
}

// TODO:  What does opened do?
bool Entry::isOpen()
{
    return opened;
}