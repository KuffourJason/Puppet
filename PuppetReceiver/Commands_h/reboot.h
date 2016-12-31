#ifndef REBOOT_H
#define REBOOT_H

#include "Commands_h/commands.h"

/**
 * @brief The Reboot class - This is a subclass of the Command class. It reboots the computer by
 * invoking the shutdown command in cmd. It can also schedule a reboot from 30 to 600 seconds from
 * the time the start method invoked
 */
class Reboot: public Commands
{
    public:

        /**
         * @brief Reboot::Reboot -  The constructor for the Reboot class. It
         * connects the necessary signals and slots, setups up the QProcess and assigns the commandID
         *
         * @param id - An int value to be assigned to this instance of the command class. For
         * error handling or notifications through signals, this value should be unique throughout
         * the runtime
         */
        Reboot(int id);

        /**
         * @brief Reboot::start - The method reboots the computer after 30 seconds, or after a time
         * specified by the user
         *
         * @param args - a QStringList where the first index specifies how long the computer should
         * wait till it reboots. The valid values for this are from 30 to 600 seconds. The default
         * is 30 seconds
         *
         * @return - a boolean indicating whether the command has/is being executed
         */
        bool start(QStringList *args); //The method to start the execution of the reboot command
};

#endif // REBOOT_H
