#include "Commands_h/browsersearch.h"
#include <QStringList>

BrowserSearch::BrowserSearch(int id){
    this->process = new QProcess();     //instantiates the inherited QProcess
    this->commandID = id;               //sets the commandID of this instance to id
    this->connectionSetup();            //connects this instance's slots to QProcess' signals
}

bool BrowserSearch::start(QStringList *args) {

    //args(0-?) - links to be opened

    bool procStarted = false;   //return value indicates whether process was started

    //checks if the browser and links to be opened are provided
    if( args->size() < 1){

        this->statusInfo = "Please include the link to be opened and the brower to open it with";
    }
    else if( this->process != NULL){ //checks if process was created first

        QStringList links = *args;      //gets the user supplied arguments
        QString browser = "chrome.exe";  //default browser of the system

        //Builds the arguments to be supplied to the cmd program. start is the cmd
        //command used to open the browser and specified links
        QStringList arguments = QStringList() << SCRIPT << "start" << browser << links ;

        this->process->start(CMD, arguments );  //executes the command in the process
        procStarted = true; //sets the return value to true
    }

    return procStarted;
}
