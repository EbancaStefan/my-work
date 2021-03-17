#include "controller.h"

#include "Controller.h"
#include <algorithm>
#include <memory>
#include <fstream>
#include <sstream>
#include "CustomExceptions.h"
using namespace std;

#include <QJsonDocument>

Controller::Controller()
{
}


Controller::~Controller()
{
}

void Controller::add(std::shared_ptr<Aircraft> aircraft)
{
    m_repo.push_back(aircraft);
}

std::vector<std::shared_ptr<Aircraft>> Controller::filterByActivity(const string& activity)
{
    vector<shared_ptr<Aircraft>> result;
    return result;
}

void Controller::displayAll()
{
    for (shared_ptr<Aircraft> a : m_repo) {
        std::string str = (*a).toString();
        std::cout << str<<"\n";
    }
}

bool Controller::saveToJsonFile(string jsonPath)
{
    QJsonObject rootObj; // creating the root json array
    rootObj["numAircrafts"] = static_cast<int>(m_repo.size()); // saving the number of aircrafts in the repo

    QJsonArray aircraftsJsonArray; // a QJsonArray to store all the aircrafts from the repo
    for (shared_ptr<Aircraft> a : m_repo) {
        aircraftsJsonArray.push_back((*a).toJsonObject()); // adding the json representation of aircraft a to aircraftsJsonArray
    }
    rootObj["aircrafts"] = aircraftsJsonArray; // adding the aircraftsJsonArray to the root json object
    // creating a QJsonDocument to store teh entire json document
    QJsonDocument jsonDoc{rootObj};
    QString jsonStr = jsonDoc.toJson(QJsonDocument::Indented); // getting the QString represention of this QJsonDocument

    // saving the jsonStr to a jsonPath file
    ofstream outFile{jsonPath};
    if(!outFile.is_open())
        return false;
    outFile<<jsonStr.toStdString();
    outFile.close();
    return true;
}

void Controller::loadRepo(std::string document)
{
    ifstream reading_file(document);
    if (reading_file.is_open())
    {
        std::string line;
        std::vector<std::string> elems;
        while (std::getline(reading_file, line)) {
            elems = tokenize_cs_line(line);
            if (elems.empty())
                throw OutofBoundException();
            if (elems[0] == "balloon")
            {
                try {
                    m_repo.push_back(std::make_shared<HotAirBalloon>(elems[1], elems[1], 21));
                    (*m_repo[m_repo.size() - 1]).set_image_path(elems[2]);
                }
                catch (out_of_range& e) {
                    throw OutofBoundException();
                }
            }
        }

    }
    else
        throw FileException(document);
    
}

std::vector<std::string> Controller::tokenize_cs_line(std::string line)
{
    std::vector<std::string> results;
    std::string temp;
    std::stringstream X(line);
    while (std::getline(X, temp, ','))
        results.push_back(temp);
    return results;
}
