#ifndef SEARCHFOLDER_H
#define SEARCHFOLDER_H

#include <QStringList>
#include <QDir>
#include "macros.h"

class SearchFolder
{
    public:
        static QStringList startDirectory(QString dir);
        static QStringList changeDirectory(QString newDir);
        static QVector<QStringList> getProgramList();

    private:
        SearchFolder();
        static QString currentDir;
        static QStringList programs1;
        static QStringList programs2;
};

#endif // SEARCHFOLDER_H
