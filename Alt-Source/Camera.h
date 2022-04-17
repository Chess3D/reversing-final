#ifndef CAMERA_H
#define CAMERA_H

// Internal import(s)
#include <ElectricalSystem.h>

// External import(s)
#include <string>
#include <iostream>

class Camera: public ElectricalSystem {
private:
    std::string view;

public:
    Camera(std::string view);
    void displayFeed();
    void refreshFeed(std::string view);
};

#endif