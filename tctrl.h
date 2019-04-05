#ifndef TCTRL_H
#define TCTRL_H
#include "aeditor.h"
#include "tanumber.h"
#include "memory.h"
#include "proc.h"

enum TCtrlState {cStart = 0, cEditing, FunDone, cValDone, cExpDone, cOpDone, cOpChange, cError};
enum Type {Frac = 0, Complex, PNumber};
class TCtrl
{
private:
    TCtrlState ctrlState;
public:
    Type type;
    TCtrl(Type type);
    TCtrl(int bas);
    AEditor* editor;
    TANumber* number;
    Memory memory;
    Proc proc;
    void runMem(int command);
    void runCalc(int command);
    void runCommandEditor(int command);
    void runOperation();
    void runFunc();
    void StrToNum(Type type);
    QString NumToStr(Type type, TANumber& other);
    int getCtrlState();
    void setCtrlState(TCtrlState State);
};

#endif // TCTRL_H
