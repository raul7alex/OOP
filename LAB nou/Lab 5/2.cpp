#include <iostream>
#include <math.h>
using namespace std;

class Punct2D{
public:
	Punct2D(){
		 x =0; y =0;
	}
	
	
	Punct2D(Punct2D& p)
	{
		x = p.x;
		y = p.y;
	}
	
	
	Punct2D(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	

	
	inline Punct2D& operator += (const Punct2D& c) 
	{
		x += c.x;
		y += c.y;
		
		return *this;
	}
	
	
	inline Punct2D& operator -= (const Punct2D& c) 
	{
		x -= c.x;
		y -= c.y;
		
		return *this;
	}
	
	inline Punct2D& operator *= (const Punct2D& c) 
	{
		x *= c.x ;
		
	
		return *this;
	}
	
	inline Punct2D& operator /= (const Punct2D& c) 
	{
		x /= c.x;
		x /=  c.x;
 
		return *this;
	}
	
	
	Punct2D operator + (const Punct2D& c)
	{
		x += c.x;
		y += c.y;
		
		return *this;
	}
	
	inline Punct2D operator ++ ()
	{
		x += 1;
		y += 1;
		
		return *this;
	}
	
	inline Punct2D operator -- ()
	{
		x -= 1;
		y -= 1;
		
		return *this;
	}
	
	inline friend istream& operator >> (istream& is, Punct2D& c)
	{		
		return is >> c.x >> c.y;
	} 
	
	inline friend ostream& operator << (ostream& os, const Punct2D& c)
	{	
		return os << c.x <<' '<< c.y;
	} 
	
	
	inline bool operator == (const Punct2D& c){
		return x == c.x && y == c.y;
	}

	inline bool operator != (const Punct2D& c){
		return x != c.x || y != c.y;
	}
	
	inline bool operator > (const Punct2D& c){
		if(x == c.x)
			return y > c.y;
		else
			return x > c.x;
	}
	
	inline bool operator >= (const Punct2D& c){
		if(x == c.x)
			return y >= c.y;
		else
			return x >= c.x;
	}

	inline bool operator < (const Punct2D& c){
		if(x == c.x)
			return y < c.y;
		else
			return x < c.x;
	}
	
	inline bool operator <= (const Punct2D& c){
		if(x == c.x)
			return y <= c.y;
		else
			return x <= c.x;
	}
	
	inline Punct2D operator * (const Punct2D& c){
		x *= c.x ;
		if(y !=0 && c.y !=0)
			x += -(y *  c.y) ;
		else
			y = 0;
	
		return *this;

		return *this;
	}
	
	inline Punct2D operator / (const Punct2D& c){
		y /= c.y;
		x /=  c.x;
  
		return *this;
	}
	
	
	inline Punct2D& operator - (const Punct2D& c) 
	{
		x -= c.x;
		y -= c.y;
		
		return *this;
	}
	
	double distanta(Punct2D a1, Punct2D a2)
{
	return  sqrt(pow(a1.x - a2.x, 2) + pow(a1.y - a2.y, 2));
}
	
	
private:
	int x, y;
};

int main(){
	
	Punct2D p1, p2;
	cin >> p1 >> p2;
	cout << p1+p2;
	
}
