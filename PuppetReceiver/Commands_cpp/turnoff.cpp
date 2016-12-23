#include "Commands_h/turnoff.h"

/**
 * @brief TurnOff::TurnOff
 * @param id
 */
TurnOff::TurnOff(int id)
{
    this->process = new QProcess();     //instantiates the inherited QProcess
    this->commandID = id;               //sets the commandID of this instance to id
    this->connectionSetup();            //connects this instance's slots to QProcess' signals
}

/**
 * @brief TurnOff::start
 * @param args
 * @return
 */
bool TurnOff::start(QStringList *args = NULL)
{
    bool ret = false;

    if(args != NULL)
    {
        qDebug() << "Extra arguments ignored";
    }

    if( this->process != NULL){
        this->process->start("shutdown /s");
        ret = true;
    }
    return ret;
}
