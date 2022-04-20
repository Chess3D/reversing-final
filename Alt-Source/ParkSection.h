#ifndef PARK_SECTION_H
#define PARK_SECTION_H

// External import(s)
#include <string>
#include <iostream>

// Internal import(s)
#include "Fence.h"
#include "Entry.h"
#include "Camera.h"

class ParkSection
{
private:
    std::string name;
    Fence fence = Fence(0, 0, 0, 0);
    Entry entry;
    Camera camera = Camera("OFFLINE");

public:
    ParkSection(std::string name, std::string view, double leftBound, double upperBound, double rightBound, double lowerBound);
    void getStatus();
    bool inSection(double x, double y);
};

#endif