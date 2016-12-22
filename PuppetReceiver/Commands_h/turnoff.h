#ifndef TURNOFF_H
#define TURNOFF_H

#include "Commands_h/commands.h"

class TurnOff : public Commands
{
    public:
        TurnOff(int id);
        bool start(QStringList *args);
};

#endif // TURNOFF_H
