#include <iostream>
#include <fstream>
#include "declarations.h"
#include "gtest/gtest.h"
using namespace std;
struct container;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Error!\nWaited: command input_file output_file\n";
		exit(1);
	}

	ifstream inputFile(argv[1]);
	ofstream outputFile(argv[2]);

	outputFile << "Start" << endl;
	container* c;
    Init(c);
	In(c, inputFile);
	outputFile << "Filled container:" << endl;
	Out(c, outputFile);
	
	Sort(c);
	outputFile << "Sorted container:" << endl;
	Out(c, outputFile);

	outputFile << "Elements of the first type only:" << endl;
	OutFirstOnly(c, outputFile);

	Clear(c);
	outputFile << "Empty container:" << endl;
	Out(c, outputFile);

	outputFile<< "Stop" << endl;
	return 0;
}