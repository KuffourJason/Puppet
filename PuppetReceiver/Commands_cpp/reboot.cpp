#include "Commands_h/reboot.h"

/**
 * @brief Reboot::Reboot
 * @param id
 */
Reboot::Reboot(int id)
{
    this->process = new QProcess();     //instantiates the inherited QProcess
    this->commandID = id;               //sets the commandID of this instance to id
    this->connectionSetup();            //connects this instance's slots to QProcess' signals
}

/**
 * @brief Reboot::start
 * @param args
 * @return
 */
bool Reboot::start(QStringList *args)
{
    bool ret = false;

    if(args != NULL)
    {
        qDebug() << "Extra arguments ignored";
    }

    if( this->process != NULL){
        this->process->start("shutdown /r /t", QStringList() << 0); //the 0 seconds specifies the time to wait before restart
        ret = true;
    }
    return ret;
}
