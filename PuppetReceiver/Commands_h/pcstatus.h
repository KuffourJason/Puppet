#ifndef PCSTATUS_H
#define PCSTATUS_H

#include "commands.h"

/**
 * @brief The PCStatus class
 */
class PCStatus: public Commands
{

public:
      PCStatus(int id);
      bool start(QStringList *args); //The method to start the execution of the PC status command

protected slots:
      void outputGo();

private:
      QStringList out;
      int index = 0;
};

#endif // PCSTATUS_H
