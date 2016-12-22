#ifndef SIGNOFF_H
#define SIGNOFF_H

#include <QObject>
#include <QProcess>
#include "commands.h"

class SignOff: public Commands
{
public:
    SignOff(int id);
    bool start(QStringList *args);
};

#endif // SIGNOFF_H
