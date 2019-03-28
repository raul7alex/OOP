#include <iostream>
#include <math.h>
using namespace std;

class Punct3D{
public:
	Punct3D(){
		 x =0; y =0, z =0;
	}
	
	
	Punct3D(Punct3D& p)
	{
		x = p.x;
		y = p.y;
		z = p.z;
	}
	
	
	Punct3D(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	
	
	inline Punct3D& operator += (const Punct3D& c) 
	{
		x += c.x;
		y += c.y;
		z += c.z;
		
		return *this;
	}
	
	
	inline Punct3D& operator -= (const Punct3D& c) 
	{
		x -= c.x;
		y -= c.y;
		z -= c.z;
		return *this;
	}
	
	inline Punct3D& operator *= (const Punct3D& c) 
	{
		x *= c.x ;
		y *= c.y ;
		z *= c.z ;
		
	
		return *this;
	}
	
	inline Punct3D& operator /= (const Punct3D& c) 
	{
		x /= c.x;
		x /=  c.x;
		z /=  c.z;
 
		return *this;
	}
	
	
	Punct3D operator + (const Punct3D& c)
	{
		x += c.x;
		y += c.y;
		z += c.z;
		
		return *this;
	}
	
	inline Punct3D operator ++ ()
	{
		x += 1;
		y += 1;
		z += 1;
		
		return *this;
	}
	
	inline Punct3D operator -- ()
	{
		x -= 1;
		y -= 1;
		z -= 1;
		
		return *this;
	}
	
	inline friend istream& operator >> (istream& is, Punct3D& c)
	{		
		return is >> c.x >> c.y >> c.z;
	} 
	
	inline friend ostream& operator << (ostream& os, const Punct3D& c)
	{	
		return os << c.x <<' '<< c.y <<' '<<c.z <<'\n';
	} 
	
	
	inline bool operator == (const Punct3D& c){
		return x == c.x && y == c.y && z == c.z;
	}

	inline bool operator != (const Punct3D& c){
		return x != c.x || y != c.y || z != c.z;
	}
	
	inline bool operator > (const Punct3D& c){
		if(x != c.x)
			return x > c.x;
		else
		{
			if(y == c.y)
				return y > c.y;
			else
				return z > c.z;
		}
	}
	
	inline bool operator >= (const Punct3D& c){
		if(x != c.x)
			return x >= c.x;
		else
		{
			if(y == c.y)
				return y >= c.y;
			else
				return z >= c.z;
		}
	}

	inline bool operator < (const Punct3D& c){
		if(x != c.x)
				return x < c.x;
			else
			{
				if(y == c.y)
					return y < c.y;
				else
					return z < c.z;
			}
	}
	
	inline bool operator <= (const Punct3D& c){
		if(x != c.x)
				return x <= c.x;
			else
			{
				if(y == c.y)
					return y <= c.y;
				else
					return z <= c.z;
			}
	}
	
	inline Punct3D operator * (const Punct3D& c){
		x *= c.x ;
		y *= c.y ;
		z *= c.z ;
		

		return *this;
	}
	
	inline Punct3D operator / (const Punct3D& c){
		y /= c.y;
		x /=  c.x;
		z /=  c.z;
  
		return *this;
	}
	
	
	inline Punct3D& operator - (const Punct3D& c) 
	{
		x -= c.x;
		y -= c.y;
		z -= c.z;
		
		return *this;
	}
	
	double distanta(Punct3D a1, Punct3D a2)
{
	return  sqrt(pow(a1.x - a2.x, 2) + pow(a1.y - a2.y, 2) + pow(a1.z - a2.z, 2));
}
	
	
private:
	int x, y, z;
};

int main(){
	
	
	
}
