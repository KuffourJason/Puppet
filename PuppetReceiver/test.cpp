#include "test.h"

test::test()
{

}

void test::testSig(int h, QString stat)
{
    qDebug() << stat + QString::number(h);
}
