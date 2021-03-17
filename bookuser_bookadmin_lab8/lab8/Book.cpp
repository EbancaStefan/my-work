#include "Book.h"
std::string Book::getTitle()
{
	return m_title;
}
std::string Book::getAuthor()
{
	return m_author;
}
std::string Book::getDesc()
{
	return m_desc;
}
int Book::getYear()
{
	return m_year;
}
Genre Book::getGenre()
{
	return m_genre;
}
std::string Book::getCover()
{
	return m_cover;
}
void Book::setTitle(std::string title)
{
	m_title = title;
}
void Book::setAuthor(std::string author)
{
	m_author = author;
}
void Book::setDesc(std::string desc)
{
	m_desc = desc;
}
void Book::setYear(int year)
{
	m_year = year;
}
void Book::setGenre(Genre genre)
{
	m_genre = genre;
}
void Book::setCover(std::string cover)
{
	m_cover = cover;
}
void Book::toString()
{
	char categoryToString[5][30] = {
		"HISTORY",
		"SCIENCE",
		"HORROR",
		"ROMANCE",
		"FANTASY",
	};
	std::cout<<"\n'"<<m_title<<"' written by "<<m_author<<", "<<m_year<<" is a "<<categoryToString[m_genre]<<" book.\n"<<"	~"<<m_desc<<std::endl<<"\n";
}