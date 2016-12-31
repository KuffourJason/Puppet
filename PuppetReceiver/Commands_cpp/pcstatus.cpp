#include "Commands_h/pcstatus.h"

PCStatus::PCStatus(int id)
{
    this->process = new QProcess();     //instantiates the inherited QProcess
    this->commandID = id;               //sets the commandID of this instance to id
    this->connectionSetup();            //connects this instance's slots to QProcess' signals

    //this connects the signal, which is emitted when the all the output of a process is available,
    //to the outputGo slot defined in PCStatus
    this->connect( this->process, &QProcess::readChannelFinished, this, &PCStatus::taskInfo );
}

bool PCStatus::start(QStringList *args = NULL)
{
    bool procStarted = false;  //return value indicates whether process was started

    if(args != NULL){
        this->statusInfo = "Extra arguments ignored";
    }

    //checks if process was created first
    if( this->process != NULL){

        //Builds the arguments to be supplied to the cmd program. tasklist is the cmd
        //command used to get the task manager like information for the computer
        QStringList arguments = QStringList() << SCRIPT << "tasklist" << "-v" << "/FO" << "LIST";

        this->process->start(CMD, arguments); //executes the command in the process
        procStarted = true;  //sets the return value to true
    }
    else{
        //if process was not created
    }
    return procStarted;
}

void PCStatus::taskInfo()
{
    QString consoleOutput = this->process->readAllStandardOutput(); //gets the task manager information from the process

    //splits the string in consoleOutput into rows and stores it in a QStringList (arrayList)
    QStringList temp = QStringList() << consoleOutput.split("\n");

    QStringList output = QStringList();

    //Loops over the QStringList temp and removes unnecessary info for each task
    for(QString row: temp){

        //Removes rows that contain the session #, PID and status which is unnecessary
        if( row.contains("Session") || row.contains("PID") || row.contains("Status") ){

        }
        else{
            output << row.trimmed();//saves the necessary data into the QStringList out
        }
    }

    //notifies and gives the callee the task info is available
    emit this->taskInfoReady( this->commandID, output );
    qDebug() << output;
}
