#ifndef REBOOT_H
#define REBOOT_H

#include "Commands_h/commands.h"

class Reboot: public Commands
{
    public:
        Reboot(int id);
        bool start(QStringList *args);
};

#endif // REBOOT_H
