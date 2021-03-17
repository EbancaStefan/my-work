#include "UI.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include "cstack.h"
void options()
{
	printf("Please select an option: \n \t 1\t - add a new product\n \t 2\t - remove a product\n \t 3\t - displays the products that have a string in them\n \t 4\t - expires in X days\n \t u\t - undo the last operation\n \t r\t - redo the last operation\n \t d\t - display all products\n \t e\t - exit\n");
}

void uiAddProduct(Controller* ctrl)
{
	system("@cls||clear");
	Date d;
	int day1, month1, year1;
	bool yes = false;
	int type;
	std::string str;
	printf("Insert new product:\n");
	printf("\tProduct name: ");
	std::getline(std::cin, str);
	std::getline(std::cin, str);
	printf("\tProduct category ( 0 - dairy, 1 - sweets, 2 - meat, 3 - fruit): ");
	scanf("%d", &type);
	printf("\tExpiration date (day,month,year): ");
	scanf("%d", &day1);
	d.day = day1;
	scanf("%d", &month1);
	d.month = month1;
	scanf("%d", &year1);
	d.year = year1;
	while (d.day > 30)
	{
		d.day = d.day - 30;
		d.month++;
	}
	while (d.month > 12)
	{
		d.month = d.month - 12;
		d.year++;
	}
	if (type == 0)
	{
		Product prod(str, DAIRY, 1, d);
		ctrl->addProduct(prod);
		yes = true;
	}
	if (type == 1)
	{
		Product prod1(str, SWEET, 1, d);
		ctrl->addProduct(prod1);
		yes = true;
	}
	if (type == 2)
	{
		Product prod2(str, MEAT, 1, d);
		ctrl->addProduct(prod2);
		yes = true;
	}
	if (type == 3)
	{
		Product prod3(str, FRUIT, 1, d);
		ctrl->addProduct(prod3);
		yes = true;
	}
	if (yes == true)
		printf("\nOperation completed successfully\n");
	else
		printf("\nOperation failed\n");

}
void uiHasString(Controller* ctrl)
{
	std::string string;
	printf("Give the string:");
	std::getline(std::cin, string);
	std::getline(std::cin, string);
	ctrl->ctrlString(string);
}
void uiRemoveProduct(Controller* ctrl)
{
	system("@cls||clear");
	Date d;
	int day1, month1, year1;
	bool yes = false;
	int type;
	std::string str;
	printf("Insert new product:\n");
	printf("\tProduct name: ");
	std::getline(std::cin, str);
	std::getline(std::cin, str);
	printf("\tProduct category ( 0 - dairy, 1 - sweets, 2 - meat, 3 - fruit): ");
	scanf("%d", &type);
	printf("\tExpiration date (day,month,year): ");
	scanf("%d", &day1);
	d.day = day1;
	scanf("%d", &month1);
	d.month = month1;
	scanf("%d", &year1);
	d.year = year1;
	while (d.day > 30)
	{
		d.day = d.day - 30;
		d.month++;
	}
	while (d.month > 12)
	{
		d.month = d.month - 12;
		d.year++;
	}
	if (type == 0)
	{
		Product prod(str, DAIRY, 1, d);
		if (ctrl->removeProduct(prod) == true)
			yes = true;
	}
	if (type == 1)
	{
		Product prod1(str, SWEET, 1, d);
		if (ctrl->removeProduct(prod1) == true)
			yes = true;
	}
	if (type == 2)
	{
		Product prod2(str, MEAT, 1, d);
		if (ctrl->removeProduct(prod2) == true)
			yes = true;
	}
	if (type == 3)
	{
		Product prod3(str, FRUIT, 1, d);
		if (ctrl->removeProduct(prod3) == true)
			yes = true;
	}
	if (yes == true)
		printf("\nOperation completed successfully\n");
	else
		printf("\nOperation failed\n");
}
void uiExpiresIn(Controller* ctrl)
{
	ctrl->ctrlExpiresIn();
}
void displayUI(Controller* ctrl) {
	char op;
	do {
		options();
		scanf(" %c", &op);
		switch (op)
		{
		case '1':
			uiAddProduct(ctrl);
			break;
		case '2':
			uiRemoveProduct(ctrl);
			break;
		case '3':
			uiHasString(ctrl);
			break;
		case '4':
			uiExpiresIn(ctrl);
			break;
		case 'u':
			ctrl->undo();
			break;
		case 'r':
			ctrl->redo();
			break;
		case 'd':
			ctrl->displayProduct();
			break;
		case 'e':
			printf("Exit.\n");
			exit(0);
		case 'p':
			printf("Redo Stack.\n");
			ctrl->redoStack.printstack();
			//printstack(&ctrl->redoStack);
			printf("\n Undo Stack.\n");
			//printstack(&ctrl->undoStack);
			ctrl->undoStack.printstack();
			break;
		default:
			printf("Unknown option %c \n", op);
			continue;
		}
	} while (true);
}