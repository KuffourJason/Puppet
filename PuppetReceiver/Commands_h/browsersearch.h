#ifndef BROWSERSEARCH_H
#define BROWSERSEARCH_H

#include "Commands_h/commands.h"

/**
 * @brief The BrowserSearch class - This is a sub class of the Command class. It implements the
 * functionality of opening any number of web links in a specified browser. It uses the cmd to
 * achieve this task
 */
class BrowserSearch: public Commands
{

public:

    /**
     * @brief BrowserSearch::BrowserSearch - The constructor for the BrowserSearch class. It
     * connects the necessary signals and slots, setups up the QProcess and assigns the commandID
     *
     * @param id - An int value to be assigned to this instance of the command class. For
     * error handling or notifications through signals, this value should be unique throughout
     * the runtime
     */
    BrowserSearch(int id);

    /**
     * @brief BrowserSearch::start - This method opens one or more web links, specified in
     * the argument args using the selected browser also defined in args.
     *
     * @param args - QStringList containing the links to be opened. It must atleast contain
     * one link and only one browser to use.
     *
     * @return - a boolean indicating whether the command has/is being executed
     */
    bool start(QStringList *args);  //The method to start the execution of the browser search command
};

#endif // BROWSERSEARCH_H
