#include <Entry.h>

using std::cout;
using std::endl;
using std::cin;

using std::string;
using std::getline;

Entry::Entry() {
    opened = 0;
    locked = 1;
}


// Changed lock to use the ElectricalSystem password
void Entry::lock() {
    cout << "Enter passcode: ";
    cin.ignore();

    string passcode;
    getline(cin, passcode);

    if (passwordCorrect(passcode)) {
        if (isOn()) {
            locked = 1;
        }
    } else {
        cout << "Passoword Incorrect" << endl;
    }
}


// Changed unlock to use the ElectricalSystem password
void Entry::lock() {
    cout << "Enter passcode: ";
    cin.ignore();

    string passcode;
    getline(cin, passcode);

    if (passwordCorrect(passcode)) {
        if (isOn()) {
            locked = 0;
        }
    } else {
        cout << "Passoword Incorrect" << endl;
    }
}


// TODO:  What does opened do?
bool Entry::isOpen() {
    return opened;
}