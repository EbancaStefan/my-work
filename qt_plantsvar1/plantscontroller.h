#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "plant.h"
#include <vector>
#include <iostream>
#include <QVector>
#include <set>

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
    //const QVector<Plant> &study();
    bool addtostudyset(Plant p);
    std::set<Plant>&studylist(){return m_tostudylist;}

private:
    QVector<Plant> m_repo;
    //QVector<Plant> m_tostudylist;
    std::set<Plant> m_tostudylist; //a set is better ~ will try later
    // set needs operator == and <

};

#endif // CONTROLLER_H
