#include "ElectricalSystem.h"

using std::string;

ElectricalSystem::ElectricalSystem()
{
    password = "howdy";
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
    return password == input;
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