#ifndef SIGNOFF_H
#define SIGNOFF_H

#include <QObject>
#include <QProcess>
#include "commands.h"

class SignOff: public Commands
{
public:
    SignOff();
    bool start(QList<QString> *args);
    QString status();
    bool ended();
};

#endif // SIGNOFF_H
