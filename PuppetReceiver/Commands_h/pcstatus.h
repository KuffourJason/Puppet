#ifndef PCSTATUS_H
#define PCSTATUS_H

#include "commands.h"

class PCStatus: public Commands
{

public:
      PCStatus();
      bool start();
      bool ended();
      QString status();
};

#endif // PCSTATUS_H
