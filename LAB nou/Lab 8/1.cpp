#include <iostream>
#include <fstream>
#include <set>
using namespace std;



struct Comp
{
	bool operator()(string x, string y) const
	{
		return x < y;	//ordonare descrescatoare dupa codul ASCII
	}
};

int main()
{
	ifstream fin("text.txt");
	string cuv;
	set<string, Comp> s1;
	   while (!fin.eof())
       {
			fin >> cuv;

            auto result = s1.insert(cuv);
			if (!result.second)
				std::cout << "Eroare in inserarea elementului!" << std::endl;
       }
	

	set<string, Comp>::iterator it;
	for( it = s1.begin(); it!=s1.end(); ++it)
		cout <<*it <<' ';
	cout <<'\n';



}
