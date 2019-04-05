#ifndef TFRAC_H
#define TFRAC_H
#include "tanumber.h"
#include <QString>

class TFrac : public TANumber
{
public:
    int up;
    int down;
    void evk();
    int gcd(int a, int b);
    TFrac();
    TFrac(int a, int b);
    TFrac(const QString &str);
    TFrac* copy() override;
    TFrac& operator-() override;
    TFrac& operator+(TANumber& B) override;
    TFrac& operator-(TANumber& B) override;
    TFrac& operator*(TANumber& B) override;
    TFrac& operator/(TANumber& B) override;
    bool operator==(TANumber& B) override;
    bool operator>(TFrac &other);
    TFrac& sqr() override;
    TFrac& rev() override;
    bool isZero() override;
    TFrac& get() override;
    void set(TANumber& A) override;
};

#endif // TFRAC_H
