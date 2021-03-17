#include <iostream>
#include "aircraft.h"
#include "controller.h"
#include "CustomExceptions.h"

#include <QJsonDocument>
int main()
{
    system("color f4");
    std::cout << "Hello World!\n";

    {
        Controller ctrl;
        auto h1=std::make_shared<Helicopter>("1", "model1", 1);
        ctrl.add(h1);

        // just a test to display helicopter h1 as a json
        QJsonObject h1JsonObj = h1->toJsonObject(); // using the toJsonObject function to get the json representation of h1
        QJsonDocument doc(h1JsonObj); // we are creating a QJsonDocument of h1JsonObj QJsonObject , because only QJsonDocument has functions which allows us to convert it to a string
        // QJsonDocument::toJson method converts a QJsonDocument to a QString
        // we are displaying this QString object to the console
        // we need to call toStdString();  to convert the QString to std::string because QString has no viable overload for <<
        cout<<doc.toJson(QJsonDocument::Indented).toStdString();
        // end json test

        std::shared_ptr<HotAirBalloon> b1 = std::make_shared<HotAirBalloon>("1", "model2", 20);
        ctrl.add(b1);

        // save the entire repo to a json document
        ctrl.saveToJsonFile("test.json");
        try {
            ctrl.loadRepo("C:\\Users\\User\\Desktop\\data_seminar9\\data.csv");
        }
        catch (FileException& e) {
            cout << e.what();
        }
        ctrl.displayAll();
    }
    _CrtDumpMemoryLeaks();
}
