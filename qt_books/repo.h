#ifndef REPO_H
#define REPO_H

#include "book.h"
#include <vector>
#include <iostream>
#include <QVector>
#include <set>

class Repo
{
public:
    Repo();
    ~Repo();

    bool dumpToJson(QString jsonPath);

    bool addBook(Book b);
    bool removeBook(Book b);
    bool updateBook(Book b);
    bool updateBookgud(Book b,QString title,QString author,QString year,QString desc,QString Cover);

    bool saveToFile(QString filepath);

    void displayallrepo();
    const QVector<Book> &repo();
    bool addtolisten(Book b);
    bool deltolisten(QString m_title);
    void displaytolisten();
    const QVector<Book> &tolisten();

    void givenGenre(Genre x);

private:
    QVector<Book> m_repo;
    QVector<Book> m_tolisten;
};

#endif // REPO_H
