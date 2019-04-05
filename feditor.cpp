#include "feditor.h"

FEditor::FEditor()
{
    this->Sep = "|";
    this->chislo = "";
}

bool FEditor::StrIsNull(){
    if(this->chislo == "") return true;
    else return false;
}

QString FEditor::addSep(){
    if(FSep == false){
        this->chislo += Sep;
        FSep = true;
    }
    return this->chislo;
}

QString FEditor::addNum(QString chis){
    if(this->chislo == "0") this->clear();
    this->chislo += chis;
    return  this->chislo;
}

QString FEditor::BC(){
    this->chislo = this->chislo.left(this->chislo.length()-1);
    return this->chislo;
}

QString FEditor::clear(){
    FSep = false;
    this->chislo = "";
    return this->chislo;
}
