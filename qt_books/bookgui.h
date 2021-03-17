#ifndef BOOKGUI_H
#define BOOKGUI_H
#include <QLineEdit>
#include <QMainWindow>
#include <QListWidget>
#include <stack>
#include <book.h>
#include <QKeyEvent>
#include <QDebug>
class Repo;
class BookGUI: public QMainWindow
{

    Q_OBJECT
public:
    explicit BookGUI(QWidget* parent = nullptr);
signals:
  void keyCaught(QKeyEvent *e);

public slots:
    void onUpdateBookPressed();
    void onAddBookPressed();
    void onRemoveBookPressed();
    void onUpdateBookPressed1();
    void showDialog();
    void repoPopulate();
    void addToListen();
    void undo();
    void redo();


private:
    Repo* m_controller;

    QWidget *createAddBookWidget();
    QWidget *createCentralWidget();
    QWidget createBookWidget();

    std::stack<int> undoStack;
    std::stack<Book> undoBookStack;
    std::stack<int> redoStack;
    std::stack<Book> redoBookStack;

    QListWidget* m_repoListWidget;

    QLineEdit* m_titleEdit;
    QLineEdit* m_authorEdit;
    QLineEdit* m_descEdit;
    QLineEdit* m_yearEdit;
    QLineEdit* m_coverEdit;
    QListWidget m_tostudylist;

protected:
    void keyPressEvent(QKeyEvent *e);

};

#endif // BOOKGUI_H
