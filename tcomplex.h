#ifndef TCOMPLEX_H
#define TCOMPLEX_H
#include "tanumber.h"
#include "ceditor.h"
#include <QString>

class TComplex: public TANumber
{
public:
    double Real;
    double Img;
    TComplex();
    TComplex(double real, double img);
    TComplex(QString &str);
    TComplex* copy() override;
    TComplex& operator-() override;
    TComplex& operator+(TANumber& B) override;
    TComplex& operator-(TANumber& B) override;
    TComplex& operator*(TANumber& B) override;
    TComplex& operator/(TANumber& B) override;
    TComplex& sqr() override;
    TComplex& rev() override;
    bool operator==(TANumber& other);
    bool operator!=(const TComplex &other);
    bool isZero() override;
    TComplex& get() override;
    void set(TANumber& A) override;
    CEditor& getRedactor() override;
};

#endif // TCOMPLEX_H
