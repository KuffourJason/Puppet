#include "Commands_h/openprogram.h"

/**
 * @brief OpenProgram::OpenProgram - The constructor for the OpenProgram class. It
 * connects the necessary signals and slots, setups up the QProcess and assigns the commandID
 *
 * @param id - An int value to be assigned to this instance of the command class. For
 * error handling or notifications through signals, this value should be unique throughout
 * the runtime
 */
OpenProgram::OpenProgram(int id)
{
    this->process = new QProcess();     //instantiates the inherited QProcess
    this->commandID = id;               //sets the commandID of this instance to id
    this->connectionSetup();            //connects this instance's slots to QProcess' signals
}

/**
 * @brief OpenProgram::start - This method opens the specified program/file in another process
 *
 * @param args - QStringList containing the directory path of the program/file to open, at index 1,
 * and an indicator whether it is a program (use P) or file ( use F) at index 0
 *
 * @return - a boolean indicating whether the command has/is being executed
 */
bool OpenProgram::start(QStringList *args)
{
    //arg[0] indicates whether to open a file or program, possible values F or P
    //arg[1] the file/program to open

    bool procStarted = false;  //return value indicates whether process was started

    //checks if the both the program/file to be opened is provided and whether its a
    //a program (P) or a file (F)
    if(args->count() < 2){
        this->statusInfo = "Please provide the program/file to open and an indicator (P or F)";
    }
    else if(this->process != NULL){  //checks if process was created first

        QStringList params = *args;  //gets the user supplied arguments
        QStringList arguments = "";  //contains the arguments to be supplied to the cmd program.

        //checks if the thing to be opened is a file
        if( params.at(0) == "F" ){

            //files require the use of the start module to be opened
            arguments = QStringList() << SCRIPT << "start" << params.at(1);
        }
        else{ //checks if it is a program

            //programs do not require the use of start module because it is a link
            arguments = QStringList() << SCRIPT << params.at(1);
        }

        this->process->start(CMD, arguments ); //executes the command in the process
        procStarted = true;  //sets the return value to true
    }

    return procStarted;
}
