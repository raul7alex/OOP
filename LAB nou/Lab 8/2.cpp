#include <iostream>
#include <fstream>
#include <map>
using namespace std;

	
int main()
{
	ifstream fin("text.txt");
	string cuv;
	
	map<string, int> m;
 
	 while (!fin.eof()) 
     {
		fin >> cuv;	
		m[cuv]++;

     }
	
	for (std::map<string,int>::iterator it=m.begin(); it!=m.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

	
}




