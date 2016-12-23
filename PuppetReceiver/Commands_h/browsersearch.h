#ifndef BROWSERSEARCH_H
#define BROWSERSEARCH_H

#include "Commands_h/commands.h"

/**
 * @brief The BrowserSearch class
 */
class BrowserSearch: public Commands
{

public:
    BrowserSearch(int id);
    bool start(QStringList *args);  //The method to start the execution of the browser search command
};

#endif // BROWSERSEARCH_H
