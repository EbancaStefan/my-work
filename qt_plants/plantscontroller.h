#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "plant.h"
#include <vector>
#include <iostream>
#include <QVector>
#include <set> // STL
#include <unordered_set>
class PlantsController
{
public:
    PlantsController();
    ~PlantsController();

    bool dumpToJson(QString jsonPath);

    bool addPlant(Plant pl);
    bool removePlant(QString scientificName);

    bool saveToFile(QString filepath);

    QStringList getPlantFamilies();

    const QVector<Plant> &repo();
    bool addToToStudy(Plant pl){

        auto res = m_toStudyAbout.insert(pl);



        // res - pair : first element iterator to position of the element
        // second element is a bool -> was the element inserted

        for(Plant pl: m_toStudyAbout){
            std::cout<<pl.commonName().toStdString()<< " ";

        }
        std::cout<<std::endl;
        return res.second;
    }

private:
    QVector<Plant> m_repo;
    // Plant: ==, <
    std::set<Plant> m_toStudyAbout;

};

#endif // CONTROLLER_H
