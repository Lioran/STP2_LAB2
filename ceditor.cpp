#include "ceditor.h"

CEditor::CEditor()
{
    this->Sep = "+i*";
    this->chislo = "";
}
bool CEditor::StrIsNull(){
    if(this->chislo == "") return true;
    else return false;
}
QString CEditor::addSep(){
    if(FSep == false){
        this->chislo += Sep;
        FSep = true;
    }
    return this->chislo;
}

QString CEditor::addNum(QString chis){
    this->chislo += chis;
    return  this->chislo;
}

QString CEditor::BC(){
    this->chislo = this->chislo.left(this->chislo.length()-1);
    return this->chislo;
}

QString CEditor::clear(){
    FSep = false;
    this->chislo = "";
    return this->chislo;
}
