#include <iostream>
#include <algorithm>
#include "Lista.h"
using namespace std;

class Person{
public:
	Person(){ name = ""; age = 0;}
    Person(string name, int age): name{name}, age{age}{}
    Person& operator=(const Person& x)
    {
        name = x.name;
        age = x.age;
        return *this;
    }
     friend ostream& operator<<(ostream& os, const Person p)
    {
       return os << p.name <<' '<<p.age;
    }
    
    int getAge() const
    {
		return age;
	}
	
	void change_dates(Person p)
	{
		age = p.age;
		name = p.name;
	}
public:
    string name;
    int age;
};

bool compare(Person a, Person b){
	return true;
}

int main()
{
	ListaD<Person> p;
	p.push_back(Person("Levitchi dan", 21));
	p.push_back(Person("Levitchi Darius", 22));
	p.push_back(Person("Levitchi Danut", 17));
	p.push_back(Person("Levitchi dan", 15));
	
	for(ListaD<Person>::Iterator it = p.begin(); it != p.end(); ++it)
		cout <<it.getAge() <<'\n';
	
	
	
    return 0;
}
