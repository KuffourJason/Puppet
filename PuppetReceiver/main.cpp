#include <QCoreApplication>
#include "Commands_cpp/signoff.cpp"
#include <QDebug>
#include "Commands_cpp/browsersearch.cpp"

#define NO_ARGS NULL

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SignOff s;

    qDebug() << s.start( new QList<QString>() );

    while( s.ended() != true ){
        qDebug() << "one";
    }

    qDebug() << s.status();
    return a.exec();
}
