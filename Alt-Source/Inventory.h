#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
private:
    string serial, date;
    unsigned int lot;
public:
    string getSerial();
    string getDate();
    unsigned int getLot();
};

#endif