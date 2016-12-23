#ifndef SIGNOFF_H
#define SIGNOFF_H

#include <QObject>
#include <QProcess>
#include "commands.h"

/**
 * @brief The SignOff class
 */
class SignOff: public Commands
{
public:
    SignOff(int id);
    bool start(QStringList *args); //The method to start the execution of the sign off command
};

#endif // SIGNOFF_H
