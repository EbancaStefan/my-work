#include "Controller.h"
#include "BookRepo.h"
#include "Book.h"
Controller::Controller()
{

}
Controller::~Controller()
{

}
void Controller::givenGenre(Genre x)
{
	int x1=0;
	std::string str;
	while (x1 == 0) {
		for (std::shared_ptr<Book> a : repo.m_adminRepo) {
			if ((*a).getGenre() == x)
			{
				(*a).toString();
				std::cout << "\nWould you like to add this book to your list?(Y/N)\n(to stop searching for books of this genre press '1')\n";
				std::getline(std::cin, str);
				while (str != "N" and str != "Y" and str != "1" and str != "y" and str != "n")
				{
					std::cout << "Invalid option!\n";
					std::getline(std::cin, str);
				}
				if (str == "1")
				{
					x1 = 1;
					break;
				}
				if (str == "Y" or str == "y")
					this->repo.to_listen.push_back(a);
			}
		}
		if (str != "1") {
		std::cout << "\nThere are no more books of this genre.\nWould you like to see the list of books of this genre again?(Y/N):";
		std::getline(std::cin, str);
		if (str == "n" or str == "N")
			x1 = 1;
	}
	}

}

void Controller::addto_listen(std::shared_ptr<Book> book)
{
	this->repo.to_listen.push_back(book);
}

void Controller::delto_listen(std::string name)
{
	int i, poz;
	i = 0;
	for (std::shared_ptr<Book> a : repo.to_listen) {
		i++;
		if ((*a).getTitle() == name)
		{
			poz = i;
		}
	}
	poz--;
	this->repo.to_listen.erase(repo.to_listen.begin() + poz);
}
void Controller::display_listen()
{
	for (std::shared_ptr<Book> a : repo.to_listen) {
		(*a).toString();
	}
}