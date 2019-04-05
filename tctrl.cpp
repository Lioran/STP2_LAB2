#include "tctrl.h"
#include "feditor.h"
#include "ceditor.h"
#include "peditor.h"
#include "tfrac.h"
#include "tcomplex.h"
#include "tpnumber.h"
#include <QString>
#include <QDebug>

int basisForPNumber = 0;
TCtrl::TCtrl(Type type)
{
    switch(type){
        case Frac:{
            this->editor = new FEditor();
            this->number = new TFrac();
            this->memory.setMemory(*this->number);
            break;
        }
        case Complex:{
            this->editor = new CEditor();
            this->number = new TComplex();
            this->memory.setMemory(*this->number);
            break;
        }
    }
    ctrlState = cStart;
}
TCtrl::TCtrl(int bas)
{
    basisForPNumber = bas;
    this->editor = new PEditor(bas);
    this->number = new TPNumber(1, bas, 5);
    this->memory.setMemory(*this->number);
    ctrlState = cStart;
}

void TCtrl::runCommandEditor(int command){
    int temp = 0;
    QString str;
    if(command >= 10){
        if(command > 20) str = ('A'+command%21);
        else{
            temp = command%10;
            str = QString::number(temp);
        }
        command = 0;
    }
    switch (command) {
        case 0:{
            //qDebug() << "зашел"<< endl;
            this->setCtrlState(cEditing);

            this->editor->addNum(str);
            break;
        }
        case 1:{
            this->setCtrlState(cEditing);
            if(this->editor->StrIsNull() == true) break;
            else{
                this->editor->addSep();
                break;
            }
        }
        case 2:{
            this->setCtrlState(cEditing);
            this->editor->BC();
            break;
        }
        case 3:{
            this->setCtrlState(cEditing);
            this->editor->clear();
            break;
        }
    }
}

void TCtrl::runOperation(){
    this->proc.OperationRun();
    //this->memory.write(*proc.Lop_Res);
    this->setCtrlState(cOpDone);
}
void TCtrl::runMem(int command){
    switch(command){
        case 0: {
            this->memory.write(*this->number);
            break;
        }
        case 1: {
            this->memory.add(*this->number);
            break;
        }
        case 2: {
            this->memory.ClearMem();
            this->memory.setMemory(*this->number);
            break;
        }
    }
    this->setCtrlState(cOpDone);
}
void TCtrl::runFunc(){
    this->proc.FuncRun(this->proc.op);
    //this->memory.write(*proc.Lop_Res);
    this->setCtrlState(cOpDone);
}

int TCtrl::getCtrlState(){
    return this->ctrlState;
}

void TCtrl::setCtrlState(TCtrlState State){
    this->ctrlState = State;
}
void TCtrl::runCalc(int command){
    int temp = 0;
    if(command >= 100){
        temp = command%100;
        command = 0;
    }
    else if(command >= 80){
        temp = command%80;
        command = 8;
    }
    switch (command) {
        case 0:{
            this->runCommandEditor(temp);
            break;
        }
        case 1:{
            if(this->ctrlState == cEditing) this->ctrlState = cValDone;
            else if(this->ctrlState == cValDone || this->ctrlState == cOpDone) this->ctrlState = cOpChange;
            else{
                this->ctrlState = cError;
                break;
            }
            this->StrToNum(this->type);
            this->editor->clear();
            this->proc.setLop_Res(*this->number);
            this->proc.setOperation(plus);
            break;
        }
        case 2:{
            if(this->ctrlState == cEditing) this->ctrlState = cValDone;
            else if(this->ctrlState == cValDone || this->ctrlState == cOpDone) this->ctrlState = cOpChange;
            else {
                this->ctrlState = cError;
                break;
            }
            this->StrToNum(this->type);
            this->editor->clear();
            this->proc.setLop_Res(*this->number);
            this->proc.setOperation(minus);
            break;
        }
        case 3:{
            if(this->ctrlState == cEditing) this->ctrlState = cValDone;
            else if(this->ctrlState == cValDone || this->ctrlState == cOpDone) this->ctrlState = cOpChange;
            else {
                this->ctrlState = cError;
                break;
            }
            this->StrToNum(this->type);
            this->editor->clear();
            this->proc.setLop_Res(*this->number);
            this->proc.setOperation(mul);
            break;
        }
        case 4:{
            if(this->ctrlState == cEditing) this->ctrlState = cValDone;
            else if(this->ctrlState == cValDone || this->ctrlState == cOpDone) this->ctrlState = cOpChange;
            else {
                this->ctrlState = cError;
                break;
            }
            this->StrToNum(this->type);
            this->editor->clear();
            this->proc.setLop_Res(*this->number);
            this->proc.setOperation(divi);
            break;
        }
        case 5:{
            if(this->ctrlState == cEditing || this->ctrlState == cValDone || this->ctrlState == cOpDone) this->ctrlState = cOpChange;
            else{
                this->ctrlState = cError;
                break;
            }
            this->StrToNum(this->type);
            this->editor->clear();
            this->proc.setLop_Res(*this->number);
            this->proc.setOperation(sqr);
            break;
        }
        case 6:{
            if(this->ctrlState == cEditing || this->ctrlState == cValDone || this->ctrlState == cOpDone) this->ctrlState = cOpChange;
            else {
                this->ctrlState = cError;
                break;
            }
            this->StrToNum(this->type);
            this->editor->clear();
            this->proc.setLop_Res(*this->number);
            this->proc.setOperation(rev);
            break;
        }
        case 7:{
            if(this->ctrlState == cOpChange || this->ctrlState == cEditing) this->ctrlState = cExpDone;
            else{
                this->ctrlState = cError;
                break;
            }
            this->StrToNum(this->type);
            this->editor->clear();
            this->proc.setRop(*this->number);
            if(this->proc.op == sqr || this->proc.op == rev) this->runFunc();
            else this->runOperation();
            this->editor->chislo = this->NumToStr(this->type, *this->proc.Lop_Res);
            this->ctrlState = cOpDone;
            break;
        }
        case 8:{
            this->StrToNum(this->type);
            this->runMem(temp);
        }
    }
}

void TCtrl::StrToNum(Type type){
    switch(type){
        case Frac:{
            TFrac* new_d = new TFrac();
            new_d->up = this->editor->chislo.left(this->editor->chislo.indexOf("|")).toInt();
            new_d->down = this->editor->chislo.right(this->editor->chislo.length()-this->editor->chislo.indexOf("|")-1).toInt();
            this->number = new_d;
            break;
        }
        case Complex:{
            TComplex* new_d = new TComplex();
            new_d->Real = this->editor->chislo.left(this->editor->chislo.indexOf("i")-1).toDouble();
            new_d->Img = this->editor->chislo.right(this->editor->chislo.length()-this->editor->chislo.indexOf("*")-1).toDouble();
            this->number = new_d;
            break;
        }
        case PNumber:{
            TPNumber* new_d = new TPNumber(this->editor->chislo.toDouble(), basisForPNumber, 2);
            this->number = new_d;
            break;
        }
    }
}
QString TCtrl::NumToStr(Type type, TANumber& other){
    switch(type){
        case Frac:{
            TFrac new_d = static_cast<TFrac&>(other);
            return QString::number(new_d.up)+"|"+QString::number(new_d.down);
        }
        case Complex:{
            TComplex new_d = static_cast<TComplex&>(other);
            return QString::number(new_d.Real, 'f', 5)+"+i*"+QString::number(new_d.Img, 'f', 5);
        }
        case PNumber:{
            TPNumber new_d = static_cast<TPNumber&>(other);;
            return QString::number(new_d.number, 'f', 10);
        }
    }
}

