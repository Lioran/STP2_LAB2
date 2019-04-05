#ifndef CEDITOR_H
#define CEDITOR_H
#include "aeditor.h"

class CEditor : public AEditor
{
public:
    CEditor();
    bool StrIsNull() override;
    QString addSep() override;
    QString addNum(QString chis) override;
    QString BC() override;
    QString clear() override;
};

#endif // CEDITOR_H
