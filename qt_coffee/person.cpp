#include "person.h"
int Person::CREATED_COUNT = 0;
Person::Person()
{
    m_name="";
    m_identification=-1;
    CREATED_COUNT++;
}

Person::Person(std::string name, int id)
{
    m_name=name;
    m_identification=id;
    CREATED_COUNT++;
}

std::string Person::GetName() const
{
    return m_name;
}

void Person::setName(const std::string &name)
{
    m_name = name;
}

int Person::GetIdentification() const
{
    return m_identification;
}

int Person::getCreatedCount()
{
    return CREATED_COUNT;
}

ostream & operator<<(ostream &stream, const Person &p)
{
    stream<<p.m_name<<" "<<p.m_identification;
    return stream;
}
ostream & operator<<(ostream &stream, const Student &s)
{
    stream<<s.GetName()<<" "<<s.m_enrollment;
    return stream;
}

Student::Student()
{
   this->setName("");
    m_enrollment=0;
    //CREATED_COUNT++;
}

Student::Student(std::string name, int id)
{
    this->setName(name);
    m_enrollment=id;
}

int Student::GetEnrollment() const
{
    return m_enrollment;
}
