#ifndef COMMANDS_H
#define COMMANDS_H

#include <QObject>
#include <QProcess>
#include <QCoreApplication>
#include <QDebug>
#include "macros.h"


/*
 *
 */
class Commands: public QObject
{
    Q_OBJECT

public:
    virtual bool start(QStringList *args) = 0;
    QString status();
    bool ended();
    void endProcess();

protected:
    void connectionSetup();

protected slots:
    void processStarted();
    void processStateChanged(QProcess::ProcessState newState);
    void processError(QProcess::ProcessError error);

signals:
    void processConditionChanged(int id, QString stat);

protected:
    QProcess *process = NULL;
    QString statusInfo = "";
    bool procEnded = false;
    int commandID = 0;
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
 * Move files/folders
 * download stuff
 * open programs
 * create to do lists with timers
 *
 */

#endif // COMMANDS_H
