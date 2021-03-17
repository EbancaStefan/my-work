#ifndef EXAMPLANIFICATION_H
#define EXAMPLANIFICATION_H

#include <QObject>
#include <QString>
#include <QDateTime>

class ExamPlanification: public QObject{
    Q_OBJECT
public:

    Q_INVOKABLE ExamPlanification();
    ExamPlanification(QString subject, QString teacher, QString classroom, QDateTime dt, QObject* parent=nullptr);

    ~ExamPlanification(){}
    // the Q_INVOKABLE macro must be applied to declarations of member functions to allow them to be invoked via the meta-object system (with invokeMethod)
    Q_INVOKABLE QString subject() const;
    Q_INVOKABLE void setClassroom(const QString &classroom);
    void setDateTime(const QDateTime &dateTime);

signals:
    void classromChanged(const QString& clasroom);
    void dateTimeChanged();

public slots:
    void onClassroomChanged(const QString& newClassroom);


private:
    QString     m_subject;
    QString     m_classroom;
    QString     m_teacherName;
    QDateTime   m_dateTime;


};


#endif // EXAMPLANIFICATION_H
