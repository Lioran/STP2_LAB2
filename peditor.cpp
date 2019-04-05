#include "peditor.h"
#include <math.h>

PEditor::PEditor(int bas)
{
    this->Sep = ".";
    this->basis = bas;
    this->chislo = "";
}

bool PEditor::StrIsNull(){
    if(fabs(this->chislo.toDouble()) < 0.000001) return true;
    else return false;
}
QString PEditor::addSep(){
    if(FSep == false){
        this->chislo += Sep;
        FSep = true;
    }
    return this->chislo;
}

QString PEditor::addNum(QString chis){
    int temp = chis.toInt();
    if(temp > 64) temp -= 55;
    if(temp < this->basis) this->chislo += chis;
    return  this->chislo;
}

QString PEditor::BC(){
    this->chislo = this->chislo.left(this->chislo.length()-1);
    return this->chislo;
}

QString PEditor::clear(){
    FSep = false;
    this->chislo = "";
    return this->chislo;
}

int PEditor::getBasis(){
    return this->basis;
}

