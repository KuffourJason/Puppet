#include "Commands_h/browsersearch.h"

BrowserSearch::BrowserSearch(){

    BrowserSearch::process = new QProcess();

}

bool BrowserSearch::start(QList<QString> args) {

    //"C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe"

    if( BrowserSearch::process != NULL){

        BrowserSearch::process->start();
    }

    return true;
}

bool BrowserSearch::ended(){

    return true;
}

QString BrowserSearch::status(){

    return "";
}
