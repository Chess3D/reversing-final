#include "Inventory.h"

using std::string;

using std::cout;
using std::endl;

Inventory::Inventory(unsigned long serial, unsigned int lot, string date)
{
    this->serial = serial;
    this->lot = lot;
    this->date = date;
}

unsigned long Inventory::getSerial()
{
    return serial;
}

unsigned int Inventory::getLot()
{
    return lot;
}

string Inventory::getDate()
{
    return date;
}

void Inventory::setSerial(unsigned long serial)
{
    this->serial = serial;
}

void Inventory::setLot(unsigned int lot)
{
    this->lot = lot;
}

void Inventory::setDate(string date)
{
    this->date = date;
}

void Inventory::printInventory() {
    cout << "Serial:  " << serial << endl;
    cout << "Lot:  " << lot << endl;
    cout << "Date:  " << date << endl;
}