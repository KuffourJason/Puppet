#include "Commands_h/movefof.h"

/**
 * @brief MoveFOF::MoveFOF - The constructor for the MoveFOF class. It assigns the commandID
 *
 * @param id - An int value to be assigned to this instance of the command class. For
 * error handling or notifications through signals, this value should be unique throughout
 * the runtime
 */
MoveFOF::MoveFOF(int id)
{
    //this->process = new QProcess();     //instantiates the inherited QProcess
    this->commandID = id;               //sets the commandID of this instance to id
    //this->connectionSetup();            //connects this instance's slots to QProcess' signals
}

/**
 * @brief MoveFOF::start - This method moves a file from one location to another destination.
 *
 * @param args - QStringList containing the file to be moved, at index 0, and the new destination
 * the file is to be moved to, at index 1
 *
 * @return - a boolean indicating whether the command has/is being executed
 */
bool MoveFOF::start(QStringList *args)
{
    //args[0] - the file/folder to be moved
    //args[1] - the destination to which it is to be moved

    bool procStarted =  false; //return value indicates whether process was started

    //checks if the file and new destination are provided
    if(args->count() < 2){

        this->statusInfo = "Please include the file to move and its new destination";
    }
    else{

        QString filePath = args->at(0);   //gets the path of the file to be moved from the args
        QString destination = args->at(1); //get the path of the new file destination
        QDir file(filePath);                //create file object to the file, to make moving it easier

        //moves the file to it's new destination. Stores whether it succeeded in procStarted
        procStarted = file.rename( file.absolutePath(), destination + "\\" + file.dirName() );
    }

    return procStarted;
}
