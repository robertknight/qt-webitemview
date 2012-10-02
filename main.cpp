#include <QtGui/QApplication>

#include "testwebitemview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TestWebItemView w;
    w.show();
    return a.exec();
}

