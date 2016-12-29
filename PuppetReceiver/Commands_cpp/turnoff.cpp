#include "Commands_h/turnoff.h"

/**
 * @brief TurnOff::TurnOff -
 *
 * @param id - An int value to be assigned to this instance of the command class. For
 * error handling or notifications through signals, this value should be unique throughout
 * the runtime
 */
TurnOff::TurnOff(int id)
{
    this->process = new QProcess();     //instantiates the inherited QProcess
    this->commandID = id;               //sets the commandID of this instance to id
    this->connectionSetup();            //connects this instance's slots to QProcess' signals
}

/**
 * @brief TurnOff::start -
 *
 * @param args -
 *
 * @return
 */
bool TurnOff::start(QStringList *args = NULL)
{
    bool ret = false;
    QString wait = "";

    if(args != NULL)
    {
        wait = args->isEmpty() ? "30" : args->at(0);
    }

    //checks if the browser and links to be opened are provided
    if( this->process != NULL){

        QStringList arguments = QStringList() << SCRIPT << "shutdown" << "/s" << "/t" << wait;
        this->process->start(CMD, arguments );
        ret = true;
    }
    return ret;
}
