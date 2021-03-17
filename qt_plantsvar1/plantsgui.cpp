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

#include <QStatusBar>

PlantsGUI::PlantsGUI(QWidget *parent) : QMainWindow(parent)
{
    m_controller = new PlantsController{};
//    m_controller->saveToFile("test.csv");
    this->setWindowTitle("Plants");
    this->setMinimumSize(QSize(800, 200));

    QMenu* fileMenu = this->menuBar()->addMenu("Fi&le"); //mnemonics ALT+L
    QAction* addPlantAction = new QAction("Add Plant");
    fileMenu->addAction(addPlantAction);
    connect(addPlantAction,&QAction::triggered,this,&PlantsGUI::onAddPlantTriggered);

    QWidget *centralW = createCentralWidget();

    this->setCentralWidget(centralW);

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

void PlantsGUI::addToStudy()
{
  int selectedRow = m_repoListWidget->currentRow();
  if(selectedRow<0)
      return;
  Plant pl(m_controller->repo()[selectedRow]);
  bool inserted = m_controller->addtostudyset(pl); //backennd -. set OK!
  qDebug()<<inserted<<"?"<<pl.commonName();
  if(inserted)
  {
      m_tostudylistWidget->addItem(pl.commonName()); //front end: list
  }
  //m_controller->addtostudyset(pl);
  //m_tostudylistWidget->addItem(pl.scientificName());

}

void PlantsGUI::onAddPlantTriggered()
{
    qDebug()<<"triggered action";
    QWidget* addPlant = createAddPlantWidget();
    addPlant->show();
}

QWidget *PlantsGUI::createAddPlantWidget()
{
    QWidget* widget = new QWidget();//am scos this din paranteza

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
    m_tostudylistWidget = new QListWidget(this);

    QWidget* addNewPlantW = createAddPlantWidget();
    QVBoxLayout* vBoxLayout = new QVBoxLayout;

    vBoxLayout->addWidget(addNewPlantW);

    QFrame *line =  new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    vBoxLayout->addWidget(line);

    //vBoxLayout->addWidget(m_repoListWidget);
    //widget->setLayout(vBoxLayout);

    repoPopulate();

    QWidget* wwidget= new QWidget(this);
    QHBoxLayout* hlayout=new QHBoxLayout(this);
    QPushButton* hbutton=new QPushButton("ADD",this);
    hlayout->addWidget(m_repoListWidget);
    hlayout->addWidget(hbutton);
    hlayout->addWidget(m_tostudylistWidget);//daca nu ai * in clasa treci cu &
    wwidget->setLayout(hlayout);

    vBoxLayout->addWidget(wwidget);

    widget->setLayout(vBoxLayout);

    connect(hbutton,&QPushButton::pressed,this,&PlantsGUI::addToStudy);
    return widget;
}
