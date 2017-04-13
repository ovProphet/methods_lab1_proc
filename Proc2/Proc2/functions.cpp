#include <iostream>
#include <fstream>
#include <exception>
#include "declarations.h"
using namespace std;

struct container;
void CheckValueArea(int value, int a, int b)
{
	if (!(a <= value && value <= b))
	{
		cout << "Incorrect input values." << endl;
		exit(1);
	}
}
void InputFileCheck(ifstream& inputFile)
{
	if(!inputFile)
	{
		cout << "Cannot open input file." << endl;
		exit(1);
	}
}
void InputValuesCheck(ifstream& inputFile)
{
	if(inputFile.fail())
	{
		cout << "Incorrect input values." << endl;
		exit(1);
	}
}
void OutputFileCheck(ofstream& outputFile)
{
	if(!outputFile)
	{
		cout << "Cannot open output file." << endl;
		exit(1);
	}
}
void Init(container* &c)
{
	//new init
	c = new container;
	c->next = NULL;
	c->plant = NULL;
	c->length = 0;
}
void Clear(container* &c)
{
	container *cur = c, *prev = c;
	
	if(c != NULL)
	{
		while(cur->plant != NULL)
		{
			prev = cur;
			cur = cur->next;
			delete prev;
		}

		delete cur;
	}
	c = new container;
	c->next = NULL;
	c->plant = NULL;
	c->length = 0;
}
void In(container* &c, ifstream &inputFile)
{
	InputFileCheck(inputFile);
	container *cur = c;
	int cnt = 0;
	while(!inputFile.eof())
	{
		plant *p;
		if((p = In(inputFile))!=0)
		{
			if(cnt == 0)
				cur = c;
			c->plant = p;
			c->next = new container;
			c->next->next = NULL;
			c->next->plant = NULL;
			c->next->length = 0;
			c = c->next;
			++cnt;
		}
	}
	c = cur;
	c->length = cnt;
}
void Out(container* &c, ofstream &outputFile)
{
	OutputFileCheck(outputFile);
	outputFile << "Container contains " << c->length << " elements." << endl;
	container* cur = c;
	int counter = 0;
	while(cur->plant != NULL)
	{
		outputFile << ++counter << ": ";
		Out((plant*)cur->plant, outputFile);
		cur = cur->next;
	}
}
void In(tree* &t, ifstream &inputFile)
{
	InputFileCheck(inputFile);
	inputFile >> t->name >> t->age;
	InputValuesCheck(inputFile);
	if(t->age < 0)
	{
		cout << "Incorrect input values." << endl;
		exit(1);
	}
	int x;
	inputFile >> x;
	InputValuesCheck(inputFile);
	CheckValueArea(x,0,4);
	switch(x)
	{
	case 0:
		t->habitat = FOREST;
		break;
	case 1:
		t->habitat = FIELD;
		break;
	case 2:
		t->habitat = DESERT;
		break;
	case 3:
		t->habitat = TUNDRA;
		break;
	case 4:
		t->habitat = JUNGLE;
		break;
	}
}
void In(bush* &b, ifstream &inputFile)
{
	InputFileCheck(inputFile);
	int month;
	inputFile >> b->name >> month;
	InputValuesCheck(inputFile);
	CheckValueArea(month, 0, 11);
	switch(month)
	{
	case 0:
		b->blooming = bush::JAN;
		break;
	case 1:
		b->blooming = bush::FEB;
		break;
	case 2:
		b->blooming = bush::MAR;
		break;
	case 3:
		b->blooming = bush::APR;
		break;
	case 4:
		b->blooming = bush::MAY;
		break;
	case 5:
		b->blooming = bush::JUN;
		break;
	case 6:
		b->blooming = bush::JUL;
		break;
	case 7:
		b->blooming = bush::AUG;
		break;
	case 8:
		b->blooming = bush::SEP;
		break;
	case 9:
		b->blooming = bush::OCT;
		break;
	case 10:
		b->blooming = bush::NOV;
		break;
	case 11:
		b->blooming = bush::DEC;
		break;
	}
	int x;
	inputFile >> x;
	InputValuesCheck(inputFile);
	CheckValueArea(x, 0, 4);
	switch(x)
	{
	case 0:
		b->habitat = FOREST;
		break;
	case 1:
		b->habitat = FIELD;
		break;
	case 2:
		b->habitat = DESERT;
		break;
	case 3:
		b->habitat = TUNDRA;
		break;
	case 4:
		b->habitat = JUNGLE;
		break;
	}
}
void In(flower* &f, ifstream &inputFile)
{
	InputFileCheck(inputFile);
	int x;
	inputFile >> f->name >> x;
	InputValuesCheck(inputFile);
	CheckValueArea(x, 0, 3);
	switch(x)
	{
	case 0:
		f->type = flower::DOMESTIC;
		break;
	case 1:
		f->type = flower::GARDEN;
		break;
	case 2:
		f->type = flower::WILD;
		break;
	case 3:
		f->type = flower::BED;
		break;
	}
	inputFile >> x;
	InputValuesCheck(inputFile);
	CheckValueArea(x, 0, 4);
	switch(x)
	{
	case 0:
		f->habitat = FOREST;
		break;
	case 1:
		f->habitat = FIELD;
		break;
	case 2:
		f->habitat = DESERT;
		break;
	case 3:
		f->habitat = TUNDRA;
		break;
	case 4:
		f->habitat = JUNGLE;
		break;
	}
}
plant* In(ifstream &inputFile)
{
	InputFileCheck(inputFile);
	plant *pl;
	tree* t;
	bush* b;
	flower* f;
	int k;
	inputFile >> k;
	if(inputFile.eof())
	{
		return NULL;
	}
	InputValuesCheck(inputFile);
	CheckValueArea(k, 1, 3);
	switch(k)
	{
	case 1:
		t = new tree;
		t->k = TREE;
		In(t,inputFile);
		return (plant*)t;
	case 2:
		b = new bush;
		b->k = BUSH;
		In(b,inputFile);
		return (plant*)b;
	case 3:
		f = new flower;
		f->k = FLOWER;
		In(f,inputFile);
		return (plant*)f;
	default:
		return 0;
	}
}
void Out(bush* &b, ofstream &outputFile)
{
	OutputFileCheck(outputFile);
	outputFile << "It is a Bush: its name is " << b->name << ", its blooming month is ";
	switch(b->blooming)
	{
	case bush::JAN:
		outputFile << "January." << endl;
		break;
	case bush::FEB:
		outputFile << "February." << endl;
		break;
	case bush::MAR:
		outputFile << "March." << endl;
		break;
	case bush::APR:
		outputFile << "April." << endl;
		break;
	case bush::MAY:
		outputFile << "May." << endl;
		break;
	case bush::JUN:
		outputFile << "June." << endl;
		break;
	case bush::JUL:
		outputFile << "July." << endl;
		break;
	case bush::AUG:
		outputFile << "August." << endl;
		break;
	case bush::SEP:
		outputFile << "September." << endl;
		break;
	case bush::OCT:
		outputFile << "October." << endl;
		break;
	case bush::NOV:
		outputFile << "November." << endl;
		break;
	case bush::DEC:
		outputFile << "December." << endl;
		break;
	}

	switch(b->habitat)
	{
	case DESERT:
		outputFile << "Its natural habitat is desert." << endl;
		break;
	case TUNDRA:
		outputFile << "Its natural habitat is tundra." << endl;
		break;
	case FOREST:
		outputFile << "Its natural habitat is forest." << endl;
		break;
	case JUNGLE:
		outputFile << "Its natural habitat is jungle." << endl;
		break;
	case FIELD:
		outputFile << "Its natural habitat is field." << endl;
		break;
	}

	plant *p = (plant*)b;
	outputFile << "Its name has " << Consonant(p) << " consonants.\n";
}
void Out(tree* &t, ofstream &outputFile)
{
	OutputFileCheck(outputFile);
	outputFile << "It is a Tree: its name is " << t->name << ", its age is estimated to be " << t->age << " years." << endl;

	switch(t->habitat)
	{
	case DESERT:
		outputFile << "Its natural habitat is desert." << endl;
		break;
	case TUNDRA:
		outputFile << "Its natural habitat is tundra." << endl;
		break;
	case FOREST:
		outputFile << "Its natural habitat is forest." << endl;
		break;
	case JUNGLE:
		outputFile << "Its natural habitat is jungle." << endl;
		break;
	case FIELD:
		outputFile << "Its natural habitat is field." << endl;
		break;
	}
	plant *p = (plant*)t;
	outputFile << "Its name has " << Consonant(p) << " consonants.\n";
}
void Out(flower* &f, ofstream &outputFile)
{
	OutputFileCheck(outputFile);
	outputFile << "It is a Flower: its name is " << f->name << ". ";
	switch(f->type)
	{
	case flower::GARDEN:
		outputFile << "It's a garden flower." << endl;
		break;
	case flower::DOMESTIC:
		outputFile << "It's a domestic flower." << endl;
		break;
	case flower::WILD:
		outputFile << "It's a wild flower." << endl;
		break;
	case flower::BED:
		outputFile << "It's from a flower-bed." << endl;
		break;
	}
	
	switch(f->habitat)
	{
	case DESERT:
		outputFile << "Its natural habitat is desert." << endl;
		break;
	case TUNDRA:
		outputFile << "Its natural habitat is tundra." << endl;
		break;
	case FOREST:
		outputFile << "Its natural habitat is forest." << endl;
		break;
	case JUNGLE:
		outputFile << "Its natural habitat is jungle." << endl;
		break;
	case FIELD:
		outputFile << "Its natural habitat is field." << endl;
		break;
	}
	plant *p = (plant*)f;
	outputFile << "Its name has " << Consonant(p) << " consonants.\n";
}
void Out(plant* &p, ofstream &outputFile)
{
	OutputFileCheck(outputFile);
	tree* t;
	bush* b;
	flower* f;
	switch(p->k)
	{
	case TREE:
		t = (tree*)p;
		Out(t, outputFile);
		break;
	case BUSH:
		b = (bush*)p;
		Out(b, outputFile);
		break;
	case FLOWER:
		f = (flower*)p;
		Out(f, outputFile);
		break;
	default:
		outputFile << "Incorrect plant!" << endl;
	}
}
void OutFirstOnly(container* &c, ofstream &outputFile)
{
	OutputFileCheck(outputFile);
	container* cur = c;
	int counter = 0;
	while(cur->plant != NULL)
	{
		plant* p = cur->plant;
		cur = cur->next;
		if(p->k != 0)
			continue;
		outputFile << ++counter << ": ";
		Out(p, outputFile);
	}
}
void Sort(container* &c)
{
	container* start = c;
	for(int i = 0; i < start->length; ++i)
	{
		bool changed = false;
		container* cur = start;
		while(cur->next->plant != NULL)
		{
			int i1 = cur->plant->habitat;
			int i2 = cur->next->plant->habitat;
			if(i1 > i2)
			{
				plant* buf;
				buf = cur->plant;
				cur->plant = cur->next->plant;
				cur->next->plant = buf;
				changed = true;
			}
			cur=cur->next;
		}
		if(!changed)
			break;
	}
}
int Consonant(plant* &p)
{
	int res = 0;
	string cur = p->name;
	string alphabet = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
	for(int i = 0; i < alphabet.length(); ++i)
	{
		int c = count(cur.begin(), cur.end(), alphabet[i]);
		if (c > 0)
			res += c;
		if (res < 0)
		{
			cout << "Integer overflow." << endl;
			exit(1);
		}
	}
	return res;
}
void MultiMethod(container* &c, ofstream &ofst)
{
	ofst << "Multimethod." << endl;
	for (int i = 0; i < c->length - 1; ++i)
	{
		container* cur = c;
		plant* plant1 = cur->plant;
		int left = i;
		while(left)
		{
			cur = cur->next;
			plant1 = cur->plant;
			--left;
		}
		
		for(int j = i + 1; j < c->length; ++j)
		{
			cur = c;
			plant* plant2 = cur->plant;
			left = j;
			while(left)
			{
				cur = cur->next;
				plant2 = cur->plant;
				--left;
			}

			switch(plant1->k)
			{
				case key::TREE:
					switch(plant2->k)
					{
						case key::TREE:
							ofst << "-A tree and a tree:" << endl;
							break;
						case key::BUSH:
							ofst << "-A tree and a bush:" << endl;
							break;
						case key::FLOWER:
							ofst << "-A tree and a flower:" << endl;
							break;
						default:
							ofst << "-Unknown type of plant." << endl;
							break;
					}
					break;
				case key::BUSH:
					switch(plant2->k)
					{
						case key::TREE:
							ofst << "-A bush and a tree:" << endl;
							break;
						case key::BUSH:
							ofst << "-A bush and a bush:" << endl;
							break;
						case key::FLOWER:
							ofst << "-A bush and a flower:" << endl;
							break;
						default:
							ofst << "-Unknown type of plant." << endl;
							break;
					}
					break;
				case key::FLOWER:
					switch(plant2->k)
					{
						case key::TREE:
							ofst << "-A flower and a tree:" << endl;
							break;
						case key::BUSH:
							ofst << "-A flower and a bush:" << endl;
							break;
						case key::FLOWER:
							ofst << "-A flower and a flower:" << endl;
							break;
						default:
							ofst << "-Unknown type of plant." << endl;
							break;
					}
					break;
				default:
					ofst << "-Unknown type of plant." << endl;
					break;
			}
			Out(plant1,ofst);
			Out(plant2,ofst);
		}
	}
}