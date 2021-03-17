#include "plantsgui.h"
#include "plantscontroller.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QFileDialog>
#include <QIcon>
#include <QFrame>
#include <QMenuBar>
#include <QAction>
#include <QStatusBar>

PlantsGUI::PlantsGUI(QWidget *parent) : QMainWindow(parent)
{
    m_controller = new PlantsController{};
    //    m_controller->saveToFile("test.csv");
    this->setWindowTitle("Plants");
    this->setMinimumSize(QSize(800, 200));

    QMenu* fileMenu = this->menuBar()->addMenu("Fi&le"); //mnemonics ALT+F
    QAction* addPlantAction = new QAction("Add plant");
    fileMenu->addAction(addPlantAction);
    connect(addPlantAction, &QAction::triggered, this, &PlantsGUI::onAddPlantTriggered);
    QWidget *centralW = createCentralWidget();

    this->setCentralWidget(centralW);

}

void PlantsGUI::onAddPlantTriggered()
{
    qDebug()<<":triggered action";
    QWidget* addPlant = createAddPlantWidget();
    addPlant->show();
}

void PlantsGUI::onAddToStudyListPressed()
{
    int selectedINdex = m_repoListWidget->currentRow();
    if(selectedINdex < 0)
        return;
    Plant pl = m_controller->repo()[selectedINdex];
    bool inserted = m_controller->addToToStudy(pl); // backend -. set OK!
    qDebug()<<inserted<<"? "<<pl.commonName();
    if(inserted){
        m_toStudyAbouListWidget->addItem(pl.commonName()); // front end : list
    }
}

void PlantsGUI::onAddPlantPressed()
{
    Plant p;
    p.setCommonName(m_customNameEdit->text());
    p.setScientificName(m_scientificNameEdit->text());
    p.setImagePath(m_imagePathEdit->text());

    bool added = m_controller->addPlant(p);

}

void PlantsGUI::showDialog()
{
    QString path;
    path=QFileDialog:: getOpenFileName(this, "Select picture", "", "(*.jpg *.png)");
    m_imagePathEdit->setText(path);
}

void PlantsGUI::repoPopulate()
{

    QVector<Plant>plant_repo= m_controller->repo();

    m_repoListWidget->clear();

    for(auto pl: plant_repo){
        if(!pl.imagePath().isEmpty()){
            QIcon icon(pl.imagePath());
            if(!icon.isNull()){
                new QListWidgetItem(icon, pl.commonName(),m_repoListWidget);
            }
            else
                new QListWidgetItem(pl.commonName(),m_repoListWidget);
        }
        else
            new QListWidgetItem(pl.commonName(),m_repoListWidget);
    }
}

QWidget *PlantsGUI::createAddPlantWidget()
{
    QWidget* widget = new QWidget();

    QGridLayout* grid = new QGridLayout(this);
    QLabel *labelN = new QLabel("nume", this);
    m_customNameEdit = new QLineEdit(this);
    QLabel *labelNS = new QLabel("nume stiintific", this);
    m_scientificNameEdit = new QLineEdit(this);
    QLabel *labelI = new QLabel("imagine", this);
    m_imagePathEdit = new QLineEdit(this);

    QPushButton *button = new QPushButton("Browse",this);
    QPushButton *buttonAdd = new QPushButton("Add plant",this);

    grid->addWidget(labelN,0,0);
    grid->addWidget(m_customNameEdit,0,1,1,2);
    grid->addWidget(labelNS,1,0);
    grid->addWidget(m_scientificNameEdit,1,1,1,2);
    grid->addWidget(labelI,2,0);
    grid->addWidget(m_imagePathEdit,2,1);
    grid->addWidget(button,2,2);
    grid->addWidget(buttonAdd,3,2);

    widget->setLayout(grid);

    connect(buttonAdd, &QPushButton:: pressed, this, &PlantsGUI:: onAddPlantPressed);
    connect(button, &QPushButton:: pressed, this, &PlantsGUI:: showDialog );
    connect(buttonAdd, &QPushButton:: pressed, this, &PlantsGUI:: repoPopulate);

    return widget;
}

QWidget *PlantsGUI::createCentralWidget()
{
    QWidget* widget=new QWidget(this);
    m_repoListWidget=new QListWidget(this);
    m_toStudyAbouListWidget=new QListWidget(this);

    QWidget* addNewPlantW = createAddPlantWidget();
    QVBoxLayout* vBoxLayout = new QVBoxLayout;

    vBoxLayout->addWidget(addNewPlantW);

    QFrame *line =  new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    vBoxLayout->addWidget(line);

    // vBoxLayout->addWidget(m_repoListWidget);
    QWidget* wb = new QWidget{};
    QHBoxLayout* hboxLaypoutBottom = new QHBoxLayout(this);

    QPushButton* btn = new QPushButton("A&dd");

    hboxLaypoutBottom->addWidget(m_repoListWidget);
    hboxLaypoutBottom->addWidget(btn);
    hboxLaypoutBottom->addWidget(m_toStudyAbouListWidget);
    wb->setLayout(hboxLaypoutBottom);
    vBoxLayout->addWidget(wb);
    widget->setLayout(vBoxLayout);

    repoPopulate();

    connect(btn, &QPushButton::pressed, this, &PlantsGUI::onAddToStudyListPressed);
    return widget;
}
