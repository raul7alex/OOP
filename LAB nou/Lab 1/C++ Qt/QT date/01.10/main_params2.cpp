#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
	cout << "Nr argumente in linia de comanda: " << argc << '\n';
	
	for (int i = 0; i < argc; ++i)
		cout << argv[i] << '\n';
	
}
