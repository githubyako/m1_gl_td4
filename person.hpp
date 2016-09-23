#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

class Person{
private:
std::string m_name;
int m_age;

public:
  Person();
  Person(std::string const& _name, int _age);
  std::string const & getName() const;
  int getAge() const;
  bool operator < (const Person& _p) const;
    

};
std::ostream& operator<<(std::ostream& _out, Person& _p);  
#endif
