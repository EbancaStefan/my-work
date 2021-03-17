#include "plant.h"
using namespace std;

Plant::Plant():m_commonName{""},
    m_scientificName{""}, m_family{""}, m_imagePath{""}, m_color{QColor{}}
{}

Plant::Plant(QString commonName, QString scientificName, QString family, QString imagePath, QColor color):m_commonName{commonName},
    m_scientificName{scientificName}, m_family{family}, m_imagePath{imagePath}, m_color{color}
{}

Plant::Plant(const Plant &other)
{
    m_scientificName = other.m_scientificName;
    m_commonName = other.m_commonName;
    m_family = other.m_family;
    m_color = other.m_color;
    m_imagePath = other.m_imagePath;

}

void Plant::operator=(const Plant &other)
{
    m_scientificName = other.m_scientificName;
    m_commonName = other.m_commonName;
    m_family = other.m_family;
    m_color = other.m_color;
    m_imagePath = other.m_imagePath;

}

bool Plant::operator==(const Plant &other)
{
    return !(m_scientificName.compare(other.m_scientificName, Qt::CaseInsensitive));
}

bool Plant::operator==(const QString &scientificName)
{
    return !(m_scientificName.compare(scientificName, Qt::CaseInsensitive));
}

bool Plant::operator<(const Plant &other) const{
    return (m_scientificName.compare(other.m_scientificName, Qt::CaseInsensitive) < 0);
}

QJsonObject Plant::toJsonObject(){
    QJsonObject obj;
    obj["family"] = m_family;
    obj["common_name"] = m_commonName;
    obj["scientific_name"] = m_scientificName;
    if(!m_imagePath.isEmpty())
        obj["image_path"] = m_imagePath;
    obj["color"] = m_color.name();

    return obj;
}

QString Plant::toString()
{
    QString str = m_commonName+","+m_scientificName+","+m_family+","+m_imagePath+","+m_color.name()+","+m_imagePath+"\n";
    return str;
}

QString Plant::family() const
{
    return m_family;
}

void Plant::setFamily(const QString &family)
{
    m_family = family;
}

QString Plant::commonName() const
{
    return m_commonName;
}

void Plant::setCommonName(const QString &commonName)
{
    m_commonName = commonName;
}

QString Plant::scientificName() const
{
    return m_scientificName;
}

void Plant::setScientificName(const QString &scientificName)
{
    m_scientificName = scientificName;
}

QString Plant::imagePath() const
{
    return m_imagePath;
}

void Plant::setImagePath(const QString &imagePath)
{
    m_imagePath = imagePath;
}

QColor Plant::color() const
{
    return m_color;
}

void Plant::setColor(const QColor &color)
{
    m_color = color;
}

