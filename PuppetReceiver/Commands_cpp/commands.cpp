#include "Commands_h/commands.h"

void Commands::connectionSetup()
{
    connect( this->process, &QProcess::started,       this, &Commands::processStarted      );
    connect( this->process, &QProcess::stateChanged,  this, &Commands::processStateChanged );
    connect( this->process, &QProcess::errorOccurred, this, &Commands::processError        );
}

void Commands::processStarted()
{
    this->statusInfo = "Command execution has begun";
}

void Commands::processStateChanged(QProcess::ProcessState newState)
{
        if(newState == QProcess::Starting){

        }
        else if(newState == QProcess::NotRunning){

            if(QProcess::NormalExit == this->process->exitStatus()){
                this->statusInfo = SUCCESS;
            }
            else if(QProcess::CrashExit == this->process->exitStatus()){
                 this->statusInfo = CRASHED;
            }

        }
        else if(newState == QProcess::Running){
            this->procEnded = true;
        }
}

void Commands::processError(QProcess::ProcessError error)
{
    if(error == QProcess::FailedToStart){
        this->statusInfo = FAILEDTOSTART;
    }
    else if(error == QProcess::Crashed){
        this->statusInfo = CRASHED;
    }
    else if(error == QProcess::Timedout){
        this->statusInfo = TIMEDOUT;
    }
    else if(error == QProcess::WriteError){
        this->statusInfo = WRITEERROR;
    }
    else if(error == QProcess::ReadError){
        this->statusInfo = READERROR;
    }
    else if(error == QProcess::UnknownError){
        this->statusInfo = UNKNOWNERROR;
    }
}
