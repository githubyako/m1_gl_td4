#include "person.hpp"

Person::Person():m_name("anonymous"),m_age(0)
{
  
}

Person::Person(const std::string& _name, int _age):m_name(_name),m_age(_age)
{

}

int Person::getAge() const
{
  return m_age;
}

const std::string& Person::getName() const
{
  return m_name;
}

bool Person::operator<(const Person& _p) const
{
  return (_p.getName().compare(m_name) >=0);
}




std::ostream& operator<<(std::ostream& _out, Person& _p)
{
  _out << "Name: " << _p.getName() << ", age: " << _p.getAge();
  return _out;
}

