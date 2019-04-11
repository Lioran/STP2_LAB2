#include "tfrac.h"
#include "tanumber.h"

TFrac::TFrac()
{
    this->up = 0;
    this->down = 1;
}

TFrac::TFrac(int a, int b){
    int temp = gcd(a, b);
    a /= abs(temp);
    b /= abs(temp);
    this->up = a;
    this->down = b;
}
TFrac::TFrac(const QString &str) {
    int separator = str.indexOf("|");
    this->up = str.left(separator).toInt();
    this->down = str.right(separator).toInt();
}
int TFrac::gcd(int a, int b){
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
void TFrac::evk(){
    int temp = gcd(up, down);
    up /= abs(temp);
    down /= abs(temp);
}
TFrac* TFrac::copy(){
    TFrac* d = new TFrac();
    d->up = this->up;
    d->down = this->down;
    return d;
}
TFrac& TFrac::operator+(TANumber& other){
    TFrac pi =  static_cast<TFrac&>(other);
    TFrac* d = new TFrac();
    d->up = this->up*pi.down+this->down*pi.up;
    d->down = this->down * pi.down;
    d->evk();
    return *d;
}
TFrac& TFrac::operator-(){
    TFrac* d = new TFrac();
    d->up = -this->up;
    d->down = this->down;
    return *d;
}
TFrac& TFrac::operator-(TANumber& other){
    TFrac pi =  static_cast<TFrac&>(other);
    TFrac* d = new TFrac();
    d->up = this->up*pi.down-this->down*pi.up;
    d->down = this->down * pi.down;
    d->evk();
    return *d;
}
TFrac& TFrac::operator*(TANumber& other){
    TFrac pi =  static_cast<TFrac&>(other);
    TFrac* d = new TFrac();
    d->up = this->up*pi.up;
    d->down = this->down *pi.down;
    d->evk();
    return *d;
}
TFrac& TFrac::sqr(){
    TFrac* d = new TFrac();
    d->up = this->up * this->up;
    d->down =this->down * this->down;
    d->evk();
    return *d;
}
TFrac& TFrac::rev() {
    TFrac* d = new TFrac();
    d->up = this->down;
    d->down = this->up;
    d->evk();
    return *d;
}
TFrac& TFrac::operator/(TANumber& other){
    TFrac pi =  static_cast<TFrac&>(other);
    TFrac* d = new TFrac();
    d->up = this->up*pi.down;
    d->down = this->down * pi.up;
    if(d->down < 0){
        d->down = -d->down;
        d->up = -d->up;
    }
    d->evk();
    return *d;
}


bool TFrac::operator==(TANumber& other) {
    TFrac pi =  static_cast<TFrac&>(other);
    if (this->up == pi.up && this->down == pi.down)
        return true;
    else
        return false;
}

bool TFrac::operator>(TFrac &other) {
    this->up *= other.down;
    other.up *= this->down;
    if (this->up > other.up)
        return true;
    else
        return false;
}
bool TFrac::isZero(){
    if(this->up == 0) return true;
    else return false;
}

TFrac& TFrac::get(){
    return *this;
}

void TFrac::set(TANumber& A){
    *this = static_cast<TFrac&>(A);
}

FEditor& TFrac::getRedactor(){
    return *(new FEditor());
}
