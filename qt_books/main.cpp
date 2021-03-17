#include <QCoreApplication>
#include "book.h"
#include "repo.h"
#include "bookgui.h"
#include <iostream>
#include <stack>
#include <QJsonDocument>
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QApplication app(argc, argv);

    BookGUI booksUI;
    booksUI.show();
        return app.exec();
    std::stack<Book> stack;
    Book b("yes","yes","yes","12",HORROR,"yes");
    stack.push(b);
    std::cout<<stack.size();
    return 0;


    /*Book a;
    Book a1("yes","yes","yes","12",HORROR,"yes");
    Repo r;
    a.setTitle("no");
    r.addBook(a);
    r.addBook(a1);
    std::cout<<a.toString().toUtf8().data();
    std::cout<<a.toString().toUtf8().data();
    return 0;*/

    //Repo r;
    //Book b;
    //b.getDesc();
    //b.setDesc("yes");
    //b.setTitle("ceapa");
    //Book book("da","da","da","12",HORROR,"");
    //std::cout<<b.toString().toUtf8().data();
    //r.addBook(b);
    //Book b3{"Gunsx, Germs, and Steel", "Jared Diamond", "The book attempts to explain why Eurasian and North African civilizations have survived and conquered others, while arguing against the idea that Eurasian hegemony is due to any form of Eurasian intellectual, moral, or inherent genetic superiority.", "1997", HISTORY, "https://audible.ro"};
    //r.addBook(b3);
    //r.displayallrepo();
    //r.removeBook("ceapa");
    //r.updateBook(b);
    //r.removeBook("ceapa");
    //r.displayallrepo();
    //r.givenGenre(HORROR);
    //r.displaytolisten();

}
