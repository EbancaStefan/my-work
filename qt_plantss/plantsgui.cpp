#include "plantsgui.h"
#include "plantscontroller.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QfileDialog>
#include <QIcon>

#include <QStatusBar>
PlantsGUI::PlantsGUI(QWidget *parent) : QMainWindow(parent)
{
    m_controller = new PlantsController{};
    m_controller->saveToFile("test.csv");
    this->setWindowTitle("Plants");
    this->setMinimumSize(QSize(800, 200));
    QWidget* addW=addWidget();
    this->setCentralWidget(addW);
}

void PlantsGUI::addPlantPress()
{
    Plant p;
    p.setCommonName(lineN->text());
    p.setScientificName(lineNS->text());
    p.setImagePath(lineI->text());

    m_controller->addPlant(p);
    qDebug()<<"addPlantPress()";

}

void PlantsGUI::showDialog()
{
    QString path;
    path=QFileDialog:: getOpenFileName(this,"Select picture","","(*.jpg *.png)");
    lineI->setText(path);
}

void PlantsGUI::repoPopulate()
{
    QVector<Plant>plant_repo=m_controller->repo();
    m_repoList->clear();
    for(auto pl:plant_repo)
    {
        QListWidgetItem* item=new QListWidgetItem(pl.commonName(),m_repoList);
        if(!pl.imagePath().isEmpty())
        {
            QIcon icon(pl.imagePath());
            if(!icon.isNull())
            {
                QListWidgetItem* itemIcon=new QListWidgetItem(icon,pl.commonName(),m_repoList);
            }
            else
            {
                QListWidgetItem* item=new QListWidgetItem(pl.commonName(),m_repoList);
            }
        }
        else
            QListWidgetItem* item=new QListWidgetItem(pl.commonName(),m_repoList);
    }
}

QWidget *PlantsGUI::addWidget()
{

    QWidget* widget=new QWidget(this);
    QGridLayout* grid=new QGridLayout(this);
    m_repoList=new QListWidget(this);
    QLabel* labelN=new QLabel("nume",this);
    lineN=new QLineEdit(this);

    QLabel* labelNS=new QLabel("nume stiintific",this);
    lineNS=new QLineEdit(this);

    QLabel* labelI=new QLabel("imagine",this);
    lineI=new QLineEdit(this);

    QPushButton* button=new QPushButton("Browse",this);
    QPushButton* buttonAdd=new QPushButton("Add plant",this);

    grid->addWidget(labelN,0,0);
    grid->addWidget(lineN,0,1,1,2);
    grid->addWidget(labelNS,1,0);
    grid->addWidget(lineNS,1,1,1,2);
    grid->addWidget(labelI,2,0);
    grid->addWidget(lineI,2,1);
    grid->addWidget(button,2,2);
    grid->addWidget(buttonAdd,3,2);
    grid->addWidget(m_repoList,5,0,3,3);

    widget->setLayout(grid);

    connect(buttonAdd,&QPushButton:: pressed,this,&PlantsGUI:: addPlantPress);
    connect(button,&QPushButton:: pressed,this,&PlantsGUI:: showDialog);
    connect(buttonAdd,&QPushButton:: pressed,this,&PlantsGUI::repoPopulate);
    repoPopulate();
    return widget;
}
