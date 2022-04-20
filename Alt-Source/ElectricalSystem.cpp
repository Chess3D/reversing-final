#include "ElectricalSystem.h"
#include "MD5.h"
using std::string;

#include <iostream>

ElectricalSystem::ElectricalSystem()
{
    systemOn = true;
    password = md5("howdy");
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
    // std::cout << "'" << input << "'" << std::endl;

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