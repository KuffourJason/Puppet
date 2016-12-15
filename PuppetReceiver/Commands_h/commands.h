#ifndef COMMANDS_H
#define COMMANDS_H

#include <QObject>
#include <QProcess>
#include <QCoreApplication>
#include <QDebug>

#define SUCCESS       "The command executed successfully"
#define FAILEDTOSTART "The command failed to start"
#define CRASHED       "The command suddenly stopped working (crashed)"
#define TIMEDOUT      "The command stopped executing"
#define WRITEERROR    "The command failed (writing error)"
#define READERROR     "The command failed (reading error)"
#define UNKNOWNERROR  "The command has stopped working (unknown error)"

class Commands: public QObject
{
    Q_OBJECT

public:
    virtual bool start(QList<QString> *args) = 0;
    virtual QString status() = 0;
    virtual bool ended() = 0;

protected:
    void connectionSetup();

protected slots:
    void processStarted();
    void processStateChanged(QProcess::ProcessState newState);
    void processError(QProcess::ProcessError error);

signals:
    void processConditionChanged(int id);

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
 * Move files/folders
 * check pc status
 * open links/search for stuff in browser
 * download stuff
 * open programs
 * restrict access to some programs unless password provided
 * create to do lists with timers
 *
 */

#endif // COMMANDS_H
