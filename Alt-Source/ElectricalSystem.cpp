#include "ElectricalSystem.h"
#include "MD5.h"

using std::string;

using std::cout;
using std::endl;

ElectricalSystem::ElectricalSystem()
{
    systemOn = true;

    // Equivalent to md5("howdy")
    password = "0782efd61b7a6b02e602cc6a11673ec9";
}

// Might not be needed either
bool ElectricalSystem::isOn()
{
    return systemOn;
}

// Originally took two inputs
// Code is unused after small change to turnOff function
bool ElectricalSystem::passwordCorrect(string input)
{
    if (password != md5(input)) {
        cout << "PERMISSION DENIED" << endl;
        cout << "AH AH AH! YOU DIDN'T SAY THE MAGIC WORD!" << endl;
        return false;
    }

    return true;
}

void ElectricalSystem::turnOff(string input)
{
    // Use private variables instead of function calls
    // Originally used a function call to isOn and passwordCorrect
    if (systemOn && (input == password))
    {
        systemOn = 0;
    }
}