#include "Commands_h/reboot.h"


Reboot::Reboot(int id)
{
    this->process = new QProcess();     //instantiates the inherited QProcess
    this->commandID = id;               //sets the commandID of this instance to id
    this->connectionSetup();            //connects this instance's slots to QProcess' signals
}

bool Reboot::start(QStringList *args = NULL)
{
    bool procStarted = false;  //return value indicates whether process was started

     //this is the number of seconds till the computer actually reboots. The default is defined as 30 seconds
    QString wait = "30";

    //if a parameter was given
    if(args != NULL)
    {
        //if a time to reboot was specified
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

    if( this->process != NULL){

        //Builds the arguments to be supplied to the cmd program. The command for shutdown is as
        //expected and the /r and /t indicate rebooting and time to reboot respectively
        QStringList arguments = QStringList() << SCRIPT << "SHUTDOWN.exe" << "/r" << "/t" << wait;


        this->process->start(CMD, arguments); //executes the command in the process
        procStarted = true; //sets the return value to true
    }
    return procStarted;
}
