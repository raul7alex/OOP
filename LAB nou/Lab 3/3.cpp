#include <iostream>
#include <math.h>
using namespace std;

class Carte{
public:
	Carte(){
	}
	Carte(string autor, string nume, string ISBN, float pret){
		this->autor = autor;
		this->nume = nume;
		this->ISBN = ISBN;
		this->pret = pret;	
		nr_instante++;

	}
	
	string getNumeAutor() const
	{
		return autor;
	}
	
	string getNumeCarte() const
	{
		return nume;
	}
	
	static inline int getNrInstante(){
		return nr_instante;
	}
private:
	string autor;
	string nume;
	string ISBN;
	float pret;
	static int nr_instante;
};
	int Carte::nr_instante = 0;

int main()
{

	int n;
	Carte carte[100];
	string autor, nume, ISBN;
	float pret;
	cout << "Numarul de carti: "; cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "autor: "; cin >> autor;
		cout << "nume: "; cin >> nume;
		cout << "ISBN: "; cin >> ISBN;
		cout << "Pret: "; cin >> pret;
		carte[i] = Carte(autor, nume, ISBN, pret);
	}
	
	if(n)
	{
		cout << "Numele autorului: "; cin >> autor;
		
		for(int i = 0; i < n; i++)
		{
			if(autor == carte[i].getNumeAutor())
			cout << carte[i].getNumeCarte();
		}
	}
	cout << "Numarul de instante ale clasei: "<< Carte::getNrInstante() <<'\n';
	
}
