#include "coffeeshop.h"
#include "person.h"
#include <iostream>
using namespace std;
CoffeeShop::CoffeeShop()
{

}

void CoffeeShop::enqueue(Person *p)
{
    m_vector1.push_back(*p);
}

void CoffeeShop::serveClients()
{
    int i;

    for(i=0;i<m_vector1.size();i++)
    {
        if(m_vector1[i].GetIdentification()==-1)
        {
            m_vector2.push_back(m_vector1[i]);
        }
    }
    for(i=0;i<m_vector1.size();i++)
    {
        if(m_vector1[i].GetIdentification()!=-1)
        {
            m_vector2.push_back(m_vector1[i]);
        }
    }
    for(i=0;i<m_vector2.size();i++)
    {
        std::cout<<m_vector2[i]<<endl;
    }
}
