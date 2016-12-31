#ifndef MOVEFOF_H
#define MOVEFOF_H

#include "Commands_h/commands.h"

/**
 * @brief The MoveFOF class - This is a subclass of the Command class. It moves a file to a new
 * location. The file to be moved, as well as its new destination, are both selected by using the
 * helper class SearchFolder. The SearchFolder class can provide the directory paths for both the
 * file and its new destination
 */
class MoveFOF: public Commands
{
    public:

       /**
        * @brief MoveFOF::MoveFOF - The constructor for the MoveFOF class. It assigns the commandID
        *
        * @param id - An int value to be assigned to this instance of the command class. For
        * error handling or notifications through signals, this value should be unique throughout
        * the runtime
        */
        MoveFOF(int id);

        /**
         * @brief MoveFOF::start - This method moves a file from one location to another destination.
         *
         * @param args - QStringList containing the file to be moved, at index 0, and the new destination
         * the file is to be moved to, at index 1
         *
         * @return - a boolean indicating whether the command has/is being executed
         */
        bool start(QStringList *args); //The method to start the execution of the move file command
};

#endif // MOVEFOF_H
