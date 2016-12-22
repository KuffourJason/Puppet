#include "Commands_h/turnoff.h"

TurnOff::TurnOff(int id)
{
    this->process = new QProcess();
    this->commandID = id;
    this->connectionSetup();
}

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
