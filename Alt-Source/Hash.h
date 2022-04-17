#ifndef HASH_H
#define HASH_H

#include <string>

class Hash {
private:
    struct MyItem {

    };
public:
    Hash(int);
    void hashFunction(int);
    void insertItem(int, std::string, int);
    void deleteItem(int);
    void displayHash();
};

#endif