#ifndef FEDITOR_H
#define FEDITOR_H
#include "aeditor.h"

class FEditor: public AEditor
{
public:
    FEditor();
    bool StrIsNull() override;
    QString addSep() override;
    QString addNum(QString chis) override;
    QString BC() override;
    QString clear() override;
};

#endif // FEDITOR_H
