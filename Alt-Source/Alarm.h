#ifndef ALARM_H
#define ALARM_H

// Required internal imports
#include <ElectricalSystem.h>

// Required external imports
#include <string>
using namespace std;
class Alarm
{
private:
    string message;

public:
    // Alarm(ElectricalSystem);
    void setMessage(string message);
    void printMessage();
};

#endif