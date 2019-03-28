#include  <iostream>
using namespace std;


class Actor
{
public:
	Actor(){
	}
	Actor(string nume, string prenume){
		nr_actori++;
		this->nume = nume;
		this->prenume = prenume;
	}
	string getName(){
		return nume;
	}
	
	string getPrenume(){
		return prenume;
	}
	
	static int getNrActori(){
		return nr_actori;
	}
private:
	string nume;
	string prenume;
	static int nr_actori;
};

int Actor::nr_actori = 0;

class Film
{
public:
	Film(){
		nr_actori = 0;
	}
	
	void sterge_actor(Actor actor){
		for(int i = 0; i < nr_actori; i++)
			if(actori->getName() == actor.getName() && actori->getPrenume() == actor.getPrenume())
			{
				for(int j = i; j < nr_actori - 1; j++)
					actori[j] = actori[j+1];
				nr_actori--;
				break;
			}
	}
	
	inline float getBuget() const{
		return buget;
	}
	
	float getNrActori() const{
		return nr_actori;
	}
	
	Actor getActor(int i) const{
		return actori[i];
	}
private:
	Actor actori[100];
	int nr_actori;
	float buget;
};

void sortareFilme(Film filme[], int n)   
{
    int k=0;                  
	bool sortat = false;
	while (!sortat)
	{
		sortat = true;
		for (int i = 0; i < n-k -1; ++i)
			if (filme[i].getBuget() > filme[i + 1].getBuget())
			{
				Film aux = filme[i];
				filme[i] = filme[i + 1];
				filme[i + 1] = aux;
				sortat = false;
			}
			else
			if(filme[i].getBuget() ==filme[i + 1].getBuget() && filme[i].getNrActori() > filme[i + 1].getNrActori()){
				
			}
        k++;
	}
}

void afisareActoriComuni(const Film &film1,const  Film &film2){
	for(int i = 0; i < film1.getNrActori(); i++)
		for(int j = 0; j < film2.getNrActori(); j++)
			if(film1.getActor(i).getName() == film2.getActor(j).getName() && film1.getActor(i).getPrenume() == film2.getActor(j).getPrenume())
				cout <<"Actor comun: " << film1.getActor(i).getName() <<' ' << film1.getActor(i).getPrenume() <<'\n';
		
}


int main(){
}
