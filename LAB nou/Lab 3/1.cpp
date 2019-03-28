#include <iostream>
#include <math.h>
using namespace std;

class Dreapta{
public:
	
	~Dreapta(){
	}
	
	Dreapta(){
		m = 1;
		n = 0;
	}
	
	Dreapta(int n, int m) {
		this->n = n;
		this->m = m;
	}
	
	Dreapta(const Dreapta &obj){
		this-> n = obj.n;
		this-> m = obj.m;
	}

	int getN(){
		return n;
	}
	
	int getM(){
		return m;
	}
private:
	friend class Punct;
	int n, m;
};

class Punct{
public:
	Punct(){
			
	}

	Punct(Dreapta dr){
		x = 0; 
		y = 0;
		
		if(dr.m * x + dr.n == y)
			nrPuncteDreapta++;
		if((dr.m * x+ dr.m - y) > 0)
			nrPuncteSemiplanPozitiv++;
		else
			nrPuncteSemiplanNegativ++;
	}
	Punct(int x, int y, Dreapta dr){
		this->x = x;
		this->y = y;
		
		if(dr.m * x + dr.n == y)
			nrPuncteDreapta++;
		if((dr.m * x+ dr.m - y) > 0)
			nrPuncteSemiplanPozitiv++;
		else
			nrPuncteSemiplanNegativ++;
		
	}
	
	~Punct(){
	}
	
	friend double Distanta(Punct p1, Punct p2){
		return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y-p1.y, 2));
	}
	
	int getX(){
		return x;
	}
	int getY(){
		return y;
	}
	
private:
	friend class Dreapta;
	int x, y;
	static int nrPuncteSemiplanPozitiv;
	static int nrPuncteSemiplanNegativ;
	static int nrPuncteDreapta;
};

int Punct::nrPuncteDreapta = 0;
int Punct::nrPuncteSemiplanNegativ = 0;
int Punct::nrPuncteSemiplanPozitiv = 0;

void centru_greutate(Punct puncte[], int n){
	int x = 0;
	int y = 0;
	for(int i = 0;i < n; i++){
		x+=puncte[i].getX();
		y+=puncte[i].getY();
	}
	x/=n;
	y/=n;
	
	cout << "centrul de greutate este punctul cu coordonatele: (" << x << ',' << y <<')';
}

int main()
{

	Dreapta dreapta = Dreapta(5, 4);
	int n, x, y;
	cin >> n;
	Punct puncte[100];
	
	for(int i = 0; i < n; i++){
		cout << "x = "; cin >> x;
		cout << "y = "; cin >> y;
		puncte[i] = Punct(x, y, dreapta);
	}
	centru_greutate(puncte, n);
	
	
	
	
}
