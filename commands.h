#ifndef COMMANDS_H
#define COMMANDS_H

#include <QObject>

class Commands: public QObject
{
    Q_OBJECT

public:
    virtual bool start() = 0;
    virtual bool status() = 0;
    virtual bool end() = 0;

    virtual QString test() = 0;
};

#endif // COMMANDS_H
