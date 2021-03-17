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
    void addToStudy();

    void onAddPlantTriggered();

private:
    PlantsController* m_controller;

    QWidget *createAddPlantWidget();
    QWidget *createCentralWidget();

    QListWidget* m_tostudylistWidget;
	QListWidget* m_repoListWidget;
// add new plant widget  GUI elements
    QLineEdit* m_customNameEdit;
    QLineEdit* m_scientificNameEdit;
    QLineEdit* m_imagePathEdit;
    QListWidget m_tostudylist;


};

#endif // PLANTSGUI_H
