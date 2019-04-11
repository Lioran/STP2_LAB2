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

template <class T>
TCtrl<T>::TCtrl()
{
    this->number = new T();
    this->editor = this->number.getRedactor();
    this->memory.setMemory(*this->number);
    ctrlState = cStart;
}

template <class T>
void TCtrl<T>::runCommandEditor(int command){
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

template <class T>
void TCtrl<T>::runOperation(){
    this->proc.OperationRun();
    //this->memory.write(*proc.Lop_Res);
    this->setCtrlState(cOpDone);
}
template <class T>
void TCtrl<T>::runMem(int command){
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
            if(this->type == Frac){
                TFrac* f = new TFrac(0, 1);
                this->memory.setMemory(*f);
            }
            else if(this->type == Complex){
                TComplex* f = new TComplex(0.0, 0.0);
                this->memory.setMemory(*f);
            }
            else {
                TPNumber* f = new TPNumber(1.0, 10, 2);
                this->memory.setMemory(*f);
            }
            break;
        }
    }
    this->setCtrlState(cOpDone);
}
template <class T>
void TCtrl<T>::runFunc(){
    this->proc.FuncRun(this->proc.op);
    //this->memory.write(*proc.Lop_Res);
    this->setCtrlState(cOpDone);
}

template <class T>
int TCtrl<T>::getCtrlState(){
    return this->ctrlState;
}

template <class T>
void TCtrl<T>::setCtrlState(TCtrlState State){
    this->ctrlState = State;
}
template <class T>
void TCtrl<T>::runCalc(int command){
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

template <class T>
void TCtrl<T>::StrToNum(Type type){
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

template <class T>
QString TCtrl<T>::NumToStr(Type type, TANumber& other){
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

