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
bool Reboot::start(QStringList *args = NULL)
{
    //arg[0] is the seconds the process waits until it reboots
    //default is 30 seconds
    bool ret = false;
    QString wait = "30";

    if(args != NULL)
    {
        wait = args->isEmpty() ? "" : args->at(0);
    }

    if( this->process != NULL){
        this->process->start(CMD, QStringList() << SCRIPT << "SHUTDOWN.exe" << "/r" << "/t" << wait); //the 0 seconds specifies the time to wait before restart
        ret = true;
    }
    return ret;
}
