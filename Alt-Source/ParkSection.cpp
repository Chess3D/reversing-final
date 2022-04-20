#include <ParkSection.h>

using std::string;

using std::cout;
using std::endl;


ParkSection::ParkSection(string name, string view, double leftBound, double upperBound, double rightBound, double lowerBound) {
    this->name = name;
    fence = Fence(leftBound, upperBound, rightBound, lowerBound);
    entry = Entry();
    camera = Camera(view);
}


// Display the status of the given park section
void ParkSection::getStatus() {
    cout << name << " [STATUS]";
    
    // Display fence status
    cout << "\tFence:  ";
    if (fence.isOn()) {
        cout << "ONLINE";
    } else {
        cout << "OFFLINE";
    }
    cout << endl;

    // Display entry status
    cout << "\tEntry:  ";
    if (entry.isOn()) {
        if (entry.isLocked()) {
            cout << "LOCKED";
        } else {
            cout << "UNLOCKED";
        }

        cout << " / ";

        if (entry.isOpen()) {
            cout << "OPEN";
        } else {
            cout << "CLOSED";
        }
    } else {
        cout << "OFFLINE";
    }
    cout << endl;

    // Display camera status
    cout << "\tCamera:  ";
    if (camera.isOn()) {
        cout << "ONLINE";
    } else {
        cout << "OFFLINE";
    }
    cout << endl;
}


// Check if some cordinate is within the park section
bool ParkSection::inSection(double x, double y) {
    return fence.inFence(x, y);
}