#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>

class Inventory {
private:
    unsigned long serial;
    unsigned int lot;
    std::string date;
public:
    Inventory(unsigned long serial, unsigned int lot, std::string date);
    unsigned long getSerial();
    unsigned int getLot();
    std::string getDate();

    void setSerial(unsigned long serial);
    void setLot(unsigned int lot);
    void setDate(std::string date);
    void printInventory();
};

#endif