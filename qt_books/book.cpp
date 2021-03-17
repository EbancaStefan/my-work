#include "book.h"

Book::Book():m_title{""},
    m_author{""}, m_year{""}, m_desc{""}, m_genre{HORROR}, m_cover{""}
{}

Book::Book(const Book &other)
{
    m_title = other.m_title;
    m_author = other.m_author;
    m_year = other.m_year;
    m_cover = other.m_cover;
    m_desc = other.m_desc;
    m_genre = other.m_genre;

}

void Book::operator=(const Book &other)
{
    m_title = other.m_title;
    m_author = other.m_author;
    m_genre = other.m_genre;
    m_desc = other.m_desc;
    m_year = other.m_year;
    m_cover = other.m_cover;
}

bool Book::operator==(const Book &other)
{
    return !(m_title.compare(other.m_title, Qt::CaseInsensitive));
}

bool Book::operator==(const QString &title)
{
    return !(m_title.compare(title, Qt::CaseInsensitive));
}

QJsonObject Book::toJsonObject(){
    QJsonObject obj;
    obj["title"] = m_title;
    obj["author"] = m_author;
    obj["desc"] = m_desc;
    if(!m_cover.isEmpty())
        obj["cover"] = m_cover;
    obj["year"] = m_year;
    obj["genre"] = m_genre;

    return obj;
}

QString Book::toString()
{
    char categoryToString[5][30] = {
        "HISTORY",
        "SCIENCE",
        "HORROR",
        "ROMANCE",
        "FANTASY",
    };
    QString str = "'"+m_title+"' written by "+m_author+" is a "+categoryToString[m_genre]+" book "+"written in "+m_year+".\n"+" ~"+m_desc+"\n";
    return str;
}

QString Book::getDesc()
{
    return m_desc;
}

QString Book::getYear()
{
    return m_year;
}

QString Book::getCover()
{
    return m_cover;
}

QString Book::getTitle()
{
    return m_title;
}

QString Book::getAuthor()
{
    return m_author;
}

Genre Book::getGenre()
{
    return m_genre;
}

void Book::setDesc(const QString &desc)
{
    m_desc=desc;
}

void Book::setYear(const QString &year)
{
    m_year=year;
}

void Book::setCover(const QString &cover)
{
    m_cover=cover;
}

void Book::setGenre(const Genre &genre)
{
    m_genre=genre;
}

void Book::setAuthor(const QString &author)
{
    m_author=author;
}

void Book::setTitle(const QString &title)
{
    m_title=title;
}
