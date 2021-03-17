#pragma once
#include "Product.h"
#include <stdlib.h>
//typedef struct
//{
//	Product* elems;
//	int len;
//	int cap;
//}ProductRepo;
//ProductRepo createProductRepo(int capacity);
class ProductRepo
{
public:

	Product elems[100];
	int len;
	int cap;
	ProductRepo(int capacity) :cap{ capacity }, len{ -1 }{};
	void destroy();
	bool add(Product prod);
	bool removeRepo(Product prod);
	bool update(Product prod,int quantity, Date expiration, Category type, std::string name);
	void display();
	void hasString(std::string string);
	void expiresInX(Category type, int x_days, Date current_date);
};



