#include "Commands_h/openprogram.h"

OpenProgram::OpenProgram(int id)
{
    this->process = new QProcess();     //instantiates the inherited QProcess
    this->commandID = id;               //sets the commandID of this instance to id
    this->connectionSetup();            //connects this instance's slots to QProcess' signals
}

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

        this->statusInfo = (args->count() > 2) ? "Extra arguments ignored" : "";

        QStringList params = *args;  //gets the user supplied arguments
        QStringList arguments;  //contains the arguments to be supplied to the cmd program.

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
