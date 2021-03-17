#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <typeinfo>
#include <ostream>
#include <istream>
using namespace std;

class Person
{
public:
  Person();
  Person(std::string name,int id);

  int GetIdentification() const;
  static int getCreatedCount();

  std::string GetName() const;
  void setName(const std::string &name);

  friend ostream& operator<<(ostream & stream, const Person & p);

private:
  int m_identification;
  std::string m_name;
  static int CREATED_COUNT;
};
class Student:public Person
{
public:
    Student();
    Student(std::string name,int id);

    friend ostream& operator<<(ostream & stream, const Student & s);

    int GetEnrollment() const;

private:
    int m_enrollment;
};

#endif // PERSON_H
