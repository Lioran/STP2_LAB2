#include "tpnumber.h"
#include <QString>

TPNumber::TPNumber() {
    number = 1.0;
    basis = 10;
    precision = 5;
}
void TPNumber::setBasis(int value){
    this->basis = value;
}
QString TPNumber::to10(QString a, int b){
    int token = a.indexOf(".");
    if(token == -1){
        int num = a.toInt(0, b);
        return  QString::number(num, 10);
    }
    else{
        QString doo = a.left(token);
        std::string posle = a.right(a.length()-token-1).toStdString();
        int len = posle.length();
        int num = doo.toInt(nullptr, b);
        double num_pos = 0.0;
        double step = 0.0;
        step = (double)1/b;
        for(int i = 0; i < len; i++){
            if((int)posle[i]%65 < 6 && (int)posle[i]%65 >=0){
                num_pos += ((int)posle[i]%65 + 10) * step;
            }else{
                num_pos += ((int)posle[i]%48) * step;
            }
            step /= b;
        }
        num_pos += (double)num;
        a = QString::number(num_pos, 'f', a.length());
        return  a;
    }
}
QString TPNumber::from10(int new_basis){
    QString result = QString::number(this->number, 'f', this->precision);
    int token = result.indexOf(".");
    if(token == -1){
        return  QString::number(result.toInt(), new_basis);
    }
    else{
        QString doo = result.left(token);
        std::string posle = result.right(result.length()-token-1).toStdString();
        int len = posle.length();
        int num = doo.toInt();
        int num_n = 0;
        int k = 1;
        while(num > 0){
            num_n += (num%new_basis)*k;
            num /= new_basis;
            k *= 10;
        }
        double num_pos = 0.0;
        double step = 10.0;
        for(int i = 0; i < len; i++){
            num_pos += (double)(posle[i]%48)/step;
            step *= 10;
        }
        int count = this->precision;
        step = 10;
        double num_pos_n = 0.0;
        int temp = 0;
        while(num_pos > 0.00000001 && count != 0){
            num_pos *= new_basis;
            temp = (int)num_pos;
            num_pos -= (double)temp;
            num_pos_n += (double)temp/step;
            step *= 10;
        }
        num_pos_n += (double)num_n;
        QString res = QString::number(num_pos_n, 'f', this->precision);
        return  res;
    }
}
TPNumber::TPNumber(QString a, int b, int c) {
    TPNumber* test = new TPNumber();
    this->basis = b;
    this->precision = c;
    this->number = test->to10(a, b).toDouble();
}
TPNumber::TPNumber(double a, int b, int c) {
    TPNumber* test = new TPNumber();
    this->number = test->to10(QString::number(a, 'f', c), b).toDouble();
    this->basis = b;
    this->precision = c;
}
TPNumber* TPNumber::copy() {
    TPNumber* cop = new TPNumber();
    cop->number = this->number;
    cop->basis = this->basis;
    cop->precision = this->precision;
    return cop;
}
TPNumber& TPNumber::operator+(TANumber& B) {
    TPNumber pi =  static_cast<TPNumber&>(B);
    this->number += pi.number;
    TPNumber* point = new TPNumber(this->from10(this->basis), this->basis, this->precision);
    return *point;
}
TPNumber& TPNumber::operator-(TANumber& B) {
    TPNumber pi =  static_cast<TPNumber&>(B);
    this->number -= pi.number;
    TPNumber* point = new TPNumber(this->from10(this->basis), this->basis, this->precision);
    return *point;
}
TPNumber& TPNumber::operator*(TANumber& B) {
    TPNumber pi =  static_cast<TPNumber&>(B);
    this->number *= pi.number;
    TPNumber* point = new TPNumber(this->from10(this->basis), this->basis, this->precision);
    return *point;
}
TPNumber& TPNumber::operator/(TANumber& B) {
    TPNumber pi =  static_cast<TPNumber&>(B);
    this->number /= pi.number;
    TPNumber* point = new TPNumber(this->from10(this->basis), this->basis, this->precision);
    return *point;
}
TPNumber& TPNumber::rev() {
    this->number = 1/this->number;
    TPNumber* point = new TPNumber(this->from10(this->basis), this->basis, this->precision);
    return *point;
}
TPNumber& TPNumber::sqr() {
    this->number *= this->number;
    TPNumber* point = new TPNumber(this->from10(this->basis), this->basis, this->precision);
    return *point;
}
TPNumber& TPNumber::operator-(){
    this->number = -this->number;
    TPNumber* point = new TPNumber(this->from10(this->number), this->basis, this->precision);
    return *point;
}
bool TPNumber::isZero(){
    if(this->number == 0.0) return true;
    else false;
}
TPNumber& TPNumber::get(){
    return *this;
}

void TPNumber::set(TANumber& A){
    *this = static_cast<TPNumber&>(A);
}

bool TPNumber::operator==(TANumber& B) {
    TPNumber pi =  static_cast<TPNumber&>(B);
    if(this->number-pi.number == 0.0) return true;
    else false;
}

PEditor& TPNumber::getRedactor(){
    return *(new PEditor(10));
}
