#include "ElectricalSystem.h"
#include "MD5.h"

using std::string;

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
    return password == md5(input);
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