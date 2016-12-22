#ifndef PCSTATUS_H
#define PCSTATUS_H

#include "commands.h"

class PCStatus: public Commands
{

public:
      PCStatus(int id);
      bool start(QStringList *args);

protected slots:
      void outputGo();

private:
      QStringList out;
      int index = 0;
};

#endif // PCSTATUS_H
