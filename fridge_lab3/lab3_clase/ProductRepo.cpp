#include "ProductRepo.h"
#include <stdlib.h>
#include <cstring>
#include <ctype.h>
#include <iostream>
void ProductRepo::destroy()
{
	free(elems);
}
bool ProductRepo::add(Product prod) {
	bool found = false;
	int i = 0;
	int poz = 0;
	
	while (i <= len && found == false)
	{
		if (elems[i].name==prod.name)
		{
			found = true;
			poz = i;
		}
		
		i++;
	}
	if (found == false)
	{
		//std::cout << "hei\n";
		//if (cap == len)
		//{
		//	elems = (Product*)realloc(elems, 2 * sizeof(Product) * cap);
		//	if (elems == nullptr)
		//		return false;
		//}
		elems[len + 1] = prod;
		len = len + 1;
	}
	if (found == true)
	{
		elems[poz].quantity=elems[poz].quantity+1;
		return false;
	}
	else
		return true;
}
bool ProductRepo::removeRepo(Product pl) {
	bool found = false;
	int i = 0;
	int poz;
	while (i <= len && found == false)
	{
		if (/*strcmp(elems[i].name, pl.name) == 0*/elems[i].name==pl.name)
		{
			found = true;
			poz = i;
		}
		i++;
	}
	if (found == true)
	{
		for (i = poz; i <= len - 1; i++)
		{
			elems[i] = elems[i + 1];
		}
		len--;
	}
	if (found == false)
		return false;
	else
		return true;
}
bool ProductRepo::update(Product prod,int quantity, Date expiration, Category type, std::string name)
{
	int i,yes,poz;
	yes = 0;
	for (i = 0; i <= len; i++)
	{
		if (/*strcmp(elems[i].name, prod.name) == 0*/elems[i].name==prod.name)
		{
			poz = i;
			yes = 1;
		}
	}
	if (yes == 1)
	{
		elems[poz].name=name;
		elems[poz].quantity = quantity;
		elems[poz].expiration = expiration;
		elems[poz].type = type;
		return true;
	}
	return false;
}
void ProductRepo::display()
{
	int i;
	for (i = 0; i <= len; i++)
	{
		elems[i].toString();
	}
}
void ProductRepo::hasString(std::string string)
{
	int i, j;
	char s[200] = "";
	//if (strcmp(string, "") == 0)
	//{
	//	Product aux();
	//	for (i = 0; i < len; i++)
	//	{
	//		for (j = i + 1; j <=len; j++)
	//		{
	//			if (elems[i].quantity < elems[j].quantity)
	//			{
	//				aux = elems[i];
	//				elems[i] = elems[j];
	//				elems[j] = aux;
	//			}
	//		}
	//	}
	//	for (i = 0; i <= len; i++)
	//	{
	//		elems[i].toString();
	//	}
	//}
	//else
	//{
	for (i = 0; i <= len; i++)
	{
		//if (s1.find(s2) != std::string::npos) {
		//	std::cout << "found!" << '\n';
		//}
		if (elems[i].name.find(string)!=std::string::npos)
		{
			elems[i].toString();
		}
	}
	/*}*/
}
void ProductRepo::expiresInX(Category type, int x_days, Date current_date)
{
	int month, dayz1, dayz2;
	int i, xd = 0;
	char str[200] = "";
	while (current_date.day > 30)
	{
		current_date.day = current_date.day - 30;
		current_date.month++;
	}
	while (current_date.month > 12)
	{
		current_date.month = current_date.month - 12;
		current_date.year++;
	}
	for (i = 0; i <= len; i++)
	{
		if (elems[i].type == type)
		{
			if (elems[i].expiration.year >= current_date.year)
			{
				dayz1 = elems[i].expiration.year * 365 + elems[i].expiration.month * 30 - elems[i].expiration.day;
				dayz2 = current_date.year * 365 + current_date.month * 30 - current_date.day;
				xd = dayz1 - dayz2;
				if (xd <= x_days)
				{
					elems[i].toString();
					//toString(repo->elems[i], str);
					//std::cout << str;
				}
			}
		}
	}
}
