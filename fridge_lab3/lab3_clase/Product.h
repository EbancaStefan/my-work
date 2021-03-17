#ifndef PRODUCT_H
#define PRODUCT_H
#define _CRT_SECURE_NO_WARNINGS
#include <string>
typedef enum {
	DAIRY,
	SWEET,
	MEAT,
	FRUIT
}Category;
typedef struct
{
	int day;
	int month;
	int year;
}Date;
class Product
{
protected:

public:
	std::string name;
	Category type;
	int quantity;
	Date expiration;
	Product() = default;
	Product(std::string name, Category type, int quantity, Date expiration):name{name},type{type},quantity{quantity},expiration{expiration}{}
	Date getExpiration();
	int getQuantity();
	Category getType();
	std::string getName();
	void toString();
};


#endif // !PRODUCT_H


