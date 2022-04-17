#ifndef ASSET_H
#define ASSET_H

#include <string>

class Asset {
private:
    std::string name;

    double x;
    double y;

public:
    Asset(std::string name, double x, double y);
    std::string getLocation();
};

#endif