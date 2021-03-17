#pragma once
#include "Book.h"
#include <vector>
#include <memory>
#include <string>
//ADMINISTRATOR MODE:
//The administrator will also have the option to see all the books in the database.
//The application will have a database, which holds all the books.The administrator must be able to update the database, meaning: 
//add a new book, delete a book and update the information of a book.
class BookRepo
{
private:

public:
	std::vector<std::shared_ptr<Book>> m_adminRepo;
	std::vector<std::shared_ptr<Book>> to_listen;
	void addA(std::shared_ptr<Book> book);
	void delA(std::shared_ptr<Book> book);
	void updateA(std::shared_ptr<Book> book);
	void displayAll();//only for admin
};

