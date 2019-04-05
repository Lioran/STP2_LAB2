#ifndef PEDITOR_H
#define PEDITOR_H
#include "aeditor.h"

class PEditor : public AEditor
{
public:
    int basis;
    int getBasis();
    PEditor(int bas);
    bool StrIsNull() override;
    QString addSep() override;
    QString addNum(QString chis) override;
    QString BC() override;
    QString clear() override;
};

#endif // PEDITOR_H
