#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class DrawingWidget : public QWidget
{
    Q_OBJECT

private:
    enum Paint
    {
        SmilingFace,
        Ellipse,
        Rectangle,
        Path
    };
    Paint m_drawingType;

public:
    DrawingWidget(QWidget *parent = 0);
    ~DrawingWidget();
    QSize sizeHint() const Q_DECL_OVERRIDE; // this must be redefined (the default implementation returns an invalid size, if there is no layout)

    void paintSmilingFace();
    void paintEllipse();
    void paintRectangle();
    void paintPath();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;		// will draw shapes on the widget
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;		// is invoked when a key is pressed, IF the widget has the focus
    void mousePressEvent(QMouseEvent * event) Q_DECL_OVERRIDE;	// is invoked when a key on the mouse is pressed
};

#endif // MAINWINDOW_H
