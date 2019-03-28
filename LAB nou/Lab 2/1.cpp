#include <iostream>
using namespace std;

class Fractie
{
public:
	Fractie()
	{
		numitor = 1;
		numarator = 0;
	}
	
	Fractie(int numarator)
	{
		this->numarator = numarator;
		numitor = 1;
	}
	
	Fractie(int numarator, int numitor)
	{
		this->numitor = numitor;
		this->numarator = numarator;
	}
	
	Fractie(const Fractie& fr){
		numitor = fr.numitor;
		numarator = fr.numarator;
	}
	
	Fractie suma(Fractie fr1, Fractie fr2)
	{
		if(fr1.numitor != fr1.numarator){
			fr1.numarator *= fr2.numitor;
			fr2.numarator *= fr1.numitor;
			
			fr1.numitor *= fr2.numitor;
			
			
			
		}
		return simplificare(Fractie(fr1.numarator + fr2.numarator, fr1.numitor));
		
	}
	
	Fractie diferenta(Fractie fr1, Fractie fr2)
	{
		if(fr1.numitor != fr1.numarator){
			fr1.numarator *= fr2.numitor;
			
			fr2.numarator *= fr1.numitor;
			fr1.numitor *= fr2.numitor;	
			
		}
		return simplificare(Fractie(fr1.numarator - fr2.numarator, fr1.numitor));
	}
	
	Fractie inmultire(Fractie fr1, Fractie fr2)
	{
		Fractie fr;
		fr.numarator = fr1.numarator * fr2.numarator;
		fr.numitor = fr1.numitor * fr2.numarator;
		return simplificare(fr);
	}
	
	Fractie impartire(Fractie fr1, Fractie fr2)
	{
		return inmultire(fr1, Fractie(fr2.numitor, fr2.numarator));
	}
	
	static int cmmdc(int a, int b)
	{
		int rest;
		do
		{
			rest = a % b;
			a = b;
		b = rest;
		}while(rest);
    
    return a;
	}
	
	Fractie simplificare(Fractie fr){
		while(cmmdc(fr.numarator , fr.numitor) !=1)
		{
			int x = cmmdc(fr.numarator, fr.numitor);
			fr.numitor/=x;
			fr.numarator/=x;
		}

		return fr;
	}
	
	Fractie reciproca(Fractie fr){
		return fr;
	}
	
	bool egal(Fractie fr1, Fractie fr2){
		fr1 = simplificare(fr1);
		fr2 = simplificare(fr2);
		
		return fr1.numitor == fr2.numitor && fr1.numarator == fr2.numarator;
	}
	
	void print(){
		cout << numarator << "/" << numitor <<'\n';
	}
	
	
private:
	int numarator, numitor;
};

int main()
{
	Fractie fr1(12, 4), fr2(4, 6);
	
	fr1.suma(fr1, fr2).print();
}
