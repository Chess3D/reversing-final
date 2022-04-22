#include "Asset.h"

using std::string;
using std::cout;
using std::endl;

Asset::Asset(string name, unsigned int id, double x, double y)
{
    #include "Images.h"
    
    this->name = name;

    this->id = id;

    this->x = x;
    this->y = y;

    string location = getLocation();

    image = "";
    if (location == "Dilophosaurus Paddock") {
        image = dilophosaurus_image;
    } else if (location == "T-Rex Paddock") {
        image = trex_image;
    } else if (location == "Raptor Paddock") {
        image = raptor_image;
    } else if (location == "Triceratops Paddock") {
        image = triceratops_image;
    }
}


string Asset::getLocation()
{
    string location;

    if (x >= 0)
    {
        if (y >= 0)
        {
            location = "Dilophosaurus Paddock";
        }
        else
        {
            location = "T-Rex Paddock";
        }
    }
    else
    {
        if (y >= 0)
        {
            location = "Raptor Paddock";
        }
        else
        {
            location = "Triceratops Paddock";
        }
    }

    return location;
}


// Prints the image of the Asset
void Asset::getImage() {
    cout << image;
}

// Prints info about the Asset
void Asset::printAsset() {
    cout << "ID:  " << id << endl;
    cout << "Name:  " << name << endl;
    cout << "Location:  " << getLocation() << " (" << x << ", " << y << ")" << endl;
}

// Return Asset ID
unsigned int Asset::getID() {
    return id;
}