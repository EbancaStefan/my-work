#include <iostream>
#include "person.h"
#include <typeinfo>
#include <vector>
#include "coffeeshop.h"
using namespace std;

int main()
{
    Person p1("Average Joe",1);
    cout<<"person1 is "<<p1<<endl;
    Student s("Average Student",2);
    cout<<"student 1 is "<<s<<endl;
    Person p2("Ionel Mateescu",100);
    Person p3("Claudia Matei",3213);
    Student s2("Todd Howard",98912);
    Person p4("CJ",3213);
    cout<<"---"<<endl;
    CoffeeShop cs;
    cs.enqueue(&p1);
    cs.enqueue(&p2);
    cs.enqueue(&p3);
    cs.enqueue(&s);
    cs.enqueue(&s2);
    cs.enqueue(&p4);
    cs.serveClients();
    cout<<"created: "<<Person::getCreatedCount()<<endl;

//    std::vector<Person> v;
//    v.push_back(p1);
//    v.push_back(s);
//    int i;
//        if(strcmp(typeid (p1).name(),"class Person"))
//            cout<<"YESYESYES";
//        else
//            cout<<"NONONO";
//    cout<<"~~~~~"<<endl;
//    for(i=0;i<v.size();i++)
//    {

//        if(v[i].GetIdentification()==-1)
//            cout<<"Student = ";
//        else
//            cout<<"Person = ";
//        cout<<v[i]<<endl;
//    }
//    cout<<"~~~~~"<<endl;
//    cout<<typeid(p1).name()<<endl;
    return 0;
}
