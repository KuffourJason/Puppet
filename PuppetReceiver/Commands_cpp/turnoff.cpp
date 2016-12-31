#include "Commands_h/turnoff.h"

TurnOff::TurnOff(int id)
{
    this->process = new QProcess();     //instantiates the inherited QProcess
    this->commandID = id;               //sets the commandID of this instance to id
    this->connectionSetup();            //connects this instance's slots to QProcess' signals
}

bool TurnOff::start(QStringList *args = NULL)
{
    //return value indicates whether process was started
    bool procStarted = false;

    //this is the number of seconds till the computer actually shutsdown. The default is defined as 30 seconds
    QString wait = "30";

    //if a parameter was given
    if(args != NULL)
    {
        //if a time to turn off was specified
        if(args->count() > 0){

            this->statusInfo = (args->count() > 1) ? "Extra arguments ignored" : "";

            QString timeout = args->at(0);      //gets the user supplied value

            bool check;     //used to store the result of whether the conversion was a success for below
            int num = timeout.toInt(&check); //converts the user supplied value from a string to int

            //if the conversion succeeded
            if(check){
                wait = (num < 30) ? "30" : QString::number(num%600); //ensures the timeout is between 30 and 600 seconds
            }
            else{
                //if conversion failed, then default of 30 seconds is used
            }
        }
        else{
                //if the parameter is empty, then default of 30 seconds is used
        }
    }

    //checks if the browser and links to be opened are provided
    if( this->process != NULL){

        //Builds the arguments to be supplied to the cmd program. The command for shutdown is as
        //expected and the /s and /t indicate shutting down and time till shutdown respectively
         QStringList arguments = QStringList() << SCRIPT << "SHUTDOWN.exe" << "/s" << "/t" << wait;

         this->process->start(CMD, arguments); //executes the command in the process
         procStarted = true; //sets the return value to true
    }
    return procStarted;
}
