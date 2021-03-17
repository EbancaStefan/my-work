#include "drawwidget.h"
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>

DrawingWidget::DrawingWidget(QWidget *parent) : QWidget{ parent }
{
    this->m_drawingType = Paint::SmilingFace;
}

DrawingWidget::~DrawingWidget()
{
}

QSize DrawingWidget::sizeHint() const
{
    return QSize{ 600, 400 };
}

void DrawingWidget::paintSmilingFace()
{
    QPainter painter{ this };
    painter.eraseRect(0, 0, 600, 400);

    // draw an ellipse
    QPen blackPen{ Qt::black, 4, Qt::SolidLine, Qt::RoundCap };
    painter.setPen(blackPen);

    QBrush brushWhite{ Qt::white, Qt::SolidPattern };
    QBrush brushBlack{ Qt::black, Qt::SolidPattern };

    painter.setBrush(brushWhite);

    painter.drawEllipse(10, 10, 250, 250); // draw a circle for the face
    painter.setBrush(brushBlack);
    // draw 2 circles for the left and right eyes
    painter.drawEllipse(67, 74, 25, 25); // left eye
    painter.drawEllipse(180, 74, 25, 25); // right eye

    painter.setBrush(brushWhite);
    painter.drawEllipse(130, 120, 25, 25); // draw another circle for the nose


    QRectF rectangle(95, 150.0, 80.0, 60.0);
    int startAngle = 210*16;
    int spanAngle = 120*16;
    // drawArc - draws the arc defined by the given rectangle, startAngle and spanAngle.
    // The startAngle and spanAngle must be specified in 1/16th of a degree, i.e. a full circle equals 5760 (16 * 360).
    painter.drawArc(rectangle, startAngle, spanAngle); // draw an arc for the smiling mouth
}

void DrawingWidget::paintEllipse()
{
    QPainter painter{ this };
    painter.eraseRect(0, 0, 600, 400);

    // draw an ellipse
    QPen pen{ Qt::red, 1, Qt::SolidLine, Qt::RoundCap };
    painter.setPen(pen);
    QBrush brush{ Qt::red, Qt::FDiagPattern };
    painter.setBrush(brush);
    painter.drawEllipse(150, 100, 250, 130);
}

void DrawingWidget::paintRectangle()
{
    QPainter painter{ this };
    painter.eraseRect(0, 0, 600, 400);

    // draw a rectangle
    QPen pen{ Qt::blue, 3, Qt::DotLine, Qt::RoundCap };
    painter.setPen(pen);

    QBrush brush{ Qt::cyan, Qt::SolidPattern };
    painter.setBrush(brush);
    painter.drawRect(150, 20, 250, 130);
}

void DrawingWidget::paintPath()
{
    QPainter painter{ this };

    // draw a more comple path
    QPainterPath path;
    path.addRect(100, 300, 60, 60);
    path.moveTo(100, 300);
    path.cubicTo(199, 300, 150, 150, 199, 199);
    path.cubicTo(300, 399, 150, 150, 100, 300);
    painter.setPen(QPen(QColor(255, 255, 0), 1, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));
    painter.setBrush(QColor("#ffd700"));
    painter.drawPath(path);
}

void DrawingWidget::paintEvent(QPaintEvent *event)
{
    switch (this->m_drawingType)
    {
    case Paint::SmilingFace:
        this->paintSmilingFace();
        break;
    case Paint::Ellipse:
        this->paintEllipse();
        break;
    case Paint::Rectangle:
        this->paintRectangle();
        break;
    case Paint::Path:
        this->paintPath();
        break;
    default:
        break;
    }
}

void DrawingWidget::mousePressEvent(QMouseEvent * event)
{
    qDebug() << "Mouse pressed";
    this->m_drawingType = Paint::Ellipse;
    this->update();
    this->setFocus();
}

void DrawingWidget::keyPressEvent(QKeyEvent *event)
{
    QWidget::keyPressEvent(event);
    int k = event->key();
    switch (k)
    {
    case Qt::Key_Up:
    case Qt::Key_R:
         qDebug() << "up key or R";
        this->m_drawingType = Paint::Rectangle;
        this->update();
        break;
    case Qt::Key_Down:
        qDebug() << "down key";
        this->m_drawingType = Paint::Path;
        this->update();
        break;
    case Qt::Key_S:
        qDebug() << "S key";
        m_drawingType = Paint::SmilingFace;
        this->update();
        break;
    }
}
