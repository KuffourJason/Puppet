#ifndef SIGNOFF_H
#define SIGNOFF_H

#include <QObject>
#include "commands.h"

class SignOff: public Commands
{
public:
    SignOff();
    bool start();
    bool status();
    bool end();

    QString test();
};

#endif // SIGNOFF_H
