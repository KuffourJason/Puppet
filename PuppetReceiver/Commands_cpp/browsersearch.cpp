#include "Commands_h/browsersearch.h"
#include <QStringList>

/**
 * @brief BrowserSearch::BrowserSearch
 * @param id
 */
BrowserSearch::BrowserSearch(int id){
    this->process = new QProcess();     //instantiates the inherited QProcess
    this->commandID = id;               //sets the commandID of this instance to id
    this->connectionSetup();            //connects this instance's slots to QProcess' signals
}

/**
 * @brief BrowserSearch::start -
 * @param args
 * @return
 */
bool BrowserSearch::start(QStringList *args) {

    //args(0-?) - links to be opened

    bool procStarted = false;

    if( args->size() < 1){
        this->statusInfo = "Please include the link to be opened";
    }
    else if( this->process != NULL){

        QString program = "";
        QStringList links = *args;

        if( QDir().exists(ROOT + PROGRAM_32 + CHROME) ){
            program = ROOT + PROGRAM_32 + CHROME;
        }
        else if( QDir().exists(ROOT + PROGRAM_64 + CHROME) ){
            program = ROOT + PROGRAM_64 + CHROME;
        }
        else if( QDir().exists(ROOT + PROGRAM_32 + FIREFOX) ){
            program = ROOT + PROGRAM_32 + FIREFOX;
        }
        else if( QDir().exists(ROOT + PROGRAM_64 + FIREFOX) ){
            program = ROOT + PROGRAM_64 + FIREFOX;
        }
        else if( QDir().exists(ROOT + PROGRAM_64 + EDGE) ){
            program = ROOT + PROGRAM_64 + EDGE;
        }
        else if( QDir().exists(ROOT + PROGRAM_64 + EDGE) ){
            program = ROOT + PROGRAM_64 + EDGE;
        }

        if( !program.isEmpty() ){
            qDebug() << program;
            this->process->start(program, QStringList() << links);
            procStarted = true;
        }
    }

    return procStarted;
}
