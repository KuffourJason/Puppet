#include "Commands_h/pcstatus.h"

/**
 * @brief PCStatus::PCStatus
 * @param id
 */
PCStatus::PCStatus(int id)
{
    this->process = new QProcess();     //instantiates the inherited QProcess
    this->commandID = id;               //sets the commandID of this instance to id
    this->connectionSetup();            //connects this instance's slots to QProcess' signals

    //this connects the signal, which is emitted when the all the output of a process is available,
    //to the outputGo slot defined in PCStatus
    this->connect( this->process, &QProcess::readChannelFinished, this, &PCStatus::outputGo );
}

/**
 * @brief PCStatus::start
 * @param args
 * @return
 */
bool PCStatus::start(QStringList *args = NULL)
{
    bool procStarted = false;

    if( this->process != NULL){

        this->process->start(CMD, QStringList() << SCRIPT << "tasklist" << "-v" << "/FO" << "LIST");
        procStarted = true;
    }
    else{
        procStarted = false;
    }
    return procStarted;
}

/**
 * @brief PCStatus::outputGo
 */
void PCStatus::outputGo()
{
    QString conOutput;
    conOutput = this->process->readAllStandardOutput();


    QStringList temp1;

    temp1 << conOutput.split("\n");

    for(QString c: temp1){

        if( c.contains("Session") || c.contains("PID") || c.contains("Status") ){

        }
        else{
            this->out << c.trimmed();
        }
    }

    qDebug() << this->out;
}
