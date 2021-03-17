#ifndef PLANTSGUI_H
#define PLANTSGUI_H

#include <QMainWindow>
#include <QLineEdit>
#include <QListWidget>

class PlantsController;
class PlantsGUI : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlantsGUI(QWidget *parent = nullptr);

signals:
public slots:
    void addPlantPress();
    void showDialog();
    void repoPopulate();
private:
    PlantsController* m_controller;
    QWidget *addWidget();
    QListWidget* m_repoList;
    QLineEdit* lineN;
    QLineEdit* lineNS;
    QLineEdit* lineI;
};

#endif // PLANTSGUI_H
