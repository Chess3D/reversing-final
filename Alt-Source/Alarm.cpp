#include <Alarm.h>

using std::string;

using std::cout;
using std::endl;


Alarm::Alarm(string input) {
    custom = input;
}

Alarm::Alarm(int input) {
    custom = messages[input % 5];
}

void Alarm::setMessage(string message) {
    custom = message;
}

void Alarm::printMessage() {
    cout << "*******************************************************" << endl;
    cout << custom << endl;
    cout << "*******************************************************" << endl;
}