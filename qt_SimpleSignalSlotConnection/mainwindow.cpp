#include "mainwindow.h"

#include <QObject>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QWidget* centralWidget{new QWidget}; // creating a central widget for out custom window
    this->setCentralWidget(centralWidget);

    QHBoxLayout* horizLayout{new QHBoxLayout{}}; // create a horizontal layout to arrange the items from the window
    m_spinBox = new QSpinBox{centralWidget}; // a spinbox
    m_spinBox->setRange(0, 100); // the range of the spinbox is set to [0, 100]

    m_slider = new QSlider{Qt::Horizontal, centralWidget}; // create a new horizontal slider. the first parameter is the orientation of the slider
    // can be Qt::Horizontal or Qt::Verical

    horizLayout->addWidget(m_slider); // add the slider to the horizontal layout
    horizLayout->addWidget(m_spinBox); // add the spinbox to the horizontal layout

    centralWidget->setLayout(horizLayout); // applying this layout to the centralWidget

    // now it's time to connect the slider and the spinbox
    //    connect(m_slider, SIGNAL(valueChanged(int)), m_spinBox, SLOT(setValue(int)));
    connect(m_slider, &QSlider::valueChanged, m_spinBox, &QSpinBox::setValue);

    //
    connect(m_spinBox, SIGNAL(valueChanged(int)), m_slider, SLOT(setValue(int)));
    //   QObject::connect(m_spinBox, QOverload<int>::of(&QSpinBox::valueChanged), m_slider,  &QSlider::setValue);

    this->setGeometry(110, 110, 300, 30);
}

MainWindow::~MainWindow()
{

}

