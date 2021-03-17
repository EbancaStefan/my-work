#include "bookgui.h"
#include "repo.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QFileDialog>
#include <QIcon>
#include <QFrame>
#include <QMenuBar>
#include <QAction>
#include <QStatusBar>

//override la KeyPressEvent
//undo redo cu KeyPressEvent ctr+z ctrl+y    la help QKeySequence -- e un enum mare cu undo si redo
//pt implementare putem folosi std::stack<Operation> care are deja push si pop
void BookGUI::keyPressEvent(QKeyEvent *e)
{
        if ((e->modifiers()==Qt::ControlModifier) && (e->key()==Qt::Key_Z) )
        {
            BookGUI::undo();
            repoPopulate();
        }
        if ((e->modifiers()==Qt::ControlModifier) && (e->key()==Qt::Key_Y) )
        {
            BookGUI::redo();
            repoPopulate();
        }
}
BookGUI::BookGUI(QWidget *parent) : QMainWindow(parent)
{
    undoStack.push(-1);
    redoStack.push(-1);
    Book b;
    undoBookStack.push(b);
    redoBookStack.push(b);

    m_controller = new Repo{};
    m_controller->saveToFile("test.csv");
    this->setWindowTitle("Books");
    this->setMinimumSize(QSize(800, 200));

    QMenu* fileMenu = this->menuBar()->addMenu("&File"); //mnemonics ALT+F
    QAction* undoAction = new QAction("&Undo");
    QAction* redoAction = new QAction("&Redo");

    fileMenu->addAction(redoAction);
    fileMenu->addAction(undoAction);
    connect(undoAction, &QAction::triggered, this, &BookGUI::undo);
    connect(undoAction, &QAction:: triggered, this, &BookGUI:: repoPopulate);
    connect(redoAction, &QAction::triggered, this, &BookGUI:: redo);
    connect(redoAction, &QAction::triggered, this, &BookGUI:: repoPopulate);

   // connect(buttontest, &QPushButton:: pressed, this, &BookGUI:: undo);
   // connect(buttontest, &QPushButton:: pressed, this, &BookGUI:: repoPopulate);
    QWidget *centralW = createCentralWidget();

    this->setCentralWidget(centralW);

}

void BookGUI::onUpdateBookPressed1() //asta merge
{                                   //bazat pe consola
                                    //uselessssss
    int selectedRow = m_repoListWidget->currentRow();
    m_controller->updateBook(m_controller->repo()[selectedRow]);

    qDebug()<<"updated"<<selectedRow;

}
void BookGUI::onUpdateBookPressed() //asta nu merge Edit: merge
{                                   //asta e cel bun
    //Book b;

    auto title=m_titleEdit->text();
    auto author=m_authorEdit->text();
    auto year=m_yearEdit->text();
    auto desc=m_descEdit->text();
    auto cover=m_coverEdit->text();
    //b.setTitle(m_titleEdit->text());
    //b.setAuthor(m_authorEdit->text());
    //b.setYear(m_yearEdit->text());
    //b.setDesc(m_descEdit->text());
    //b.setCover(m_coverEdit->text());
    //b.setGenre(HORROR);
    int selectedRow = m_repoListWidget->currentRow();
    m_controller->updateBookgud(m_controller->repo()[selectedRow],title,author,year,desc,cover);
    //m_controller->repo()[selectedRow].getTitle();
}

void BookGUI::onAddBookPressed()
{
    Book b;
    b.setTitle(m_titleEdit->text());
    b.setAuthor(m_authorEdit->text());
    b.setYear(m_yearEdit->text());
    b.setDesc(m_descEdit->text());
    b.setCover(m_coverEdit->text());//image path-ul meu
    undoStack.push(0);
    undoBookStack.push(b);
    qDebug()<<undoStack.size()<<" "<<undoBookStack.size();
    //b.setImagePath(m_imagePathEdit->text());
    //qDebug()<<"added";
    bool added = m_controller->addBook(b);

}

void BookGUI::onRemoveBookPressed()
{
    int selectedRow = m_repoListWidget->currentRow();
    undoStack.push(1);
    undoBookStack.push(m_controller->repo()[selectedRow]);
    m_controller->removeBook(m_controller->repo()[selectedRow]);

    qDebug()<<"deleted"<<selectedRow;

    //bool removed = m_controller->removeBook(m_controller->repo()[selectedRow]);
}
void BookGUI::undo()
{
    qDebug()<<"undo";
    if(undoStack.top()==0)
    {
        redoStack.push(0);
        redoBookStack.push(undoBookStack.top());
        m_controller->removeBook(undoBookStack.top());
        undoStack.pop();
        undoBookStack.pop();
    }
    if(undoStack.top()==1)
    {
        redoStack.push(1);
        redoBookStack.push(undoBookStack.top());
        m_controller->addBook(undoBookStack.top());
        undoStack.pop();
        undoBookStack.pop();
    }
}
void BookGUI::redo()
{
    if(redoStack.top()==0)
    {
        undoStack.push(0);
        undoBookStack.push(redoBookStack.top());
        m_controller->addBook(redoBookStack.top());
        redoStack.pop();
        redoBookStack.pop();
    }
    if(redoStack.top()==1)
    {
        undoStack.push(1);
        undoBookStack.push(redoBookStack.top());
        m_controller->removeBook(redoBookStack.top());
        redoStack.pop();
        redoBookStack.pop();
    }
}

void BookGUI::showDialog()
{
    QString path;
    path=QFileDialog:: getOpenFileName(this, "Select picture", "", "(*.jpg *.png)");
    m_coverEdit->setText(path);
}

void BookGUI::repoPopulate()
{

    QVector<Book>book_repo= m_controller->repo();

    m_repoListWidget->clear();

    //QVector<Book> database = this->m_controller->repo();
    //m_repoListWidget->setRowCount(database.size());

    for(auto a: book_repo){
        if(!a.getCover().isEmpty())
        {
            QIcon icon(a.getCover());
            if(!icon.isNull())
            {
                new QListWidgetItem(icon, a.getTitle(),m_repoListWidget);
            }
            else
                new QListWidgetItem(a.getTitle(),m_repoListWidget);
        }
        else
            new QListWidgetItem(a.getTitle(),m_repoListWidget);
    }
}

void BookGUI::addToListen()
{
  int selectedRow = m_repoListWidget->currentRow();
  m_controller->addtolisten(m_controller->repo()[selectedRow]);
  qDebug()<<"pressed"<<selectedRow;
}

QWidget *BookGUI::createAddBookWidget()
{

    //m_repoListWidget = new QTableWidge(this);
    //m_repoListWidget->setColumnCount(6);
    QWidget* widget = new QWidget(this);

    QGridLayout* grid = new QGridLayout(this);
    QLabel *labelT = new QLabel("Title", this);
    m_titleEdit = new QLineEdit(this);
    QLabel *labelA = new QLabel("Author", this);
    m_authorEdit = new QLineEdit(this);
    QLabel *labelY = new QLabel("Year", this);
    m_yearEdit = new QLineEdit(this);
    QLabel *labelD = new QLabel("Descr.", this);
    m_descEdit = new QLineEdit(this);
    QLabel *labelC = new QLabel("Cover", this);
    m_coverEdit = new QLineEdit(this);

    QPushButton *button = new QPushButton("Browse",this);
    QPushButton *buttonAdd = new QPushButton("Add Book",this);
    QPushButton *buttonRemove = new QPushButton("Remove Book",this);
    QPushButton *buttonUpdate = new QPushButton("Update Book",this);
    QPushButton *buttontest = new QPushButton("Undo *Test*",this);
    QPushButton *buttontest2 = new QPushButton("Redo *Test*",this);



    grid->addWidget(labelT,0,0);
    grid->addWidget(m_titleEdit,0,1,1,2);
    grid->addWidget(labelA,1,0);
    grid->addWidget(m_authorEdit,1,1,1,2);
    grid->addWidget(labelY,2,0);
    grid->addWidget(m_yearEdit,2,1,1,2);
    grid->addWidget(labelD,3,0);
    grid->addWidget(m_descEdit,3,1,1,2);
    grid->addWidget(labelC,4,0);
    grid->addWidget(m_coverEdit,4,1);
    grid->addWidget(button,4,2);
    grid->addWidget(buttonRemove,5,0);
    grid->addWidget(buttonAdd,5,1);
    grid->addWidget(buttonUpdate,5,2);
     grid->addWidget(buttontest,6,2);
     grid->addWidget(buttontest2,7,2);

    widget->setLayout(grid);

    connect(buttonAdd, &QPushButton:: pressed, this, &BookGUI:: onAddBookPressed);
    connect(button, &QPushButton:: pressed, this, &BookGUI:: showDialog );
    connect(buttonRemove,&QPushButton:: pressed, this, &BookGUI:: onRemoveBookPressed);
    connect(buttonAdd, &QPushButton:: pressed, this, &BookGUI:: repoPopulate);
    connect(buttonRemove,&QPushButton:: pressed, this, &BookGUI:: repoPopulate);
    connect(buttonUpdate, &QPushButton:: pressed, this, &BookGUI:: onUpdateBookPressed);
    connect(buttonUpdate, &QPushButton:: pressed, this, &BookGUI:: repoPopulate);
    //undo redo
    connect(buttontest, &QPushButton:: pressed, this, &BookGUI:: undo);
    connect(buttontest, &QPushButton:: pressed, this, &BookGUI:: repoPopulate);
    connect(buttontest2, &QPushButton:: pressed, this, &BookGUI:: redo);
    connect(buttontest2, &QPushButton:: pressed, this, &BookGUI:: repoPopulate);
    //not needed anymore

    //void QPushButton::showMenu()

    return widget;
}

QWidget *BookGUI::createCentralWidget()
{
    QWidget* widget=new QWidget(this);
    m_repoListWidget=new QListWidget(this);

    QWidget* addNewBookW = createAddBookWidget();
    QVBoxLayout* vBoxLayout = new QVBoxLayout;

    vBoxLayout->addWidget(addNewBookW);

    QFrame *line =  new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    vBoxLayout->addWidget(line);

    vBoxLayout->addWidget(m_repoListWidget);
    widget->setLayout(vBoxLayout);

    repoPopulate();

    QWidget* wwidget= new QWidget(this);
    QHBoxLayout* hlayout=new QHBoxLayout(this);
    //QPushButton* hbutton=new QPushButton("ADD",this);
    hlayout->addWidget(m_repoListWidget);
    //hlayout->addWidget(hbutton);
    //hlayout->addWidget(&m_tostudylist);//daca nu ai * in clasa treci cu &
    wwidget->setLayout(hlayout);

    vBoxLayout->addWidget(wwidget);

    widget->setLayout(vBoxLayout);

    //connect(hbutton,&QPushButton::pressed,this,&BookGUI::addToListen);
    return widget;
}



//QWidget BookGUI::createBookWidget()
//{
//    QWidget* widget = new QWidget(this);
//    QGridLayout* grid = new QGridLayout(this);
//    QLabel *labelT = new QLabel("Title", this);
//    m_titleEdit = new QLineEdit(this);
//    QLabel *labelA = new QLabel("Author", this);
//    m_authorEdit = new QLineEdit(this);
//    QLabel *labelY = new QLabel("Year", this);
//    m_yearEdit = new QLineEdit(this);
//    QLabel *labelD = new QLabel("Descr.", this);
//    m_descEdit = new QLineEdit(this);
//    QLabel *labelC = new QLabel("Cover", this);
//    m_coverEdit = new QLineEdit(this);

//    QPushButton *buttonUpdate = new QPushButton("Update Book",this);

//    grid->addWidget(labelT,0,0);
//    grid->addWidget(m_titleEdit,0,1,1,2);
//    grid->addWidget(labelA,1,0);
//    grid->addWidget(m_authorEdit,1,1,1,2);
//    grid->addWidget(labelY,2,0);
//    grid->addWidget(m_yearEdit,2,1,1,2);
//    grid->addWidget(labelD,3,0);
//    grid->addWidget(m_descEdit,3,1,1,2);
//    grid->addWidget(labelC,4,0);
//    grid->addWidget(m_coverEdit,4,1);
//    grid->addWidget(buttonUpdate,4,2);

//}
//Book createBook()
//{
//    Book book1;
//    std::string str;
//    int genre1;
//    QString qstr;

//    std::cout << "Update the AUTHOR:" << std::endl;
//    std::getline(std::cin, str);
//    qstr= QString::fromStdString(str);
//    book1.setAuthor(qstr);

//    std::cout << "Update the TITLE:" << std::endl;
//    std::getline(std::cin, str);
//    qstr = QString::fromStdString(str);
//    book1.setTitle(qstr);

//    std::cout << "Update the DESCRIPTION:" << std::endl;
//    std::getline(std::cin, str);
//    qstr = QString::fromStdString(str);
//    book1.setDesc(qstr);

//    std::cout << "Update the COVER:" << std::endl;
//    std::getline(std::cin, str);
//    qstr = QString::fromStdString(str);
//    book1.setCover(qstr);

//    std::cout << "Update the YEAR:" << std::endl;
//    std::getline(std::cin, str);
//    qstr = QString::fromStdString(str);
//    book1.setYear(qstr);


//    std::cout << "0-HISTORY	1-SCIENCE	2-HORROR	3-ROMANCE	4-FANTASY\nUpdate the GENRE:" << std::endl;
//    std::cin >> genre1;
//    if (genre1 == 0)
//        book1.setGenre(HISTORY);
//    if (genre1 == 1)
//        book1.setGenre(SCIENCE);
//    if (genre1 == 2)
//        book1.setGenre(HORROR);
//    if (genre1 == 3)
//        book1.setGenre(ROMANCE);
//    if (genre1 == 4)
//        book1.setGenre(FANTASY);
//    return book1;
//}
