#ifndef MOVEFOF_H
#define MOVEFOF_H

#include "Commands_h/commands.h"

/**
 * @brief The MoveFOF class
 */
class MoveFOF: public Commands
{
    public:
        MoveFOF(int id);
        bool start(QStringList *args); //The method to start the execution of the move file command
};

#endif // MOVEFOF_H
