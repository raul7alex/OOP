#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Triunghi{
public:
	double getAria(){
		return (l1 * l2)/2;
	}
	double getPerimetru(){
		return l1+l2+l3;
	}
}

	int l1, l2, l3;

class Dreptunghi : public Triunghi{
public:
	double getAria(){
		return Triunghi::getAria();
	}
	double getPerimetru(){
		return l1+l2 *2;
	}
};

class Isoscel : public Triunghi{
public:
	double getAria(){
		return Triunghi::getAria();
	}

	double getPerimetru(){
		return Triunghi::getPerimetru();
	};
};

class Dreptunghi_Isoscel : public Isoscel, Dreptunghi{
	double getAria(){
		return Isoscel::getAria();
	}

	double getPerimetru(){
		return Dreptunghi::getPerimetru()/2;
	};
};

class Echilateral : Isoscel{
	double getAria(){
		return (l1 * sqrt(3))/2;
	}

	double getPerimetru(){
		return Triunghi::getPerimetru();
	};
};



int main(){


}
