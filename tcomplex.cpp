#include "tcomplex.h"
#include "tanumber.h"
#include <math.h>
TComplex::TComplex() {
    this->Real = 1.0;
    this->Img = 0.0;
}
TComplex::TComplex(double real, double img) {
    Real = real;
    Img = img;
}
TComplex::TComplex(QString &str) {
    int separator = str.indexOf("i*");
    this->Real = str.left(separator-1).toInt();
    this->Img = str.right(separator-1).toInt();
    if(str[separator-1] == "-") this->Img = -this->Img;
}
TComplex* TComplex::copy(){
    TComplex* d = new TComplex();
    d->Real = this->Real;
    d->Img = this->Img;
    return d;
}
TComplex& TComplex::operator+(TANumber& B){
    TComplex pi =  static_cast<TComplex&>(B);
    TComplex* result = new TComplex();
    result->Real = this->Real + pi.Real;
    result->Img = this->Img + pi.Img;
    return *result;
}
TComplex& TComplex::operator-(TANumber& B){
    TComplex pi =  static_cast<TComplex&>(B);
    TComplex* result = new TComplex();
    result->Real = this->Real - pi.Real;
    result->Img = this->Img - pi.Img;
    return *result;
}
TComplex& TComplex::operator*(TANumber& B){
    TComplex pi =  static_cast<TComplex&>(B);
    TComplex* result = new TComplex();
    result->Real = (this->Real * pi.Real) - (this->Img * pi.Img);
    result->Img = (this->Real * pi.Img) + (this->Img * pi.Real);
    return *result;
}
TComplex& TComplex::operator/(TANumber& B){
    TComplex pi =  static_cast<TComplex&>(B);
    TComplex* result = new TComplex();
    result->Real = (this->Real*pi.Real + this->Img*pi.Img)/(pi.Real*pi.Real + pi.Img*pi.Img);
    result->Img = (this->Img*pi.Real - this->Real*pi.Img)/(pi.Real*pi.Real + pi.Img*pi.Img);
    return *result;
}
TComplex& TComplex::sqr(){
    TComplex* result = new TComplex();
    result->Real = (this->Real * this->Real) - (this->Img * this->Img);
    result->Img = (this->Real * this->Img) + (this->Img * this->Real);
    return *result;
}
TComplex& TComplex::rev(){
    TComplex* result = new TComplex();
    result->Real = this->Real/(this->Real*this->Real + this->Img*this->Img);
    result->Img = -this->Img/(this->Real*this->Real + this->Img*this->Img);
    return *result;
}
bool TComplex::operator==(TANumber& other){
    TComplex pi =  static_cast<TComplex&>(other);
    if(fabs(this->Real-pi.Real) < 0.00001 || fabs(this->Img-pi.Img) < 0.00001){
        return true;
    }
    else{
        return false;
    }
}
bool TComplex::operator!=(const TComplex &other){
    if(fabs(this->Real-other.Real) > 0.00001 || fabs(this->Img-other.Img) > 0.00001){
        return true;
    }
    else{
        return false;
    }
}
TComplex& TComplex::operator-(){
    TComplex* d = new TComplex();
    d->Real = -this->Real;
    d->Img = this->Img;
    return *d;
}
bool TComplex::isZero(){
    if(this->Real == 0.0) return true;
    else return false;
}
TComplex& TComplex::get(){
    return *this;
}

void TComplex::set(TANumber& A){
    *this = static_cast<TComplex&>(A);
}

CEditor& TComplex::getRedactor(){
    return *(new CEditor());
}
