#include <iostream>

#include <QJsonDocument>
#include <QApplication>
#include <QDebug>

#include "plantsgui.h"

#include <QTableWidget>
#include <QTableWidgetItem>

int main(int argc,  char *argv[])
{
    QApplication app(argc, argv);

    PlantsGUI plantsUI;
    plantsUI.show();


    return app.exec();
}
