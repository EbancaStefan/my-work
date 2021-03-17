#include "Controller.h"
#include "ProductRepo.h"
#include "cstack.h"
#include <iostream>

void Controller::loadProductData()
{
	Date d;
	d.day = 12;
	d.month = 12;
	d.year = 2012;
	std::string str = "Corn cu ciocolata";
	Product prod1(str, SWEET, 1, d);
	addProduct(prod1);
	std::string str1 = "Conserva de ton";
	d.day = 13;
	d.month = 13;
	d.year = 2013;
	Product prod2(str1, MEAT, 1, d);
	addProduct(prod2);
	std::string str2 = "Piept de pui";
	d.day = 12;
	d.month = 12;
	d.year = 2012;
	Product prod3(str2, MEAT, 1, d);
	addProduct(prod3);
}

bool Controller::addProduct(Product prod)
{
	if (/*add(ctrl->repo, prod) == true*/repo->add(prod)==true)
	{
		Element prod1;
		prod1.type = ADD;
		prod1.prod = prod;
		undoStack.push(prod1);
		return true;
	}
	else
		return false;
}

void Controller::displayProduct() {
	int i;
	for (i = 0; i <= repo->len; i++)
	{
		repo->elems[i].toString();
	}
}

bool Controller::removeProduct(Product prod)
{
	if (/*removeRepo(ctrl->repo, prod) == true*/repo->removeRepo(prod)==true)
	{
		Element prod1;
		prod1.type = REMOVE;
		prod1.prod = prod;
		undoStack.push(prod1);
		return true;
	}
	else
		return false;
}

void Controller::undo()
{
	if (undoStack.elements[undoStack.top].type == ADD)
	{
		removeProduct(undoStack.elements[undoStack.top].prod);
		
		Element prod1;
		prod1.type = ADD;
		prod1.prod = undoStack.elements[undoStack.top].prod;
		redoStack.push(prod1);
		undoStack.pop();
	}
	if (undoStack.elements[undoStack.top].type == REMOVE)
	{
		//removeProduct(ctrl, ctrl->undoStack.elements[ctrl->undoStack.top].prod);
		//add(repo, undoStack.elements[undoStack.top].prod);
		addProduct(undoStack.elements[undoStack.top].prod);
		Element prod1;
		prod1.type = REMOVE;
		prod1.prod = undoStack.elements[undoStack.top].prod;
		//push(&redoStack, prod1);
		redoStack.push(prod1);
		//pop(&undoStack);
		undoStack.pop();
	}
}

void Controller::redo()
{
	if (redoStack.elements[redoStack.top].type == ADD)
	{
		//addProduct(ctrl, ctrl->redoStack.elements[ctrl->redoStack.top].prod);
		addProduct(redoStack.elements[redoStack.top].prod);
		Element prod1;
		prod1.type = ADD;
		prod1.prod = redoStack.elements[redoStack.top].prod;
		undoStack.push(prod1);
		redoStack.pop();
	}
	if (redoStack.elements[redoStack.top].type == REMOVE)
	{
		removeProduct(redoStack.elements[redoStack.top].prod);
		Element prod1;
		prod1.type = ADD;
		prod1.prod = redoStack.elements[redoStack.top].prod;
		undoStack.push(prod1);
		redoStack.pop();
	}
}

bool Controller::updateProduct(Product prod,int quantity, Date expiration, Category type, std::string name)
{
	if (/*update(ctrl->repo, prod, index, quantity, expiration, type, name) == true*/repo->update(prod,quantity,expiration,type,name)==true)
		return true;
	else
		return false;
}
void Controller::ctrlString(std::string string)
{
	repo->hasString(string);
}
void Controller::ctrlExpiresIn()
{
	Date d;
	int day, days, month, year, type;
	printf("\tCurrent date (year,month,day): ");
	scanf("%d", &year);
	d.year = year;
	scanf("%d", &month);
	d.month = month;
	scanf("%d", &day);
	d.day = day;
	printf("\tNumber of days:");
	scanf("%d", &days);
	printf("\tThe category:");
	scanf("%d", &type);
	if (type == 0)
		repo->expiresInX(DAIRY, days, d);
	if (type == 1)
		repo->expiresInX(SWEET, days, d);
	if (type == 2)
		repo->expiresInX(MEAT, days, d);
	if (type == 3)
		repo->expiresInX(FRUIT, days, d);
}