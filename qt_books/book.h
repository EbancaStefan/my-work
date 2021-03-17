#pragma once
#ifndef BOOK_H
#define BOOK_H
#define _CRT_SECURE_NO_WARNINGS
//Each Book has a title, an author, a genre, a description the year it was published and a book cover.
//The book cover is stored as a link towards an online resource.
//The administrator will also have the option to see all the books in the database.

#include <string>
#include <vector>

#include <QColor>
#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include <QStringList>

typedef enum {
    HISTORY,
    SCIENCE,
    HORROR,
    ROMANCE,
    FANTASY
}Genre;
class Book:public QObject
{
private:
    QString m_title;
    QString m_author;
    QString m_desc;
    QString m_cover;
    QString m_year;
    Genre m_genre;
public:
    Book();
    Book(const Book &other);
    Book(QString title, QString author, QString desc, QString year, Genre genre, QString cover) : m_title{ title }, m_author{ author }, m_desc{ desc }, m_year{ year }, m_genre{ genre }, m_cover{ cover } {}

    //QString imagePath() const;
    //void setImagePath(const QString &imagePath);

    QJsonObject toJsonObject();
    QString toString();

    QString getTitle();
    QString getAuthor();
    QString getDesc();
    QString getCover();
    QString getYear();
    Genre getGenre();

    void setTitle(const QString &title);
    void setAuthor(const QString &author);
    void setDesc(const QString &desc);
    void setCover(const QString &cover);
    void setYear(const QString &year);
    void setGenre(const Genre &genre);

    void operator=(const Book &other);
    bool operator==(const Book &other);
    bool operator==(const QString &title);

};
#endif // !BOOK_H

