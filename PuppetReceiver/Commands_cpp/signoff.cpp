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

    if(args != NULL)
    {
        qDebug() << "Extra arguments ignored";
    }

    if( this->process != NULL){
        this->process->start("shutdown -l");
        ret = true;
    }
    return ret;
}
