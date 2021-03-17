#ifndef COFFEESHOP_H
#define COFFEESHOP_H
#include "person.h"
#include <vector>

class CoffeeShop
{
public:
    CoffeeShop();

    void enqueue(Person* p);
    void serveClients();
private:
    std::vector<Person> m_vector1;
    std::vector<Person> m_vector2;
};

#endif // COFFEESHOP_H
