#include "memory.h"
#include <QString>

void Memory::setMemory(TANumber& other)
{
    if(FNumber) delete FNumber;
    this->FNumber = &other;
    this->state = on;
}
Memory::Memory()
{
    FNumber = nullptr;
    this->state = of;
}

void Memory::write(TANumber& new_dan){
    this->FNumber = &new_dan;
    state = on;
}

void Memory::add(TANumber& new_plus){
    this->FNumber = &(*FNumber + new_plus);
    state = on;
}

TANumber& Memory::getFNumber(){
    return *this->FNumber;
}

void Memory::ClearMem(){
    Memory();
}

bool Memory::getState(){
    if(this->state == of) return 0;
    else return 1;
}
