#pragma once
#include "Product.h"
#include "ProductRepo.h"
#include "cstack.h"
class Controller
{
public:
	ProductRepo* repo;
	Stack undoStack;
	Stack redoStack;
	Controller(ProductRepo* repo) :repo{ repo } {};
	void loadProductData();
	bool addProduct(Product prod);
	bool removeProduct(Product prod);
	void displayProduct();
	bool updateProduct(Product prod,int quantity, Date expiration, Category type, std::string name);
	void ctrlString(std::string string);
	void ctrlExpiresIn();
	void undo();
	void redo();
};



