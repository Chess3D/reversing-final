#include "Camera.h"

using std::getline;
using std::string;

using std::cin;
using std::cout;
using std::endl;

// Same as source code
Camera::Camera(string view)
{
    this->view = view;
}

// This function is slightly different then the source code
// Source code would display if there was no power
void Camera::displayFeed()
{
    cout << "Enter passcode: ";

    string passcode;
    getline(cin, passcode);

    if (passwordCorrect(passcode))
    {
        if (isOn())
        {
            cout << view << endl;
        }
    }
    else
    {
        cout << "INCORRECT PASSCODE" << endl;
    }
}

// TODO:  Should refresh feed mirror the behavior of display feed?
void Camera::refreshFeed(string view)
{
    this->view = view;
}