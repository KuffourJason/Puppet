#ifndef SIGNOFF_H
#define SIGNOFF_H

#include <QObject>
#include <QProcess>
#include "commands.h"

/**
 * @brief The SignOff class - This is a subclass of the Command class. It signs out the user by
 * invoking the shutdown command in cmd
 */
class SignOff: public Commands
{
public:

    /**
     * @brief SignOff::SignOff - The constructor for the SignOff class. It
     * connects the necessary signals and slots, setups up the QProcess and assigns the commandID
     *
     * @param id - An int value to be assigned to this instance of the command class. For
     * error handling or notifications through signals, this value should be unique throughout
     * the runtime
     */
    SignOff(int id);

    /**
     * @brief SignOff::start - The method logs out of the computer after 30 seconds, or after a time
     * specified by the user
     *
     * @param args - This method takes no parameter. Any supplied parameter will be ignored
     *
     * @return - a boolean indicating whether the command has/is being executed
     */
    bool start(QStringList *args); //The method to start the execution of the sign off command
};

#endif // SIGNOFF_H
