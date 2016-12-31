#ifndef SEARCHFOLDER_H
#define SEARCHFOLDER_H

#include "macros.h"

/**
 * @brief The SearchFolder class - This is a helper class for the OpenProgram and MoveFOF classes.
 * It provides static methods which allows directories to be browsed in order to obtain the absolute
 * paths to them. It also provides a static method to access the paths to computer programs
 */
class SearchFolder
{
    public:

        /**
         * @brief startDirectory - This method lists all the files in the directory pointed to by
         * the dir parameter. This method should be invoked before the changeDirectory method, if
         * the callee has no path to a directory
         *
         * @param dir - the directory to display all the contents of
         *
         * @return - A QStringList of all the contents of the directory pointed to by dir. It also
         * adds the absolute path to the end of the QStringList, so that subsequent directories can
         * be searched
         */
        static QStringList startDirectory(QString dir);

        /**
         * @brief changeDirectory - This method lists all the directories pointed to by newDir and
         * also sets the current directory to newDir. Should be invoked after startDirectory if no
         * valid directory path is provided
         *
         * @param newDir - the new directory to display all the contents of
         *
         * @return A QStringList of all the contents of the directory pointed to by newDir. It also
         * adds the absolute path to the end of the QStringList, so that subsequent directories can
         * be searched
         */
        static QStringList changeDirectory(QString newDir);

        /**
         * @brief getProgramList - This method gets the list of programs on the computer system.
         * It obtains the list from the start menu folder in both the appdata folder and the
         * Program folder on windows systems
         *
         * @return - A QVector (2D array) of the absolute file paths to all programs on the system
         * The first index contains a QStringList of programs listed in the start menu while the
         * second index contains a QStringList of programs specific to each user. At the end of each
         * QStringList is the file path to each directory. Subsequent folders can be searched by using
         * the changeDirectory method.
         */
        static QVector<QStringList> getProgramList();

    private:
        SearchFolder();                 //constructor
        static QString currentDir;      //contains the path to the current directory being searched
        static QStringList programs1;   //contains the list of program shortcuts in the start menu
        static QStringList programs2;   //contains the list of program shortcuts in appdata
};

#endif // SEARCHFOLDER_H
