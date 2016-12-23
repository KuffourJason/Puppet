#ifndef OPENPROGRAM_H
#define OPENPROGRAM_H

#include "Commands_h/commands.h"

class OpenProgram: public Commands
{
public:
    OpenProgram(int id);
    bool start(QStringList *args);
};

#endif // OPENPROGRAM_H
