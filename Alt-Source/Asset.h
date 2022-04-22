#ifndef ASSET_H
#define ASSET_H

#include <string>
#include <iostream>

class Asset {
private:
    std::string name;
    std::string image;
    
    unsigned int id;

    double x;
    double y;

public:
    Asset(std::string name, unsigned int id, double x, double y);
    std::string getLocation();
    void getImage();
    void printAsset();
    unsigned int getID();
};

#endif