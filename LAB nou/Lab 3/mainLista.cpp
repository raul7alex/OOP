#include <iostream>
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
private:
    string name;
    int age;
};

int main()
{
	  ListaD<Person> p;
	int meniu;
	do{
		
		cout << "0. Iesire din program\n";
		cout << "1. Initializare LDI\n";
		cout << "2. Inserare in LDI\n";
		cout << "3. Stergere din LDI\n";
		cout << "4. Cautare in LDI\n";
		cout << "5. Actalizare(modificare)\n";
		cout << "5.Afisare LDI\n";
		cout << "6. Eliberare LDI\n";
		cin >> meniu;
		
		switch(meniu){
		case 1: {
			
			break;
		}
		case 2: {
			int c;
			cout << "0. Push_back\n";
			cout << "1. Push_front\n";
			cout << "2. Inserare pozitia LSI\n";
			cin >> c;
			
			string name; int age;
			cout << "name: "; cin >> name;
			cout << "age: "; cin >> age;
			switch(c)
			{
				case 0: {
				p.push_back(Person(name, age));
				break;
				}
				case 1: {
				p.push_front(Person(name, age));
				break;
				}
				case 2: {
					cout <<"Pozitia de inserare";
					int x;
					cin >> x;
					
					ListaD<Person>::Iterator it = p.begin();
					while(x)
					{
						it++;
						--x;
					}
					p.insert_before(Person(name, age), it);
					break;
				}
				default: {
					cout << "valoare gresita";
					break;
				}
			}
			break;
		}
		case 3: {
			int c;
			cout << "0. pop_back\n";
			cout << "1. pop_front\n";
			cout << "2. erase LSI\n";
			cin >> c;
		
			switch(c)
			{
				case 0: {
				p.pop_back();
				break;
				}
				case 1: {
				p.pop_front();
				break;
				}
				case 2: {
					cout <<"Pozitia de stergere";
					int x;
					cin >> x;
					
					ListaD<Person>::Iterator it = p.begin();
					while(x)
					{
						it++;
						--x;
					}
					p.remove(it);
					break;
				}
				default: {
					cout << "valoare gresita";
					break;
				}
			}
			break;
		}
		
		case 4: {
			cout <<"4...";
			break;
		}
		case 5: {
			 for(ListaD<Person>::Iterator it = p.begin(); it != p.end(); it++)
				cout << *it <<'\n';
			break;
		}
		case 6: {
			 p.clear();
			break;
		}
		default: {
			cout <<"Varianta gresita";
			break;
		}	
	}
		//int x;
		//cout <<" introdu orice caracter pentru stergere ecran"; cin >> x;
		// system("clear"); 	//system("cls"); windows
	}while(meniu);

    return 0;
}
