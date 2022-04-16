#include <Alarm.h>

using std::string;

using std::cout;
using std::endl;


Alarm::Alarm(string input) {
    message = input;
}

Alarm::Alarm(int input) {
    // Deviates from source code but should be functionally equivalent
    // Originally these were assigned and left unchanged in the constructor
    const string messages[5] = {
        "SEVERE WEATHER IMMINDENT. EVACUATE IMMEDIATELY",
        "THE FIRE ALARM HAS BEEN ACTIVATED. EVACUATE IMMEDIATELY",
        "BREACH DETECTED",
        "SYSTEM FAILURE",
        "ASSETS OUT OF CONTAINTMENT. THIS IS NOT A DRILL."
    };

    message = messages[input % 5];
}

void Alarm::setMessage(string message) {
    this->message = message;
}

void Alarm::printMessage() {
    cout << "*******************************************************" << endl;
    cout << message << endl;
    cout << "*******************************************************" << endl;
}