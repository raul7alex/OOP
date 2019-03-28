#include <iostream>
#include <vector>
#include<string>
using namespace std;

class ContBancar;

class Operatiuni{
public:
	virtual float getSumaTotala()=0;
	virtual float getDobanda(int nr_zile)=0;
	virtual void depunere(ContBancar contDest, float suma)=0;
	virtual void extragere(ContBancar contDest, float suma)=0;
	
};

class ContBancar : public Operatiuni{
public:
	ContBancar(){
	}
	
	ContBancar(string moneda){
		numarCont = "NumarContNou"+ to_string(codUnic++);
		suma  = 0;
		this->moneda = moneda;
	}
	
	ContBancar(string numarCont, float suma, string moneda){
		this->numarCont = numarCont;
		this->suma = suma;
		this->moneda = moneda;
	}
	float getSumaTotala()
	{
		return suma;
	}

	void depunere(ContBancar contDest, float suma)
	{	
		contDest.suma +=suma;
	}
	void extragere(ContBancar contDest, float suma)
	{
		this->suma-= suma;
	} 
	
	string get_numar_cont(){
		return numarCont;
	}
	
	 static void transfer(ContBancar ct1, ContBancar ct2, int suma)
	{
		if (ct1.moneda !="RON" || ct2.moneda != "RON")
			cout << "tranzactie esuata";
		return;

		if(ct2.suma < suma)
			cout << "tranzactie esuata - suma insuficienta";
		return;
		
		ct1.suma += suma;
		ct2.suma -= suma;
		
	} 
	
	float getDobanda(int nr_zile){
		if(moneda == "RON"){
			if(suma < 500)
				return 0.3 * suma * nr_zile;
			else
				return 0.5 * suma * nr_zile;
		}
		else
		return 0.1 * suma * nr_zile;
	}

private:
	static int codUnic;
	string numarCont;
	float suma;
	string moneda;
};

int ContBancar::codUnic = 0;

class Client{
public:
	Client(){
	}
	Client(string nume, string prenume,string adresa){
		this->nume = nume;
		this->prenume = prenume;
		this->adresa = adresa;
	}
	
	
	void adauga_cont(ContBancar cont){
		conturi[nrConturi++] = cont;
	}
	
	string get_name(){
		return nume;
	}
	
	int get_nr_conturi(){
		return nrConturi;
	}
	
	ContBancar get_cont_bancar(int i){
		 return conturi[i];
	}
	
private:
	string nume;
	string prenume;
	string adresa;
	ContBancar conturi[10];
	int nrConturi = 0;
};

class Banca{
public:
	Banca(){
	}
	Banca(string codBanca){
		codBanca = codBanca;
		nrClienti = 0;
	}
	
	void adaugareClient(Client client){
		clienti[nrClienti++] = client;
	}
private:
	Client clienti[10];
	string codBanca;
	int nrClienti = 0;
};



int main()
{
	Banca banca("CodBANCA5843");
	int n;
	Client client[10]; 
	
	string nume, prenume, domiciliu, moneda;
	cout << "Introduceti numarul de clienti: "; cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "Introduceti numele clientului:"; cin >> nume;
		cout << "Introduceti prenumele clientului:"; cin >> prenume;
		cout << "Introduceti domiciliul clientului:"; cin >> domiciliu;
		client[i] = Client(nume, prenume, domiciliu);
		banca.adaugareClient(client[i]);
		
		int x;
		cout << "Introduceti numarul de conturi ale clientului :";
		cin >> x;
		for(int j = 0; j < x; j++)
		{
			cout << "Introduceti moneda in care doriti sa deschideti contul (RON / EURO)";
			cin >> moneda;
			client[i].adauga_cont(ContBancar(moneda));
		}
	}
	
	
	for(int i = 0; i < n; i++){
			
		cout << client[1].get_name() <<'\n';
		for(int i = 0; i < client[1].get_nr_conturi(); i++)
		{
			cout << "numar cont bancar: " <<client[1].get_cont_bancar(i).get_numar_cont() <<'\n';
			cout <<"Suma depusa in cont " ; int x; cin >> x;
			client[1].get_cont_bancar(i).depunere(client[1].get_cont_bancar(i), x);
			cout <<"nr zile pe care se calculeaza dobanda: " ;  cin >> x;
			cout << "dobanda: " <<client[1].get_cont_bancar(i).getDobanda(x) <<'\n';
			cout <<"Suma extrasa din cont: " ;  cin >> x;
			client[1].get_cont_bancar(i).extragere(client[1].get_cont_bancar(i), 100);
			cout << "suma totala: " << client[1].get_cont_bancar(i).getSumaTotala() <<"/n";
			bool ok;
			cout << "Doriti sa faceti un transfer de bani? (1/0)";
			cin >> ok;
			if(ok && client[1].get_nr_conturi() > 2)
				ContBancar::transfer(client[1].get_cont_bancar(1), client[1].get_cont_bancar(2), 100);
		}
	}
	
}
