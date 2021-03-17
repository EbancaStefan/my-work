#include "examplanification.h"

#include <QDebug>
ExamPlanification::ExamPlanification()
{
    m_classroom = QString();
    m_teacherName = QString();
    m_dateTime = QDateTime();
    m_subject = QString();
}

ExamPlanification::ExamPlanification(QString subject, QString teacher, QString classroom, QDateTime dt, QObject *parent):m_subject{subject},m_teacherName{teacher},
    m_classroom{classroom},m_dateTime{dt}{}

QString ExamPlanification::subject() const{
    qDebug()<<Q_FUNC_INFO<<" called.";
    return m_subject;
}

void ExamPlanification::setClassroom(const QString &classroom)
{
    qDebug()<<Q_FUNC_INFO<<" called with "<<classroom<<" param.";
    m_classroom = classroom;
    emit classromChanged(classroom);
}

void ExamPlanification::setDateTime(const QDateTime &dateTime){
    m_dateTime = dateTime;
    emit dateTimeChanged();
}

void ExamPlanification::onClassroomChanged(const QString &newClassroom){
    qDebug()<<"Classroom changed!! "<<newClassroom;
}
