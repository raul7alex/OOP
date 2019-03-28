#include <iostream>
#include <string>
using namespace std;

class Animal{
public:
	virtual bool heterotof();

	int getVarsta(){
		return varsta;
	}
	void setVarsta(int varsta){
		this->varsta = varsta;
	}
	void setSpecie(string specie){
		this->specie = specie;
	}
	string getSpecie(){
		return specie;
	}
private:
	string specie;
	int varsta;

};

class Reptila : public Animal{
public:
	void taraste(){
	}

	void setlungime(int lungime){
		this->lungime = lungime;
	}

	int getLungime(){
		return lungime;
	}

private:
	int lungime;
};

class Pasare : public Animal{
public:
	void zboara(){
	}

	void setNrPene(int nrpene){
		this->nrpene = nrpene;
	}

	int getNrPene(){
		return nrpene;
	}

private:
	int nrpene;
};

class Ornitorinc : public Pasare, Reptila{
public:
	void amfibiu(){
	}

}

int main(){


}
