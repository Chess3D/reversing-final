#ifndef ENTRY_H
#define ENTRY_H

class Entry {
private:
    
public:
    void lock();
    void unlock();
    bool isOpen();
};

#endif