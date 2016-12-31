#include <QCoreApplication>
#include "Commands_cpp/signoff.cpp"
#include "Commands_cpp/turnoff.cpp"
#include <QDebug>
#include "Commands_cpp/browsersearch.cpp"
#include "Commands_cpp/reboot.cpp"
#include "test.cpp"
#include "Commands_cpp/pcstatus.cpp"
#include "Commands_cpp/openprogram.cpp"
#include "Commands_cpp/searchfolder.cpp"
#include "Commands_cpp/movefof.cpp"

#define NO_ARGS NULL

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BrowserSearch s(1);
    QStringList *f = new QStringList();
    f->append("http://doc.qt.io/qt-5/qtwidgets-dialogs-findfiles-example.html");
    f->append("http://www.google.com");

    //PCStatus p(2);

    //TurnOff r(3);
    //r.start(&(QStringList() << "720") );
    qDebug() << s.start(f);

//    MoveFOF test(20);
//    QStringList *w = new QStringList();
//    w->append(DESKTOP + "\\desktop.docx");
//    w->append("C:\\Users\\jay\\Desktop\\practice");

    //test.start(w);

    return a.exec();
}
