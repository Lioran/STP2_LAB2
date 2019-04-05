#ifndef TANUMBER_H
#define TANUMBER_H


class TANumber
{
public:
    //TANumber();
    virtual TANumber* copy() = 0;
    virtual TANumber& operator+(TANumber& B) = 0;
    virtual TANumber& operator-(TANumber& B) = 0;
    virtual TANumber& operator*(TANumber& B) = 0;
    virtual TANumber& operator/(TANumber& B) = 0;
    virtual bool operator==(TANumber& B) = 0;
    virtual TANumber& operator-() = 0;
    virtual TANumber& sqr() = 0;
    virtual TANumber& rev() = 0;
    virtual bool isZero() = 0;
    virtual TANumber&  get() = 0;
    virtual void set(TANumber& A) = 0;
};

#endif // TANUMBER_H
