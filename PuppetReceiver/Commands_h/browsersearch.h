#ifndef BROWSERSEARCH_H
#define BROWSERSEARCH_H

#include "Commands_h/commands.h"

class BrowserSearch: public Commands
{

public:
    BrowserSearch(int id);
    bool start(QStringList *args);
};

#endif // BROWSERSEARCH_H
