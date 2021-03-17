#pragma once
#ifndef BOOK_H
#define BOOK_H
#define _CRT_SECURE_NO_WARNINGS
//Each Book has a title, an author, a genre, a description the year it was published and a book cover.The book cover is stored as a link towards an online resource.
//The administrator will also have the option to see all the books in the database.
#include <string>
#include <vector>
#include <ostream>
#include <iostream>
typedef enum {
	HISTORY,
	SCIENCE,
	HORROR,
	ROMANCE,
	FANTASY
}Genre;
class Book
{
protected:
	std::string m_title;
	std::string m_author;
	std::string m_desc;
	std::string m_cover;
	int m_year;
	Genre m_genre;
public:
	Book(const std::string title, const std::string author, const std::string desc, const int year, Genre genre, const std::string cover) : m_title{ title }, m_author{ author }, m_desc{ desc }, m_year{ year }, m_genre{ genre }, m_cover{ cover } {}
	virtual std::string getTitle();
	virtual std::string getAuthor();
	virtual std::string getDesc();
	virtual std::string getCover();
	virtual int getYear();
	virtual Genre getGenre();
	virtual void setTitle(std::string title);
	virtual void setAuthor(std::string author);
	virtual void setDesc(std::string desc);
	virtual void setCover(std::string cover);
	virtual void setYear(int year);
	virtual void setGenre(Genre genre);
	virtual void toString();

};
#endif // !BOOK_H

