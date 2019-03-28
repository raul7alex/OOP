#include <iostream>
#include <string> 
using namespace std;

class Persoana{
public:
	virtual string getNume();
private:
	string nume;
};

class Student : public Persoana{
public:
	int  getNota(){
		return nota;
	}
	
	string getDetalii(){
		return  "Studentul[" + getNume() + "[are nota[" + to_string(nota) + "].";
	}
private:
	string email;
	int nota;
};

class Profesor : public Persoana{
public:
	string email;
	string getMaterie(){
		return materie;
	}
	string getDetalii(){
		return  "Profesorul[" + getNume() + "]preda [" + materie + "].";
	}
private:
	string  materie;
};

class Angajat : public Persoana{
public:
	string getDepartament(){
		return departament;
	}
	string getDetalii(){
		return  "angajatul[" + getNume() + "] face parte din departamentul [" + departament + "].";
	}
	
private:
	string email, departament;
};

int main(){
	
	
}
