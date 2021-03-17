//#include "mainwindow.h"

#include <QDebug>
#include <QTextStream>
#include <QDateTime>
#include <QApplication>
#include <QGenericArgument>
#include <QMetaClassInfo>
#include <qmetaobject.h>

#include "examplanification.h"

int main(int argc, char *argv[])
{


    ExamPlanification *obj = static_cast<ExamPlanification*>(ExamPlanification::staticMetaObject.newInstance());

    qDebug()<<"The constructors of this clss are: ";
    for (int i = 0; i < obj->metaObject()->constructorCount(); i++)
    {
        QMetaMethod constr = obj->metaObject()->constructor(i);
        qDebug() << constr.methodSignature();
    }
    qDebug()<<".";
    qDebug() << "The methods for this class are: ";
    for (int i = 0; i < obj->metaObject()->methodCount(); i++)
    {
        QMetaMethod method = obj->metaObject()->method(i);
        qDebug() << method.methodSignature()<<" ";
        method.invoke(obj);
    }

    QMetaObject::invokeMethod(obj, &ExamPlanification::subject, Qt::AutoConnection);
    QString classrrom = "SL304";
    QMetaObject::invokeMethod(obj, "setClassroom", Qt::AutoConnection , Q_ARG(const QString&, classrrom));

    return 0;
}



