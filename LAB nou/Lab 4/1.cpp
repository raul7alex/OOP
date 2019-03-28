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
	
	inline Fractie simplificare(Fractie fr){
		while(cmmdc(fr.numarator , fr.numitor) !=1)
		{
			int x = cmmdc(fr.numarator, fr.numitor);
			fr.numitor/=x;
			fr.numarator/=x;
		}

		return fr;
	}

	
	inline Fractie& operator += (const Fractie& fr) 
	{
		if(numitor != fr.numitor){
			numarator =numarator * fr.numitor + fr.numarator * numitor;
			numitor *= fr.numitor;
		}
		
		*this =  simplificare(Fractie(numarator, numitor));
		return *this;
	}
	
	
	inline Fractie& operator -= (const Fractie& fr) 
	{
		if(numitor != fr.numitor){
			numarator =numarator * fr.numitor - fr.numarator * numitor;
			numitor *= fr.numitor;
		}
				
		*this =  simplificare(Fractie(numarator, numitor));
		return *this;
	}
	
	inline Fractie& operator *= (const Fractie& fr) 
	{
		Fractie fractie;
		fractie.numarator = numarator * fr.numarator;
		fractie.numitor = numitor * fr.numitor;
		*this = simplificare(fractie);

		return *this;
	}
	
	inline Fractie& operator /= (const Fractie& fr) 
	{
		
		numitor *= fr.numarator;
		numarator *= fr.numitor;
		Fractie f  = *this;
		*this  = simplificare(f);
 
		return *this;
	}
	
	Fractie operator + (const Fractie& fr)
	{
		if(numitor != fr.numitor){
			numarator =numarator * fr.numitor + fr.numarator * numitor;
			numitor *= fr.numitor;
		}
		
		return  simplificare(Fractie(numarator, numitor));
	}
	
	inline Fractie operator ++ ()
	{
		Fractie fr = *this;
		fr+=1;
		*this = fr;
		return *this;
	}
	
	inline Fractie operator -- ()
	{
		Fractie fr = *this;
		fr-=1;
		*this = fr;
		return *this;
	}
	
	inline friend istream& operator >> (istream& is, Fractie& f)
	{		
		return is >> f.numarator >> f.numitor;
	} 
	
	inline friend ostream& operator << (ostream& os, const Fractie& f)
	{	
		return os << f.numarator <<'/'<< f.numitor;
	} 
	
	inline bool egal(Fractie fr1, Fractie fr2){
		fr1 = simplificare(fr1);
		fr2 = simplificare(fr2);
		
		return fr1.numitor == fr2.numitor && fr1.numarator == fr2.numarator;
	}
	
	inline bool operator == (const Fractie& fr){
		return numarator == fr.numarator && numitor == fr.numitor;
	}


	inline bool operator != (const Fractie& fr){
		return numarator/numitor != fr.numarator/numitor;
	}
	
	inline bool operator > (const Fractie& fr){
		return numarator/numitor > fr.numarator/numitor;
	}
	
	inline bool operator >= (const Fractie& fr){
		return numarator/numitor > fr.numarator/numitor;
	}

	inline bool operator < (const Fractie& fr){
		return numarator/numitor < fr.numarator/numitor;
	}
	
	inline bool operator <= (const Fractie& fr){
		return numarator/numitor <= fr.numarator/numitor;
	}
	
	inline Fractie operator * (const Fractie& fr){
		Fractie fractie;
		fractie.numarator = numarator * fr.numarator;
		fractie.numitor = numitor * fr.numitor;
		*this = simplificare(fractie);

		return *this;
	}
	
	inline Fractie operator / (const Fractie& fr){
		numitor *= fr.numarator;
		numarator *= fr.numitor;
		Fractie f  = *this;
		*this  = simplificare(f);
 
		return *this;
	}
	
	
	inline Fractie& operator - (const Fractie& fr) 
	{
		if(numitor != fr.numitor){
			numarator =numarator * fr.numitor - fr.numarator * numitor;
			numitor *= fr.numitor;
				
		*this =  simplificare(Fractie(numarator, numitor));
		return *this;
	}
	
private:
	int numarator, numitor;
};

	
int main()
{
	Fractie fr1(12, 4), fr2(4, 6);
	
	cout << fr1 * fr2;
	
	
}
