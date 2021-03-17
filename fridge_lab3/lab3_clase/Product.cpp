#include "Product.h"
#include <string.h>
#include <iostream>
Date Product::getExpiration()
{
	return expiration;
}
Category Product::getType()
{
	return type;
}
int Product::getQuantity()
{
	return quantity;
}
std::string Product::getName()
{
	return name;
}
void Product::toString()
{
	char categoryToString[4][30] = {
		"DAIRY",
		"SWEET",
		"MEAT",
		"FRUIT",
	};
	std::cout << "Product " << name << " is of category " << categoryToString[type] << " with quantity " << quantity << " and expires at " << expiration.day << "/" << expiration.month << "/" << expiration.year << ".\n";
}