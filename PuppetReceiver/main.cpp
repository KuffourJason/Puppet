#include <QCoreApplication>
#include "Commands_cpp/signoff.cpp"
#include <QDebug>
#include "Commands_cpp/browsersearch.cpp"
#include "test.cpp"

#include "Commands_cpp/pcstatus.cpp"

#define NO_ARGS NULL

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BrowserSearch s(1);
    QStringList *f = new QStringList();
    f->append("http://doc.qt.io/qt-5/qtwidgets-dialogs-findfiles-example.html");

    //PCStatus p(2);

    qDebug() << s.start(f);


    return a.exec();
}
