#ifndef ASSET_H
#define ASSET_H

#include <string>
using std::string;

class Asset {
private:
    string location;
public:
    string getLocation();
};

#endif