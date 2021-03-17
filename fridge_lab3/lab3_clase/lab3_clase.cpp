/*The company “Home SmartApps” has decided to
design a new intelligent refrigerator.Besides the
hardware, they need a software application to
manage the refrigerator.Each Product has a
name, a category(may be dairy, sweets, meat or fruit), a quantityand an expiration date.
    a.The application must allow adding, deletingand updating a product.A product is uniquely
    identified by nameand category.If a product that already exists is added, its quantity will be
    updated(the new quantity is added to the existing one).
    b.The application should offer the possibility to display all the products whose names contain a
    given string(if the string is empty, all products from the refrigerator are considered) and they will
    be shown sorted ascending by their quantities.
    c.The application should be able to display all products of a given category(if the category is
        empty, all types of food will be considered) whose expiration dates are close(expire in the
            following given X days).
    d.The application must provide multiple undoand redo functionality.Each step will undo / redo
    the previous operation performed by the user.*/
#include <iostream>
#include "Product.h"
#include "ProductRepo.h"
#include "Controller.h"
#include "UI.h"
#include "cstack.h"
//#include "ProductRepo.cpp"
//#include "Controller.cpp"
//#include "UI.cpp"
//#include "Product.cpp"
using namespace std;
int main()
{
     int repoSize = 100;
    ProductRepo repo(repoSize);
    Controller ctrl(&repo);
    ctrl.loadProductData();
    displayUI(&ctrl);
    Date d;
    d.day = 12;
    d.month = 12;
    d.year = 2012;
    std::string str = "Corn cu ciocolata";
    Product prod(str, SWEET, 1, d);
    //repo.add(prod);
    //repo.display();
    //ctrl.addProduct(prod);
    //ctrl.displayProduct();

    //prod.toString();
    //Product elems[20];
    //elems[0] = prod;
    //elems[0].toString();




    //testare add ctrl si remove
    //addProduct(&ctrl, prod);
    //removeProduct(&ctrl, prod);
    //displayProduct(&ctrl);

    //char s[2000] = "";
    //toString(prod, s);
    //cout << s;

    //add(&repo, prod);

    //char str1[20] = "cu";
    //hasString(&repo, str1);
    //Element elem;
    //elem.prod = prod;
    //Stack st = createStack();
    ////printstack(&st);
    //push(&st, elem);
    //printstack(&st);
    //pop(&st);
    //printstack(&st);
}