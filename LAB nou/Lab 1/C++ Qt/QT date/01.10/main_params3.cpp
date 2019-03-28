#include <iostream>
using namespace std;


int main(int argc, char* argv[], char* env[])
{
	
	cout << "Variabilele de mediu: \n";
	
	for (int i = 0; env[i]; ++i)
		cout << env[i] << '\n';
	
}
