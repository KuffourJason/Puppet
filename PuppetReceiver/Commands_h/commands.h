#ifndef COMMANDS_H
#define COMMANDS_H

#include <QObject>
#include <QProcess>
#include <QCoreApplication>
#include <QDebug>
#include "macros.h"


/**
 * @brief The Commands class - This is an abstract class that all commands must inherit from it.
 * It has one virtual method named start that must be implemented by all subclasses.
 */
class Commands: public QObject
{
    Q_OBJECT

public:
    virtual bool start(QStringList *args) = 0;  //The method to start the execution of a command
    QString status();                           //the current status of the command being executed
    bool ended();                               //indicates whether the command has been executed
    void endProcess();                          //This method shuts down the process in which the commmand is executing

protected:
    void connectionSetup();                     //The method connects the necessary signals to the slots

protected slots:
    void processStarted();                      //slot for the process started signal
    void processStateChanged(QProcess::ProcessState newState);  //slot for the process state changed signal. Used to
                                                                //determine if a process is still executing or has ended
    void processError(QProcess::ProcessError error);    //slot for when an error occurs in the process

signals:
    void processConditionChanged(int id, QString stat); //this signal is emitted when something has occured with
                                                        //the process executing the command

protected:
    QProcess *process = NULL;   //the process in which the command will be executed
    QString statusInfo = "";    //the current status of the process
    bool procEnded = false;     //indicates whether the process/command has exited
    int commandID = 0;          //the id of the command being executed
};

/*
 *Possible commands
 *
 * Turn off
 * Reboot
 * check pc status
 * open links/search for stuff in browser
 * Signout
 *
 * open programs
 *
 * Move files/folders
 * create to do lists with timers
 *
 */

#endif // COMMANDS_H
