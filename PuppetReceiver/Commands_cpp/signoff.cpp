#include "Commands_h/signoff.h"
#include <QDebug>
#include <QProcess>

/**
 * @brief SignOff::SignOff
 * @param id
 */
SignOff::SignOff(int id)
{
    this->process = new QProcess();     //instantiates the inherited QProcess
    this->commandID = id;               //sets the commandID of this instance to id
    this->connectionSetup();            //connects this instance's slots to QProcess' signals
}

/**
 * @brief SignOff::start
 * @param args
 * @return
 */
bool SignOff::start( QStringList *args = NULL ){

    bool ret = false;
    QString wait = "";

    if(args != NULL)
    {
        wait = args->isEmpty() ? "30" : args->at(0);
    }

    if( this->process != NULL){
        this->process->start(CMD, QStringList() << SCRIPT << "shutdown" << "/l" << "/t" << wait);
        ret = true;
    }
    return ret;
}
