#ifndef REBOOT_H
#define REBOOT_H

#include "Commands_h/commands.h"

/**
 * @brief The Reboot class
 */
class Reboot: public Commands
{
    public:
        Reboot(int id);
        bool start(QStringList *args); //The method to start the execution of the reboot command
};

#endif // REBOOT_H
