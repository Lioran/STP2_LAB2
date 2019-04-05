#include "proc.h"

void Proc::setProc(TANumber& other)
{
    if(Lop_Res) delete(Lop_Res);
    if(Rop) delete(Rop);
    this->Lop_Res = &other;
    this->Rop = &other;
    this->op = None;
}
Proc::Proc()
{
    Lop_Res = nullptr;
    Rop = nullptr;
}

void Proc::ProcClear(){
    Proc();
}

void Proc::OperationClear(){
    this->op = None;
}

void Proc::OperationRun(){
    if(this->op == plus){
        this->Lop_Res = &(*Lop_Res + *Rop);
        return;
    }
    if(this->op == minus){
        this->Lop_Res = &(*Lop_Res - *Rop);
        return;
    }
    if(this->op == mul){
        this->Lop_Res = &(*Lop_Res * *Rop);
        return;
    }
    if(this->op == divi){
        this->Lop_Res = &(*Lop_Res / *Rop);
        return;
    }
}

void Proc::FuncRun(Operation str){
    if(str == sqr){
        this->Lop_Res = &Lop_Res->sqr();
    }
    else{
        this->Lop_Res = &Lop_Res->rev();
    }
    return;
}
TANumber& Proc::getLop_Res(){
    return *this->Lop_Res;
}
void Proc::setLop_Res(TANumber& new_dan){
    this->Lop_Res = &new_dan;
}
TANumber& Proc::getRop(){
    return *this->Rop;
}
void Proc::setRop(TANumber& new_dan){
    this->Rop = &new_dan;
}
Operation Proc::getOperation(){
    return this->op;
}
void Proc::setOperation(Operation str){
    this->op = str;
}
