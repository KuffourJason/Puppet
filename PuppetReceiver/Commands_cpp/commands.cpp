#include "Commands_h/commands.h"

/**
 * @brief Commands::connectionSetup - The method connects the QProcess signals: started, stateChanged
 * and errorOccurred to their corresponding slots defined in the Command class
 *
 */
void Commands::connectionSetup()
{
    connect( this->process, &QProcess::started,       this, &Commands::processStarted      );
    connect( this->process, &QProcess::stateChanged,  this, &Commands::processStateChanged );
    connect( this->process, &QProcess::errorOccurred, this, &Commands::processError        );
}

/**
 * @brief Commands::ended - This method indicates whether a command has ended
 * @return - a boolean indicating whether the process/command has ended
 */
bool Commands::ended()
{
    return this->procEnded;
}

/**
 * @brief Commands::status - This method returns the current status of the command
 * @return - A string containing detailed information about the status of the process/command
 */
QString Commands::status()
{
    return this->statusInfo;
}

/**
 * @brief Commands::endProcess - The exits the process/command executing
 */
void Commands::endProcess()
{
    this->process->kill();
}

/**
 * @brief Commands::processStarted - This slot is executed whenever the process has begun executing
 */
void Commands::processStarted()
{
    this->statusInfo = "Command " + QString::number(this->commandID) + " execution has begun";
}

/**
 * @brief Commands::processStateChanged - This slot is executed whenever the process' state has changed.
 * It is executed when the process is starting, not running or running. If the process is not running then
 * it emits the signal processConditionChanged
 * @param newState - the state to which the process is transitioning to
 */
void Commands::processStateChanged(QProcess::ProcessState newState)
{
    if(newState == QProcess::Starting){
        //the process is starting
    }
    else if(newState == QProcess::NotRunning){
        //the process is not running, meaning it has either ended or crashed

        if(QProcess::NormalExit == this->process->exitStatus()){
            //exited normally
            this->statusInfo = SUCCESS;
        }
        else if(QProcess::CrashExit == this->process->exitStatus()){
            /*crashed. On windows, using the kill() method to end a process causes it to have
             *crash exit. Hence the case where the process has crashed is handled by the slot
             *processError
             */
        }

        //Notifies callee that the process has ended and/or an error has occured
        emit this->processConditionChanged(this->commandID, this->statusInfo);
    }
    else if(newState == QProcess::Running){
       /*the process is currently executing
        *For some commands, this signals that it is done executing
        *while for others it doesn't. This case handles the former
        */
        this->procEnded = true;
    }
}

/**
 * @brief Commands::processError - This slot is for the signal errorOccurred which is emitted by QProcess.
 * This method converts the error code to a readable string and stores it in the attribute status.
 * @param error - The error that caused the process to terminate
 */
void Commands::processError(QProcess::ProcessError error)
{
    if(error == QProcess::FailedToStart){
        //the process failed to start
        this->statusInfo = FAILEDTOSTART;
    }
    else if(error == QProcess::Crashed){
        //the process crashed
        this->statusInfo = CRASHED;
    }
    else if(error == QProcess::Timedout){
        //the process took too long to respond
        this->statusInfo = TIMEDOUT;
    }
    else if(error == QProcess::WriteError){
        //the process failed to write something
        this->statusInfo = WRITEERROR;
    }
    else if(error == QProcess::ReadError){
        //the process failed to read something
        this->statusInfo = READERROR;
    }
    else if(error == QProcess::UnknownError){
        //there was an unknown error
        this->statusInfo = UNKNOWNERROR;
    }
}

