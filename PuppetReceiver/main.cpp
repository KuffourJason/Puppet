#include <QCoreApplication>
#include "Commands_cpp/signoff.cpp"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SignOff s;

    qDebug() << s.start();
    return a.exec();
}
