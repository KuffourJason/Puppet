#include "Commands_h/signoff.h"
#include <QDebug>
#include <QProcess>
#include <QDir>

SignOff::SignOff(int id)
{
    this->process = new QProcess();
    this->commandID = id;
    this->connectionSetup();
}

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
