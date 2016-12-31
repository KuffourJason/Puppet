#include "Commands_h/SearchFolder.h"

QStringList SearchFolder::startDirectory(QString dir = "")
{
    QDir d("");     //creates a QDir object and points it to the program's working directory

    //if no starting directory is provided or if that directory does not exist
    if(dir.isEmpty() || QDir(dir).exists()){

       //set the current directory to the system's home directory
       d.setPath(HOME);
       currentDir = HOME;
    }
    else{ //a valid directory path is provided

       d.setPath(dir);
       currentDir = dir;
    }

    //returns the contents of the current directory and its directory path
    return d.entryList() << currentDir;
}

QStringList SearchFolder::changeDirectory(QString newDir)
{
    QDir newD("");

    //if the newDir is a valid directory
    if( QDir(newDir).exists()){

        //changes the current directory to newDir
        newD.setPath(newDir);
        currentDir = newDir;
    }
    else{ //if newDir is invalid then keep the current dir the same
        newD.setPath(currentDir);
    }

    //returns the contents of the current directory and its directory path
    return newD.entryList() << currentDir;
}

QVector<QStringList> SearchFolder::getProgramList()
{
    //if either program lists are empty, populate them with the
    //system's available programs. Should only be done once in each
    //execution
    if(programs1.isEmpty() || programs2.isEmpty()){

        QDir pro1(PROGRAMS_1);
        programs1 << pro1.entryList() << PROGRAMS_1; //adds the directory path to the end of the list

        QDir pro2(PROGRAMS_1);
        programs2 << pro2.entryList() << PROGRAMS_2; //adds the directory path to the end of the list
    }

    //returns the list of both programs in a QVector which is basically a 2D array
    QVector<QStringList> ret(2);
    ret.insert(0, programs1);
    ret.insert(1, programs2);

    return ret;
}


QString SearchFolder::currentDir = "";
QStringList SearchFolder::programs1;
QStringList SearchFolder::programs2;
