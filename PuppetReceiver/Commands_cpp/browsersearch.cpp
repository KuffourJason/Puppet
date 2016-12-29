#include "Commands_h/browsersearch.h"
#include <QStringList>

/**
 * @brief BrowserSearch::BrowserSearch - The constructor for the BrowserSearch class. It
 * connects the necessary signals and slots, setups up the QProcess and assigns the commandID
 *
 * @param id - An int value to be assigned to this instance of the command class. For
 * error handling or notifications through signals, this value should be unique throughout
 * the runtime
 */
BrowserSearch::BrowserSearch(int id){
    this->process = new QProcess();     //instantiates the inherited QProcess
    this->commandID = id;               //sets the commandID of this instance to id
    this->connectionSetup();            //connects this instance's slots to QProcess' signals
}

/**
 * @brief BrowserSearch::start - This method opens one or more web links, specified in
 * the argument args using the selected browser also defined in args.
 *
 * @param args - QStringList containing the browser to use at index 0 and the links to
 * be opened in the subsequent indices. It must atleast contain one link and only one browser
 * to use. Possible values for browsers include chrome, firefox and iexplorer
 *
 * @return - a boolean indicating whether the command has/is being executed
 */
bool BrowserSearch::start(QStringList *args) {

    //args(0)   - the browser to open the links in
        //possibles values are chrome, firefox and iexplorer
    //args(1-?) - links to be opened

    bool procStarted = false;   //return value indicates whether process was started

    //checks if the browser and links to be opened are provided
    if( args->size() < 2){

        this->statusInfo = "Please include the link to be opened and the brower to open it with";
    }
    else if( this->process != NULL){ //checks if process was created first

        QStringList links = *args;      //gets the user supplied arguments
        QString browser = links.takeFirst() + ".exe";  //gets the browser to open from the arguments

        /*
         * NEED TO DEFINE SOMETHING HERE TO USE MORE BROWSERS IF POSSIBLE
         *
         */
        qDebug() << OS_VERSION;

        //Builds the arguments to be supplied to the cmd program. start is the cmd
        //command used to open the browser and specified links
        QStringList arguments = QStringList() << SCRIPT << "start" << browser << links ;

        this->process->start(CMD, arguments );  //executes the command in the process
        procStarted = true; //sets the return value to true
    }

    return procStarted;
}
