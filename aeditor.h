#ifndef AEDITOR_H
#define AEDITOR_H
#include <QString>

class AEditor
{
public:
    //AEditor();
    QString chislo;
    QString Sep;
    bool FSep;
    virtual bool StrIsNull() = 0;
    virtual QString addSep() = 0;
    virtual QString addNum(QString chis) = 0;
    virtual QString BC() = 0;
    virtual QString clear() = 0;
};

#endif // AEDITOR_H
