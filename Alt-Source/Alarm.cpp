#include <Alarm.h>

// Could all but custom be set to a constents?
Alarm::Alarm(string input) {
    custom = input;
}

Alarm::Alarm(int input) {
    custom = messages[input % 5];
}

Alarm::setMessage(string message) {
    custom = message;
}

Alarm::printMessage() {
    cout << "*******************************************************" << endl;
    cout << custom << endl;
    cout << "*******************************************************" << endl;
}