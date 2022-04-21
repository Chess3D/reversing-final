#include "Alarm.h"

using std::string;

using std::cout;
using std::endl;

Alarm::Alarm(string input)
{
    message = input;
}

Alarm::Alarm(int input)
{
    // Deviates from source code but should be functionally equivalent
    // Originally these were assigned and left unchanged in the constructor
    message = messages[input % 5];
}

void Alarm::setMessage(string message)
{
    this->message = message;
}

void Alarm::setMessage(int input) {
    message = messages[input % 5];
}

void Alarm::printMessage()
{
    cout << "*******************************************************" << endl;
    cout << message << endl;
    cout << "*******************************************************" << endl;
}