#pragma once
#include <string>
#include <vector>

#include <QColor>
#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include <QStringList>

class Plant: public QObject
{

public:
    Plant();
    Plant(QString commonName, QString scientificName, QString family, QString imagePath, QColor color);
    Plant(const Plant &other);

    void operator=(const Plant &other);
    bool operator==(const Plant &other);
    bool operator==(const QString &scientificName);
//operator <
    bool operator<(const Plant &other) const;
    QJsonObject toJsonObject();
    QString     toString();

    QString family() const;
    void setFamily(const QString &family);

    QString commonName() const;
    void setCommonName(const QString &commonName);

    QString scientificName() const;
    void setScientificName(const QString &scientificName);

    QString imagePath() const;
    void setImagePath(const QString &imagePath);

    QColor color() const;
    void setColor(const QColor &color);


private:
    QString     m_family;
    QString     m_commonName;
    QString     m_scientificName;
    QString     m_imagePath;
    QColor      m_color;

};
