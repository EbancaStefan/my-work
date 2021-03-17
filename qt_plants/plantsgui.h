#ifndef PLANTSGUI_H
#define PLANTSGUI_H
#include <QLineEdit>
#include <QMainWindow>
#include <QListWidget>

class PlantsController;
class PlantsGUI : public QMainWindow
{

    Q_OBJECT
public:
    explicit PlantsGUI(QWidget *parent = nullptr);

signals:

public slots:
    void onAddPlantPressed();

    void showDialog();
    void repoPopulate();
    void onAddPlantTriggered();
    void onAddToStudyListPressed();

private:
    PlantsController* m_controller;

    QWidget *createAddPlantWidget();
    QWidget *createCentralWidget();


	QListWidget* m_repoListWidget;
    QListWidget* m_toStudyAbouListWidget;
// add new plant widget  GUI elements
    QLineEdit* m_customNameEdit;
    QLineEdit* m_scientificNameEdit;
    QLineEdit* m_imagePathEdit;


};



#endif // PLANTSGUI_H
