#ifndef PROC_H
#define PROC_H
#include "tanumber.h"

enum Operation{None = 0, plus, minus, mul, divi, sqr, rev};
class Proc
{
public:
    Proc();
    void setProc(TANumber& other);
    TANumber* Lop_Res;
    TANumber* Rop;
    Operation op = None;
    void ProcClear();
    void OperationClear();
    void OperationRun();
    void FuncRun(Operation str);
    TANumber& getLop_Res();
    void setLop_Res(TANumber& new_dan);
    TANumber& getRop();
    void setRop(TANumber& new_dan);
    Operation getOperation();
    void setOperation(Operation str);
};

#endif // PROC_H
