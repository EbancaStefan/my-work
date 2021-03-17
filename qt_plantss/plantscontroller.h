#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "plant.h"
#include <vector>
#include <iostream>
#include <QVector>
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

private:
    QVector<Plant> m_repo;

};

#endif // CONTROLLER_H
