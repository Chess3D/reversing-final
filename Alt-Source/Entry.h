#ifndef ENTRY_H
#define ENTRY_H

// Internal import(s)
#include <ElectricalSystem.h>

// External import(s)
#include <iostream>
#include <string>
#include <string.h>

class Entry: public ElectricalSystem {
private:
    bool locked;
    bool opened;

public:
    void lock();
    void unlock();
    bool isOpen();
};

#endif