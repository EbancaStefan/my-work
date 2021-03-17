#include "BookRepo.h"
#include <algorithm>
#include <memory>
#include <iostream>
#include <string>
#include <fstream>
void BookRepo::addA(std::shared_ptr<Book> book)
{
	int i=0;
	int yes = 0;
	for (std::shared_ptr<Book> a : m_adminRepo) {
		i++;
		if ((*a).getTitle() == (*book).getTitle() && (*a).getGenre() == (*book).getGenre() && (*a).getYear()==(*book).getYear())
		{
			yes = 1;
		}
	}
	if (yes == 1)
	{
		std::cout << "This book already exists!\n";
	}
	else
		this->m_adminRepo.push_back(book);
	//this->m_userRepo.push_back(book);
}
void BookRepo::delA(std::shared_ptr<Book> book)
{
	int i, poz;
	i = 0;
	int yes = 0;
	for (std::shared_ptr<Book> a : m_adminRepo) {
		i++;
		if ((*a).getTitle() == (*book).getTitle())
		{
			poz = i;
			yes = 1;
		}
	}
	if (yes == 1)
	{
		poz--;
		this->m_adminRepo.erase(m_adminRepo.begin() + poz);
	}
	else
	{
		std::cout << "That book does not exist!\n";
	}

	//this->m_userRepo.erase(m_adminRepo.begin() + poz);
}
void BookRepo::updateA(std::shared_ptr<Book> book)
{
	int i, poz;
	i = 0;
	for (std::shared_ptr<Book> a : m_adminRepo) {
		i++;
		if ((*a).getTitle() == (*book).getTitle())
		{
			std::cout << "Update the AUTHOR:" << std::endl;
			std::string str;
			int year1;
			int genre1;
			std::getline(std::cin, str);
			(*a).setAuthor(str);
			std::cout << "Update the TITLE:" << std::endl;
			std::getline(std::cin, str);
			(*a).setTitle(str);
			std::cout << "Update the DESCRIPTION:" << std::endl;
			std::getline(std::cin, str);
			(*a).setDesc(str);
			std::cout << "Update the COVER:" << std::endl;
			std::getline(std::cin, str);
			(*a).setCover(str);
			std::cout << "Update the YEAR:" << std::endl;
			std::cin >> year1;
			(*a).setYear(year1);
			std::cout << "0-HISTORY	1-SCIENCE	2-HORROR	3-ROMANCE	4-FANTASY\nUpdate the GENRE:" << std::endl;
			std::cin >> genre1;
			if(genre1==0)
				(*a).setGenre(HISTORY);
			if (genre1 == 1)
				(*a).setGenre(SCIENCE);
			if (genre1 == 2)
				(*a).setGenre(HORROR);
		}
	}
}
void BookRepo::displayAll()
{
	for (std::shared_ptr<Book> a : m_adminRepo) {
		(*a).toString();
	}
}