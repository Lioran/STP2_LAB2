#ifndef MEMORY_H
#define MEMORY_H
#include "tanumber.h"
#include <QString>

enum FState {of = 0, on};
class Memory
{
public:
    Memory();
    void setMemory(TANumber& other);
    TANumber* FNumber;
    FState state = of;
    void write(TANumber& new_dan);
    void add(TANumber& new_plus);
    TANumber& getFNumber();
    void ClearMem();
    bool getState();
};

#endif // MEMORY_H
