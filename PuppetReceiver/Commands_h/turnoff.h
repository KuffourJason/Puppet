#ifndef TURNOFF_H
#define TURNOFF_H

#include "Commands_h/commands.h"

/**
 * @brief The TurnOff class
 */
class TurnOff : public Commands
{
    public:
        TurnOff(int id);
        bool start(QStringList *args);  //The method to start the execution of the turn off command
};

#endif // TURNOFF_H
