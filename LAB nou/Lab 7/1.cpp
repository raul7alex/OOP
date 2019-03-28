#include <iostream>
using namespace std;

template <typename T>
T maxim(T a[], int n){
	T el = a[0];
	for(int i =1; i < n; i++)
		if(a[i] > el)
			el = a[i];
	return el;
}

template <typename T>
T minim(T a[], int n){
	T el = a[0];
	for(int i =1; i < n; i++)
		if(a[i] < el)
			el = a[i];
	return el;
}

template <typename T>
T cautare_secventiala(T a[], int n, T el_cautat){
	for(int i =0; i < n; i++)
		if(a[i]  == el_cautat)
			return el_cautat;
	return -1;
}
template <typename T>
bool cautare_binara(T s,T d,T a[],T x)
{
    if(s>d) return false;
    int m=(s+d)/2;
    if(a[m]==x) return true;
    if(a[m]<x) return cautare_binara(m+1,d,a,x);
    return cautare_binara(s,m-1,a,x);
}

template <typename T>
void Bule(T a[], int n)   
{
    int k=0;                  
	bool sortat = false;
	while (!sortat)
	{
		sortat = true;
		for (int i = 0; i < n-k -1; ++i)
			if (a[i] > a[i + 1])
			{
				T aux = a[i];
				a[i] = a[i + 1];
				a[i + 1] = aux;
				sortat = false;
			}
		if(sortat)
			break;
        k++;
	}
}

template <typename T>
void Selectie(T a[], int n
{                               
	for (int  i = 1; i < n; i++)
	{
		int pmin = i;
		bool ok = false;
		for (int j = i + 1; j <= n; j++) 
			if (a[j] < a[pmin])
			{
				pmin = j;
				ok = true;
			}
  
		if ( ok )
		{
			T aux = 0;
			aux = a[i];
			a[i] = a[pmin];
			a[pmin] = aux;
		}
	}
}


int main()
{
	
  
}
