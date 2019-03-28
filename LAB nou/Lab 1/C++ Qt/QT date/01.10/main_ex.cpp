#include <fstream>
using namespace std;


int main(int argc, char* argv[])
{
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	
	int x, y;
	fin >> x >> y;
	
	fout << "Suma: " << x + y;
	fout.close();
}
