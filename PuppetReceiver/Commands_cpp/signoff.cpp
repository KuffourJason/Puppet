#include "Commands_h/signoff.h"
#include <QDebug>
#include <QProcess>

SignOff::SignOff(int id)
{
    this->process = new QProcess();     //instantiates the inherited QProcess
    this->commandID = id;               //sets the commandID of this instance to id
    this->connectionSetup();            //connects this instance's slots to QProcess' signals
}

bool SignOff::start( QStringList *args = NULL ){

    bool procStarted = false; //return value indicates whether process was started

    //if a parameter was given
    if(args != NULL)
    {
        this->statusInfo = "Extra arguments ignored";
    }

    if( this->process != NULL){

        //Builds the arguments to be supplied to the cmd program. The command for shutdown is as
        //expected and the /l means signing out
        QStringList arguments = QStringList() << SCRIPT << "SHUTDOWN.exe" << "/l";

        qDebug() << arguments;

        this->process->start(CMD, arguments);  //executes the command in the process
        procStarted = true; //sets the return value to true
    }

    return procStarted;
}
