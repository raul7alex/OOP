#include <iostream>
#include "Liste.h"
using namespace std;

class Person{
public:
	Person()
	{
		name = "";
		age = 0;
	}
    Person(string name, int age): name{name}, age{age}
    {
    }
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
private:
    string name;
    int age;

};


int main()
{

    Lista<Person> p1;
    p1.push_back(Person("Victimescu", 20));
    p1.push_back(Person("Condrea", 50));
    p1.push_front(Person("Ionela", 20));

	Lista<Person> p2;
    p2.push_back(Person("Ana", 30));
    p2.push_back(Person("Maria", 10));
    p2.push_front(Person("Daria", 20));


	Lista<Lista<Person> > catalog;

	catalog.push_back(p1);
	catalog.push_back(p2);

	Lista<Lista<Person> >::Iterator itr;

	for(itr = catalog.begin(); itr!= catalog.end(); itr++)
	{
		Lista<Person> p=*itr;

		Lista<Person>::Iterator it;
		for(it = p.begin(); it != p.end(); it++)
			{
				cout << *it <<'\n';
			}
		cout <<'\n';

	}

    return 0;
}
