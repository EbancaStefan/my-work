#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSlider>
#include <QSpinBox>
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QSlider* m_slider;
    QSpinBox *m_spinBox;
};
#endif // MAINWINDOW_H
