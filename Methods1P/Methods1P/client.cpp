#include <iostream>
#include <fstream>
#include "declarations.h"

using namespace std;
struct container;
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Error!\nWaited: command input_file output_file\n";
		exit(1);
	}

	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);

	ofst << "Start" << endl;
	container* c;
    Init(c);
	In(c, ifst);
	ofst << "Filled container:" << endl;
	Out(c,ofst);
	
	Sort(c);
	ofst << "Sorted container:" << endl;
	Out(c,ofst);

	ofst << "Elements of the first type only:" << endl;
	OutFirstOnly(c,ofst);

	Clear(c);
	ofst << "Empty container:" << endl;
	Out(c,ofst);

	ofst<< "Stop" << endl;
	return 0;
}