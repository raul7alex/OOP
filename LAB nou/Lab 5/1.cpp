#include <iostream>
using namespace std;

class Angajat {
public:
	double getSalar(){
		return tarifOrar * nrOre;
	}
	
	double tarifOra(){
		return tarifOrar;
	}
private:
	double tarifOrar = 5.5;
	int nrOre = 10;
};

class Manager : public Angajat{
public:
	double getSalar(){
		return Angajat::getSalar() + Angajat::getSalar() *1/2; 
	}
};

int main(){
	Angajat a =  Angajat();
	cout << a.tarifOra() <<'\n';
	cout << a.getSalar() <<'\n';
	
	Manager m = Manager();
	cout << m.tarifOra() <<'\n';
	cout << m.getSalar() <<'\n';
	
}
