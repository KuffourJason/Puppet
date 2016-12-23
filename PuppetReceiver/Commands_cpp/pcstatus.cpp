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

        QString program = "tasklist";
        this->process->start(program);
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

    QStringList temp1, temp2;

    temp1 << conOutput.split("\n");
    temp1.pop_front();
    temp1.pop_front();
    temp1.pop_front();
    temp1.pop_front();

    for(QString c: temp1){
        temp2 = c.split(" ", QString::SkipEmptyParts);

        if(temp2.size() >= 5){
            QString i = temp2.at(0) + " " + temp2.at(4) + " " + temp2.at(5);
            out << i.trimmed();
        }
    }

    qDebug() << out;
}
