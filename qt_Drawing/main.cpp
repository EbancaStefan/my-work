#include "drawwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DrawingWidget w;
    w.show();
    return a.exec();
}
