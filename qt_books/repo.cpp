#include "repo.h"
#include "persistenceengine.h"
Repo::Repo()
{
    // add some data
    Book b1{"Dracula", "Bram Stoker", "It introduced the character of Count Dracula and established many conventions of subsequent vampire fantasy. The novel tells the story of Dracula's attempt to move from Transylvania to England so that he may find new blood and spread the undead curse, and of the battle between Dracula and a small group of people led by Professor Abraham Van Helsing.", "1897", HORROR, "https://audible.ro"};
    Book b2{"Frankenstein", "Mary Shelley", "Frankenstein; or, The Modern Prometheus is a novel written by English author Mary Shelley (1797–1851) that tells the story of Victor Frankenstein, a young scientist who creates a hideous sapient creature in an unorthodox scientific experiment.", "1821", HORROR, "https://audible.ro"};
    Book b3{"Guns, Germs, and Steel", "Jared Diamond", "The book attempts to explain why Eurasian and North African civilizations have survived and conquered others, while arguing against the idea that Eurasian hegemony is due to any form of Eurasian intellectual, moral, or inherent genetic superiority.", "1997", HISTORY, "https://audible.ro"};
    /*Book b4{"trifoi", "Trifolium pratense", "Fabaceae", "trifoi.jpg", Qt::red};
    Book b5{"degetel", "Digitalis grandiflora", "Plantaginacee", "degetel.jpg", Qt::yellow};
    Book b6{"ciubotica cucului", "Primula officinalis", "Primulaceae", "ciubotica.jpg", Qt::yellow};
    Book b7{"crucea voinicului", "Hepatica transsilvanica", "Ranunculaceae", "crucea_voinicului.jpg", Qt::blue};
    Book b8{"Pastita", "Anemone nemorosa", "Ranunculaceae", "", Qt::white};
    Book b9{"nigella sativa", "nigella sativa", "Ranunculaceae", "negrilica.jpg", Qt::white};
    Book b10{"roua cerului", "Drosera rotundifolia", "Droseraceae", "drosera.jpg", Qt::green};*/

    m_repo<<b1<<b2<<b3;/*<<b4<<b5<<b6<<b7<<b8<<b9<<b10;*/
}

Repo::~Repo()
{}

bool Repo::addBook(Book b)
{
    std::vector<Book> books = m_repo.toStdVector();
    if (std::find(books.begin(), books.end(), b) != books.end())
        return false;
    m_repo.append(b);
    return true;
}

bool Repo::removeBook(Book b)
{
    int y=0,i=0,poz;
    for(auto a:m_repo)
    {
        if(a.getTitle()==b.getTitle())
        {
            y=1;
            poz=i;
        }
        i++;
    }
    if(y==0)
        return false;
    else
        m_repo.remove(poz);
    return true;
}

Book createBook()
{
    Book book1;
    std::string str;
    int genre1;
    QString qstr;

    std::cout << "Update the AUTHOR:" << std::endl;
    std::getline(std::cin, str);
    qstr= QString::fromStdString(str);
    book1.setAuthor(qstr);

    std::cout << "Update the TITLE:" << std::endl;
    std::getline(std::cin, str);
    qstr = QString::fromStdString(str);
    book1.setTitle(qstr);

    std::cout << "Update the DESCRIPTION:" << std::endl;
    std::getline(std::cin, str);
    qstr = QString::fromStdString(str);
    book1.setDesc(qstr);

    std::cout << "Update the COVER:" << std::endl;
    std::getline(std::cin, str);
    qstr = QString::fromStdString(str);
    book1.setCover(qstr);

    std::cout << "Update the YEAR:" << std::endl;
    std::getline(std::cin, str);
    qstr = QString::fromStdString(str);
    book1.setYear(qstr);


    std::cout << "0-HISTORY	1-SCIENCE	2-HORROR	3-ROMANCE	4-FANTASY\nUpdate the GENRE:" << std::endl;
    std::cin >> genre1;
    if (genre1 == 0)
        book1.setGenre(HISTORY);
    if (genre1 == 1)
        book1.setGenre(SCIENCE);
    if (genre1 == 2)
        book1.setGenre(HORROR);
    if (genre1 == 3)
        book1.setGenre(ROMANCE);
    if (genre1 == 4)
        book1.setGenre(FANTASY);
    return book1;
}
bool Repo::updateBook(Book book)
{

    int i=0, yes=0,poz;
    for(auto a:m_repo)
    {
        if(book.getTitle()==a.getTitle())
        {
            yes=1;
            poz=i;
        }
        i++;
    }
    if(yes==0)
        return false;
    else
    {
        Book x;
        x=createBook();
        m_repo.replace(poz,x);
        return true;
    }
}
Book createBook_gud(QString title,QString author,QString year,QString desc,QString Cover)
{
    Book book;
    book.setTitle(title);
    book.setAuthor(author);
    book.setYear(year);
    book.setDesc(desc);
    book.setCover(Cover);
    return book;
    //    b.setTitle(m_titleEdit->text());
    //    b.setAuthor(m_authorEdit->text());
    //    b.setYear(m_yearEdit->text());
    //    b.setDesc(m_descEdit->text());
    //    b.setCover(m_coverEdit->text());
    //    b.setGenre(HORROR);

}
bool Repo::updateBookgud(Book book,QString title,QString author,QString year,QString desc,QString Cover)
{

    int i=0, yes=0,poz;
    for(auto a:m_repo)
    {
        if(book.getTitle()==a.getTitle())
        {
            yes=1;
            poz=i;
        }
        i++;
    }
    if(yes==0)
        return false;
    else
    {
        Book x;
        x=createBook_gud(title,author,year,desc,Cover);
        m_repo.replace(poz,x);
        return true;
    }
}

bool Repo::addtolisten(Book b)
{
    for(auto a: m_tolisten)
    {
        if(a.getTitle()==b.getTitle())
            return false;
    }
    m_tolisten.append(b);
    return true;
}

bool Repo::deltolisten(QString m_title)
{
    int y=0,i=0,poz;
    for(auto a:m_tolisten)
    {
        if(a.getTitle()==m_title)
        {
            poz=i;
            y=1;
        }
        i++;
    }
    if(y==0)
        return false;
    m_tolisten.remove(poz);
    return true;
}

void Repo::displaytolisten()
{
    for(auto a:m_tolisten)
    {
         std::cout<<a.toString().toUtf8().data()<<std::endl;
    }
}

void Repo::displayallrepo()
{
    //std::vector<Book> books = m_repo.toStdVector();
    for(auto a:m_repo)
    {
        std::cout<<a.toString().toUtf8().data()<<std::endl;
    }
}
const QVector<Book> &Repo::repo()
{
    return m_repo;
}
const QVector<Book> &Repo::tolisten()
{
    return m_tolisten;
}

void Repo::givenGenre(Genre x)
{
    int x1=0;
        std::string str;
        while (x1 == 0) {
            for (auto a : m_repo) {
                if (a.getGenre() == x)
                {
                    std::cout<<a.toString().toUtf8().data();
                    std::cout << "\nWould you like to add this book to your list?(Y/N)\n(to stop searching for books of this genre press '1')\n";
                    std::getline(std::cin, str);
                    while (str != "N" && str != "Y" && str != "1" && str != "y" && str != "n")
                    {
                        std::cout << "Invalid option!\n";
                        std::getline(std::cin, str);
                    }
                    if (str == "1")
                    {
                        x1 = 1;
                        break;
                    }
                    if (str == "Y" || str == "y")
                        this->m_tolisten.push_back(a);
                }
            }
            if (str != "1") {
            std::cout << "\nThere are no more books of this genre.\nWould you like to see the list of books of this genre again?(Y/N):";
            std::getline(std::cin, str);
            if (str == "n" || str == "N")
                x1 = 1;
        }
        }
}
bool Repo::saveToFile(QString filepath)
{
    PersistenceEngine<Book>* persistenceEngine = nullptr;
    if(filepath.endsWith(".json"))
        persistenceEngine = new PersistenceEngineJSON<Book>(m_repo);
    if(filepath.endsWith(".csv"))
        persistenceEngine = new PersistenceEngineCSV<Book>(m_repo);
    if(!persistenceEngine)
        return false;

    return persistenceEngine->save(filepath);
}
/*bool Repo::dumpToJson(QString jsonPath)
{

}*/
