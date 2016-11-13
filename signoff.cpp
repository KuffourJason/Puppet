#include "signoff.h"
#include <QDebug>

SignOff::SignOff()
{

}

bool SignOff::start(){

    QSysInfo in;
    qDebug() << in.productType();
    return true;
}

bool SignOff::end(){
    return false;
}

bool SignOff::status(){
    return true;
}

QString SignOff::test(){
    return "hello world";
}
