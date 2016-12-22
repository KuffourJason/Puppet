#include "Commands_h/reboot.h"

Reboot::Reboot(int id)
{
    this->commandID = id;
    this->process = new QProcess();
    this->connectionSetup();
}

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
