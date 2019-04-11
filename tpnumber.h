#ifndef TPNUMBER_H
#define TPNUMBER_H
#include "tanumber.h"
#include "peditor.h"
#include <QString>

class TPNumber: public TANumber
{
public:
    double number;
    int basis;
    int precision;
    TPNumber();
    TPNumber(double a, int b, int c);
    TPNumber(QString a, int b, int c);
    TPNumber* copy() override;
    TPNumber& operator+(TANumber& B) override;
    TPNumber& operator-(TANumber& B) override;
    TPNumber& operator*(TANumber& B) override;
    TPNumber& operator/(TANumber& B) override;
    bool operator==(TANumber& B) override;
    TPNumber& operator-() override;
    TPNumber& rev() override;
    TPNumber& sqr() override;
    bool isZero() override;
    QString to10(QString a, int b);
    QString from10(int new_basis);
    TPNumber& get() override;
    void set(TANumber& A) override;
    void setBasis(int value);
    PEditor& getRedactor() override;
};

#endif // TPNUMBER_H
