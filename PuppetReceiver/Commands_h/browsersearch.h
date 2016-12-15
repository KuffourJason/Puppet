#ifndef BROWSERSEARCH_H
#define BROWSERSEARCH_H

#include "commands.h"

class BrowserSearch: public Commands
{

public:
    BrowserSearch();
    bool start(QList<QString> args);
    QString status();
    bool ended();

};

#endif // BROWSERSEARCH_H
