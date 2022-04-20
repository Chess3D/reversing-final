#include "Fence.h"

// Construct the fence and insure the bounds are correctly ordered
Fence::Fence(double leftBound, double upperBound, double rightBound, double lowerBound)
{
    if (leftBound > rightBound)
    {
        this->leftBound = rightBound;
        this->rightBound = leftBound;
    }
    else
    {
        this->leftBound = leftBound;
        this->rightBound = rightBound;
    }

    if (upperBound < lowerBound)
    {
        this->upperBound = lowerBound;
        this->lowerBound = upperBound;
    }
    else
    {
        this->upperBound = upperBound;
        this->lowerBound = lowerBound;
    }
}

// Check if a given cordinate is within the bounds of the fence
bool Fence::inFence(double x, double y)
{

    // Assume the coordinates are in bounds
    bool inBounds = true;

    // Outside of leftBound
    if (x <= leftBound)
    {
        inBounds = false;
    }

    // Outside of rightBound
    if (inBounds && x >= rightBound)
    {
        inBounds = false;
    }

    // Outside of upperBound
    if (inBounds && x >= upperBound)
    {
        inBounds = false;
    }

    // Outside of lowerBound
    if (inBounds && x <= lowerBound)
    {
        inBounds = false;
    }

    return inBounds;
}