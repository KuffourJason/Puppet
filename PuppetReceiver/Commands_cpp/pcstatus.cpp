#include "Commands_h/pcstatus.h"

PCStatus::PCStatus(int id)
{
    this->process = new QProcess();
    this->commandID = id;
    this->connectionSetup();

    this->connect( this->process, &QProcess::readChannelFinished, this, &PCStatus::outputGo );
}

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
