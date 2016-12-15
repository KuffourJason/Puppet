#include "Commands_h/signoff.h"
#include <QDebug>
#include <QProcess>
#include <QByteArray>
#include <QDir>

SignOff::SignOff()
{
    SignOff::process = new QProcess();
    this->connectionSetup();
}

bool SignOff::start( QList<QString> *args = NULL ){

    bool ret = false;

    if(args != NULL)
    {
        qDebug() << "Extra arguments ignored";
    }


    if( SignOff::process != NULL){

        // test.startDetached("shutdown -l");
        SignOff::process->start("explorer.exe");
        QString a = QString(SignOff::process->readAllStandardOutput() );

        qDebug() << SignOff::process->program();

        ret = true;
    }
    return ret;
}

bool SignOff::ended(){
    return SignOff::procEnded;
}

QString SignOff::status(){
    return SignOff::statusInfo;
}
