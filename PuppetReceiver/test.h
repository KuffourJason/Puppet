#ifndef TEST_H
#define TEST_H

#include <QDebug>
#include <QObject>

class test : public QObject
{
    Q_OBJECT

public:
    test();

public slots:
    void testSig(int h, QString stat);
};

#endif // TEST_H
