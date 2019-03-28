#include <iostream>
#include <fstream>
#include <set>
using namespace std;

class Student{
public:
	Student(string nume, string CNP, string nota_laborator, string nota_examen, string numar_absente){
		this->nume = nume;
		this->CNP = CNP;
		this->nota_exament = nota_exament;
		this->nota_laborator = nota_laborator;
		this->numar_absente = numar_absente;
	}
	
	string getNotaExamen() const{
		return nota_exament;
	}
	
	string getNume() const{
		return nume;
	}
	
	
	string getCNP() const{
		return CNP;
	}
	
	string getNotaLaborator() const{
		return nota_laborator;
	}
	
	string getNrAbsente() const{
		return numar_absente;
	}
	
	bool operator == (const Student & student){
		return CNP == student.getCNP();
	}
	
	inline friend istream& operator >> (istream& is, Student& s)
	{		
		return is >> s.nume >> s.CNP >> s.nota_laborator >> s.nota_exament >> s.numar_absente;
	} 
	
	inline friend ostream& operator << (ostream& os, const Student& s)
	{	
		return os << s.nume <<' '<< s.CNP <<' '<<s.nota_laborator << ' '<< s.nota_exament <<' '<< s.numar_absente;
	} 
	

private:
	string nume, CNP, nota_laborator, nota_exament, numar_absente;
};

struct ComparanNota
{
	bool operator()(Student x, Student y) const
	{
		return stoi(x.getNotaExamen()) <  stoi(y.getNotaExamen());
	}
};
	
struct ComparaNume
{
	bool operator()(Student x, Student y) const
	{
		return x.getNume() < y.getNume();
	}
};

Student searchforStudent(set<Student, ComparanNota> sets, string name){
	set<Student, ComparanNota>::iterator it;
	for( it = sets.begin(); it!=sets.end(); ++it)
		if(it->getNume() == name)
			return *it;
} 


int main()
{
	ifstream fin("students.txt");
	
	set<Student, ComparanNota> setOfStudents;
	
	string nume, CNP, nota_laborator, nota_exament, numar_absente;
	   while (!fin.eof()) 
       {
			fin >> nume;
			fin >> CNP;
			fin >> nota_laborator;
			fin >> nota_exament;
			fin >> numar_absente;
			setOfStudents.insert(Student(nume, CNP, nota_laborator,
				nota_exament, numar_absente));
       }
       
       
	set<Student, ComparanNota>::iterator it;
	for( it = setOfStudents.begin(); it!=setOfStudents.end(); ++it)
		cout <<*it <<' ';
	cout <<'\n';
		

	
		
	
	
}




