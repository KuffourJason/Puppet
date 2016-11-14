#include <QCoreApplication>
#include "signoff.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SignOff s;

    qDebug() << s.start();
    return a.exec();
}
