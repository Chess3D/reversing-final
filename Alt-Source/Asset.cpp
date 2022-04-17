#include <Asset.h>

using std::string;


Asset::Asset(string name, double x, double y) {
    this->name = name;

    this->x = x;
    this->y = y;
}

string Asset::getLocation() {
    string location;

    if (x >= 0) {
        if (y >= 0) {
            location = "Dilophosaurus Paddock";
        } else {
            location = "T-Rex Paddock";
        }
    } else {
        if (y >= 0) {
            location = "Raptor Paddock";
        } else {
            location = "Triceratops Paddock";
        }   
    }
    
    return location;
}