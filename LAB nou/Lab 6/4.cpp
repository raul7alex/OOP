#include <iostream>
#include <string> 
using namespace std;

class Engine{
public:
	void startEngine(){
		cout << "Engine start\n";
	}
	void stopEngine(){
		cout << "Engine stop\n";

	}
};

class DieselEngine :virtual public Engine{
public:
	void burnPetrol(){
		cout << "Petrol is buriningl";
	}
};

class ElectricEngine :virtual public Engine{
public:
	void useElectricEnergy(){
		cout << "Electric energy is used";
	}
};

class HibridEngine : public DieselEngine, public ElectricEngine{
};

int main(){
	HibridEngine engine;
	engine.startEngine();
	engine.burnPetrol();
	engine.useElectricEnergy();
	
}
