#include "UI.h"
#include "BookRepo.h"
#include "Book.h"
#include "Controller.h"
#include <cstring>
#include <iostream>
void options_admin()
{
	std::cout<<("\nPlease select an option:\n1 - Add an AudioBook.\n2 - Delete an AudioBook.\n3 - Update an existing AudioBook.\nd - Display your Library.\ne - To quit the application.\nOption:");
}
void options_user()
{
	std::cout << ("\nPlease select an option:\n1 - See the AudioBooks that are relevant to a chosen genre.\n2 - Delete an AudioBook from your list.\nd - Display your list.\ne - To quit the application.\nOption:");
}
void display_ctrl(Controller* ctrl)
{
	ctrl->repo.displayAll();
}
void loadAudioBookData(Controller* ctrl)
{
	//std::cout << "'" << m_title << "' written by " << m_author << ", " << m_year << " is a " << categoryToString[m_genre] << " book.\n" << "	~" << m_desc << std::endl;
	auto b1 = std::make_shared<Book>("Dracula", "Bram Stoker", "It introduced the character of Count Dracula and established many conventions of subsequent vampire fantasy. The novel tells the story of Dracula's attempt to move from Transylvania to England so that he may find new blood and spread the undead curse, and of the battle between Dracula and a small group of people led by Professor Abraham Van Helsing.", 1897, HORROR, "https://audible.ro");
	ctrl->repo.addA(b1);
	auto b2 = std::make_shared<Book>("Frankenstein", "Mary Shelley", "Frankenstein; or, The Modern Prometheus is a novel written by English author Mary Shelley (1797–1851) that tells the story of Victor Frankenstein, a young scientist who creates a hideous sapient creature in an unorthodox scientific experiment.", 1821, HORROR, "https://audible.ro");
	ctrl->repo.addA(b2);
	auto b3 = std::make_shared<Book>("Guns, Germs, and Steel", "Jared Diamond", "The book attempts to explain why Eurasian and North African civilizations have survived and conquered others, while arguing against the idea that Eurasian hegemony is due to any form of Eurasian intellectual, moral, or inherent genetic superiority.", 1997, HISTORY, "https://audible.ro");
	ctrl->repo.addA(b3);
	auto b4 = std::make_shared<Book>("1776", "David McCullough", "The work is a companion to McCullough's earlier biography of John Adams, and focuses on the events surrounding the start of the American Revolution. While revolving mostly around the leadership (and often indecisiveness) of George Washington.", 2005, HISTORY, "https://audible.ro");
	ctrl->repo.addA(b4);
	auto b5 = std::make_shared<Book>("Cosmos", "Carl Sagan", "Cosmos has 13 chapters, corresponding to the 13 episodes of the Cosmos television series. The book covers a broad range of topics, comprising Sagan's reflections on anthropological, cosmological, biological, historical, and astronomical matters from antiquity to contemporary times.", 1980, SCIENCE, "https://audible.ro");
	ctrl->repo.addA(b5);
	auto b6 = std::make_shared<Book>("Astrophysics for People in a Hurry", "Neil deGrasse Tyson", "In Astrophysics for People in a Hurry by Neil deGrasse Tyson takes the reader on a voyage from the beginning of our universe and the big bang to our modern world and the need to place our existence within a wider cosmological perspective.", 2017, SCIENCE, "https://audible.ro");
	ctrl->repo.addA(b6);
	auto b7 = std::make_shared<Book>("Pride and Prejudice", "Jane Austen", "The novel follows the character development of Elizabeth Bennet, the dynamic protagonist of the book who learns about the repercussions of hasty judgments and comes to appreciate the difference between superficial goodness and actual goodness.", 1813, ROMANCE, "https://audible.ro");
	ctrl->repo.addA(b7);
	auto b8 = std::make_shared<Book>("The Time Traveler's Wife", "Audrey Niffenegger", " It is a love story about a man with a genetic disorder that causes him to time travel unpredictably, and about his wife, an artist, who has to cope with his frequent absences and dangerous experiences.", 2003, ROMANCE, "https://audible.ro");
	ctrl->repo.addA(b8);
	auto b9 = std::make_shared<Book>("The Hobbit", "J. R. R. Tolkien", "The Hobbit is set within Tolkien's fictional universe and follows the quest of home-loving Bilbo Baggins, the titular hobbit, to win a share of the treasure guarded by Smaug the dragon. Bilbo's journey takes him from light-hearted, rural surroundings into more sinister territory.", 1937, FANTASY, "https://audible.ro");
	ctrl->repo.addA(b9);
	auto b10 = std::make_shared<Book>("Alice's Adventures in Wonderland", "Lewis Carroll", "It tells of a young girl named Alice falling through a rabbit hole into a subterranean fantasy world populated by peculiar, anthropomorphic creatures.One of the best-known and most popular works of English-language fiction, its narrative course, structure, characters, and imagery have been enormously influential in both popular culture and literature, especially in the fantasy genre.", 1865, FANTASY, "https://audible.ro");
	ctrl->repo.addA(b10);
}
void uiAddBook_Admin(Controller* ctrl)
{
	std::string str1;
	std::string str2;
	std::string str3;
	int year1;
	int genre1;
	std::cout << "Give the TITLE:";
	std::getline(std::cin,str2);
	std::getline(std::cin, str2);
	std::cout << "Give the AUTHOR:";
	std::getline(std::cin, str1);
	std::cout << "Give the DESCRIPTION:";
	std::getline(std::cin, str3);
	std::cout << "Give the YEAR:";
	std::cin >> year1;
	std::cout << "0-HISTORY	1-SCIENCE	2-HORROR	3-ROMANCE	4-FANTASY\nGive the GENRE:";
	std::cin >> genre1;
	if (genre1 == 0)
	{
		auto b1 = std::make_shared<Book>(str2, str1, str3, year1, HISTORY, "https://audible.ro/");
		ctrl->repo.addA(b1);
	}
	if (genre1 == 1)
	{
		auto b1 = std::make_shared<Book>(str2, str1, str3, year1, SCIENCE, "https://audible.ro/");
		ctrl->repo.addA(b1);
	}
	if (genre1 == 2)
	{
		auto b1 = std::make_shared<Book>(str2, str1, str3, year1, HORROR, "https://audible.ro/");
		ctrl->repo.addA(b1);
	}
	if (genre1 == 3)
	{
		auto b1 = std::make_shared<Book>(str2, str1, str3, year1, ROMANCE, "https://audible.ro/");
		ctrl->repo.addA(b1);
	}
	if (genre1 == 4)
	{
		auto b1 = std::make_shared<Book>(str2, str1, str3, year1, FANTASY, "https://audible.ro/");
		ctrl->repo.addA(b1);
	}
}
void uiRemoveBook_Admin(Controller* ctrl)
{
	std::string str1;
	std::string str2;
	std::string str3;
	int year1;
	int genre1;
	std::cout << "Give the TITLE:";
	std::getline(std::cin, str2);
	std::getline(std::cin, str2);
	str1 = "1";
	str3 = "3";
	year1 = 1;
	genre1 = 1;
	auto b1 = std::make_shared<Book>(str2, str1, str3, year1, HORROR, "https://audible.ro/");
	ctrl->repo.delA(b1);
}

void uiUpdateBook_Admin(Controller* ctrl)
{
	std::string str1;
	std::string str2;
	std::string str3;
	int year1;
	int genre1;
	std::cout << "Give the TITLE:";
	std::getline(std::cin, str2);
	std::getline(std::cin, str2);
	str1 = "1";
	str3 = "3";
	year1 = 1;
	genre1 = 1;
	auto b1 = std::make_shared<Book>(str2, str1, str3, year1, HORROR, "https://audible.ro/");
	ctrl->repo.updateA(b1);
}
void uiAddBook_User(Controller* ctrl)
{
	std::string str;
	int yes = 0;
	std::cout << "You have chosen to add an AudioBook to your To Listen list!\nHISTORY		SCIENCE		HORROR		ROMANCE		FANTASY\n(To see all existing AudioBooks press ENTER)\nChoose a genre:";
	std::getline(std::cin, str);
	std::getline(std::cin, str);
	if (str == "horror" || str == "HORROR" || str == "Horror")
	{
		ctrl->givenGenre(HORROR);
		yes = 1;
	}
	if (str == "science" || str == "SCIENCE" || str == "Science")
	{
		ctrl->givenGenre(SCIENCE);
		yes = 1;
	}
	if (str == "history" || str == "HISTORY" || str == "History")
	{
		ctrl->givenGenre(HISTORY);
		yes = 1;
	}
	if (str == "fantasy" || str == "FANTASY" || str == "Fantasy")
	{
		ctrl->givenGenre(FANTASY);
		yes = 1;
	}
	if (str == "romance" || str == "ROMANCE" || str == "Romance")
	{
		ctrl->givenGenre(ROMANCE);
		yes = 1;
	}
	if (yes == 0)
	{
		for (std::shared_ptr<Book> a : ctrl->repo.m_adminRepo) {
			(*a).toString();
			std::cout << "\nWould you like to add this book to your list?(Y/N)\n(to stop searching for books press '1')\n";
			std::getline(std::cin, str);
			while (str != "N" and str != "Y" and str != "1" and str != "y" and str != "n")
			{
				std::cout << "Invalid option!\n";
				std::getline(std::cin, str);
			}
			if (str == "1")
				break;
			if (str == "Y" or str == "y")
				ctrl->repo.to_listen.push_back(a);			
		}
	}
}
void uiRemoveBook_User(Controller* ctrl)
{
	std::string str1;
	std::string str2;
	std::string str3;
	int year1;
	int genre1;
	std::cout << "Give the TITLE:";
	std::getline(std::cin, str2);
	std::getline(std::cin, str2);
	str1 = "1";
	str3 = "3";
	year1 = 1;
	genre1 = 1;
	auto b1 = std::make_shared<Book>(str2, str1, str3, year1, HORROR, "https://audible.ro/");
	ctrl->delto_listen((*b1).getTitle());
}
void display_lib(Controller* ctrl)
{
	ctrl->display_listen();
}
void uiUpdateBook_User(Controller* ctrl)
{

}
void displayUI(Controller* ctrl) 
{
	int x = 0;std::string str; int k, ok;
	while (x == 0)
	{
		std::cout << "Choose the mode you want to run this application.\n1 - User Mode\n2 - Administrator Mode\n(to quit this application type 'quit')\n";
		std::getline(std::cin, str);
		if (str == "quit" || str == "QUIT")
			x = 1;
		else 
		{
			while (str != "1" and str != "2")
			{
				std::cout << "Invalid option!\nPlease choose either User Mode(1) or Administrator Mode(2)";
				std::getline(std::cin, str);
			}
		}
		if (str == "1")
		{
			std::cout << "You have chosen User Mode!\nThe following operations are available to you:\n";
			char op1;
			do {
				options_user();
				scanf(" %c", &op1);
				switch (op1)
				{
				case '1':
					uiAddBook_User(ctrl);
					break;
				case '2':
					uiRemoveBook_User(ctrl);
					break;
				case 'd':
					display_lib(ctrl);
					break;
				case 'e':
					printf("Exit.\n");
					exit(0);
				default:
					printf("Unknown option %c \n", op1);
					continue;
				}
			} while (true);
		}
		if (str == "2")
		{
			std::cout << "You have chosen Administrator Mode!\nPlease insert the password to gain access to it's features.\nPassword:";
			std::getline(std::cin, str);
			k = 0; ok = 0;
			while (str != "admin" && ok == 0)
			{
				if (2 - k > 1)
					std::cout << "Invalid password! You have " << 2 - k << " more tries.\nPassword:";
				if (2 - k == 1)
					std::cout << "Invalid password! You have " << 2 - k << " more try.\nPassword:";
				std::getline(std::cin, str);
				k++;
				if (k == 2 || str == "e")
					ok = 1;
			}
			if (ok == 1)
			{
				std::cout << "You have no more tries!\nSending you back to Mode Selection.\n";
			}
			if (str == "admin")
			{
				char op;
				do {
					options_admin();
					scanf(" %c", &op);
					switch (op)
					{
					case '1':
						uiAddBook_Admin(ctrl);
						break;
					case '2':
						uiRemoveBook_Admin(ctrl);
						break;
					case '3':
						uiUpdateBook_Admin(ctrl);
						break;
					case 'd':
						display_ctrl(ctrl);
						break;
					case 'e':
						printf("Exit.\n");
						exit(0);
					default:
						printf("Unknown option %c \n", op);
						continue;
					}
				} while (true);
			}
		}
	}
}