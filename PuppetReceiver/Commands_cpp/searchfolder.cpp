#include "Commands_h/SearchFolder.h"

QStringList SearchFolder::startDirectory(QString dir = "")
{
    QDir d("");

    if(dir.isEmpty()){
       d.setPath(HOME);
       currentDir = HOME;
    }
    else{
       d.setPath(dir);
       currentDir = dir;
    }

    return d.entryList() << currentDir;
}

QStringList SearchFolder::changeDirectory(QString newDir)
{
    QDir newD("");
    newD.setPath(newDir);
    currentDir = newDir;

    return newD.entryList() << currentDir;
}

QVector<QStringList> SearchFolder::getProgramList()
{
    if(programs1.isEmpty() || programs2.isEmpty()){

        QDir pro1(PROGRAMS_1);
        programs1 << pro1.entryList() << PROGRAMS_1;

        QDir pro2(PROGRAMS_1);
        programs2 << pro2.entryList() << PROGRAMS_2;
    }

    QVector<QStringList> ret(2);
    ret.insert(0, programs1);
    ret.insert(1, programs2);

    return ret;
}


QString SearchFolder::currentDir = "";
QStringList SearchFolder::programs1;
QStringList SearchFolder::programs2;
