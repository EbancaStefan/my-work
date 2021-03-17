#include "plantscontroller.h"
#include "persistenceengine.h"


#include <QJsonDocument>

#include <vector>
#include <algorithm>
using namespace std;

PlantsController::PlantsController()
{
    // add some data
    Plant laleaPestrita{"Lalea pestrita", "Fritillaria meleagris", "Liliaceae","lalea_pestrita.jpg", Qt::red};
    Plant mac1{"mac", "Papaver dubium",  "Papaveraceae", "mac-de-camp-portocaliu.jpg", Qt::red};
    Plant mac2{"mac de gradina", "Papaver somniferum", "Papaveraceae", "", Qt::red};
    Plant trifoi{"trifoi", "Trifolium pratense", "Fabaceae", "trifoi.jpg", Qt::red};
    Plant degetel{"degetel", "Digitalis grandiflora", "Plantaginacee", "degetel.jpg", Qt::yellow};
    Plant ciubotica{"ciubotica cucului", "Primula officinalis", "Primulaceae", "ciubotica.jpg", Qt::yellow};
    Plant cruceaVoinicului{"crucea voinicului", "Hepatica transsilvanica", "Ranunculaceae", "crucea_voinicului.jpg", Qt::blue};
    Plant anemona{"Pastita", "Anemone nemorosa", "Ranunculaceae", "", Qt::white};
    Plant negrilica{"nigella sativa", "nigella sativa", "Ranunculaceae", "negrilica.jpg", Qt::white};
    Plant drosera{"roua cerului", "Drosera rotundifolia", "Droseraceae", "drosera.jpg", Qt::green};
    Plant floareDeColt{"floare de colt", "Leontopodium alpinum", "Magnoliopsida", "floare-de-colt", Qt::white};

    m_repo<<laleaPestrita<<mac1<<mac2<<trifoi<<degetel<<ciubotica<<cruceaVoinicului<<anemona<<negrilica<<drosera<<floareDeColt;

}

PlantsController::~PlantsController()
{}

bool PlantsController::addPlant(Plant pl)
{
    std::vector<Plant> plants = m_repo.toStdVector();
    if (std::find(plants.begin(), plants.end(), pl) != plants.end())
        return false;
    m_repo.append(pl);
    return true;
}

bool PlantsController::removePlant(QString scientificName)
{
    std::vector<Plant> plants = m_repo.toStdVector();
    auto it = std::find(plants.begin(), plants.end(), scientificName);

    if (it == plants.end())
        return false;

    int index = it - plants.begin();
    m_repo.remove(index);
    return true;
}

bool PlantsController::saveToFile(QString filepath)
{
    PersistenceEngine<Plant>* persistenceEngine = nullptr;
    if(filepath.endsWith(".json"))
        persistenceEngine = new PersistenceEngineJSON<Plant>(m_repo);
    if(filepath.endsWith(".csv"))
        persistenceEngine = new PersistenceEngineCSV<Plant>(m_repo);
    // @todo other types of actual persistence objects (csv, xml etc)
    if(!persistenceEngine)
        return false;

    return persistenceEngine->save(filepath);
}

QStringList PlantsController::getPlantFamilies()
{
    /// @todo
    return QStringList{};
}

const QVector<Plant> &PlantsController::repo()
{
    return m_repo;
}

//const QVector<Plant> &PlantsController::study()
//
//    return m_tostudylist;
//}

bool PlantsController::addtostudyset(Plant p)
{
   auto res= m_tostudylist.insert(p);
   //res - pair :first element iterator to position of the element
   // second element is a bool -> was the element inserted
   std::cout<<"********"<<std::endl;
   for(Plant p : m_tostudylist)
   {
       std::cout<<p.commonName().toStdString()<<" ";
   }
   std::cout<<std::endl;
   return res.second;
    //return true;
}

