#ifndef OPENPROGRAM_H
#define OPENPROGRAM_H

#include "Commands_h/commands.h"

/**
 * @brief The OpenProgram class - This is a subclass of the Command class. This class opens
 * a program selected by the user from a list. The list is provided the helper class
 * SearchFolder which returns a list of paths to shortcuts to executable programs. The
 * paths are then executed in cmd
 */
class OpenProgram: public Commands
{
public:

    /**
     * @brief OpenProgram::OpenProgram - The constructor for the OpenProgram class. It
     * connects the necessary signals and slots, setups up the QProcess and assigns the commandID
     *
     * @param id - An int value to be assigned to this instance of the command class. For
     * error handling or notifications through signals, this value should be unique throughout
     * the runtime
     */
    OpenProgram(int id);

    /**
     * @brief OpenProgram::start - This method opens the specified program/file in another process
     *
     * @param args - QStringList containing the directory path of the program/file to open, at index 1,
     * and an indicator whether it is a program (use P) or file ( use F) at index 0
     *
     * @return - a boolean indicating whether the command has/is being executed
     */
    bool start(QStringList *args);
};

#endif // OPENPROGRAM_H
