#ifndef FENCE_H
#define FENCE_H

#include <ElectricalSystem.h>

class Fence: public ElectricalSystem { 
private:
    double leftBound, rightBound;
    double upperBound, lowerBound;

public:
    Fence(double leftBound, double upperBound, double rightBound, double lowerBound);
    bool inFence(double x, double y);
};

#endif