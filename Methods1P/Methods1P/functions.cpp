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
void InputFileCheck(ifstream& ifst)
{
	if(!ifst)
	{
		cout << "Cannot open input file." << endl;
		exit(1);
	}
}
void InputValuesCheck(ifstream& ifst)
{
	if(ifst.fail())
	{
		cout << "Incorrect input values." << endl;
		exit(1);
	}
}
void OutputFileCheck(ofstream& ofst)
{
	if(!ofst)
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
	c->pl = NULL;
	c->len = 0;
}
void Clear(container* &c)
{
	container *cur = c, *prev = c;
	
	if(c != NULL)
	{
		while(cur->pl != NULL)
		{
			prev = cur;
			cur = cur->next;
			delete prev;
		}

		delete cur;
	}
	c = new container;
	c->next = NULL;
	c->pl = NULL;
	c->len = 0;
}
void In(container* &c, ifstream &ifst)
{
	InputFileCheck(ifst);
	container *cur = c;
	int cnt = 0;
	while(!ifst.eof())
	{
		plant *p;
		if((p = In(ifst))!=0)
		{
			if(cnt == 0)
				cur = c;
			c->pl = p;
			c->next = new container;
			c->next->next = NULL;
			c->next->pl = NULL;
			c->next->len = 0;
			c = c->next;
			++cnt;
		}
	}
	c = cur;
	c->len = cnt;
}
void Out(container* &c, ofstream &ofst)
{
	OutputFileCheck(ofst);
	ofst << "Container contains " << c->len << " elements." << endl;
	container* cur = c;
	int counter = 0;
	while(cur->pl != NULL)
	{
		ofst << ++counter << ": ";
		Out((plant*)cur->pl, ofst);
		cur = cur->next;
	}
}
void In(tree* &t, ifstream &ifst)
{
	InputFileCheck(ifst);
	ifst >> t->name >> t->age;
	InputValuesCheck(ifst);
	if(t->age < 0)
	{
		cout << "Incorrect input values." << endl;
		exit(1);
	}
	int x;
	ifst >> x;
	InputValuesCheck(ifst);
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
void In(bush* &b, ifstream &ifst)
{
	InputFileCheck(ifst);
	int mon;
	ifst >> b->name >> mon;
	InputValuesCheck(ifst);
	CheckValueArea(mon,0,11);
	switch(mon)
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
	ifst >> x;
	InputValuesCheck(ifst);
	CheckValueArea(x,0,4);
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
void In(flower* &f, ifstream &ifst)
{
	InputFileCheck(ifst);
	int x;
	ifst >> f->name >> x;
	InputValuesCheck(ifst);
	CheckValueArea(x,0,3);
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
	ifst >> x;
	InputValuesCheck(ifst);
	CheckValueArea(x,0,4);
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
plant* In(ifstream &ifst)
{
	InputFileCheck(ifst);
	plant *pl;
	tree* t;
	bush* b;
	flower* f;
	int k;
	ifst >> k;
	if(ifst.eof())
	{
		return NULL;
	}
	InputValuesCheck(ifst);
	CheckValueArea(k,1,3);
	switch(k)
	{
	case 1:
		t = new tree;
		t->k = TREE;
		In(t,ifst);
		return (plant*)t;
	case 2:
		b = new bush;
		b->k = BUSH;
		In(b,ifst);
		return (plant*)b;
	case 3:
		f = new flower;
		f->k = FLOWER;
		In(f,ifst);
		return (plant*)f;
	default:
		return 0;
	}
}
void Out(bush* &b, ofstream &ofst)
{
	OutputFileCheck(ofst);
	ofst << "It is a Bush: its name is " << b->name << ", its blooming month is ";
	switch(b->blooming)
	{
	case bush::JAN:
		ofst << "January." << endl;
		break;
	case bush::FEB:
		ofst << "February." << endl;
		break;
	case bush::MAR:
		ofst << "March." << endl;
		break;
	case bush::APR:
		ofst << "April." << endl;
		break;
	case bush::MAY:
		ofst << "May." << endl;
		break;
	case bush::JUN:
		ofst << "June." << endl;
		break;
	case bush::JUL:
		ofst << "July." << endl;
		break;
	case bush::AUG:
		ofst << "August." << endl;
		break;
	case bush::SEP:
		ofst << "September." << endl;
		break;
	case bush::OCT:
		ofst << "October." << endl;
		break;
	case bush::NOV:
		ofst << "November." << endl;
		break;
	case bush::DEC:
		ofst << "December." << endl;
		break;
	}

	switch(b->habitat)
	{
	case DESERT:
		ofst << "Its natural habitat is desert." << endl;
		break;
	case TUNDRA:
		ofst << "Its natural habitat is tundra." << endl;
		break;
	case FOREST:
		ofst << "Its natural habitat is forest." << endl;
		break;
	case JUNGLE:
		ofst << "Its natural habitat is jungle." << endl;
		break;
	case FIELD:
		ofst << "Its natural habitat is field." << endl;
		break;
	}

	plant *p = (plant*)b;
	ofst << "Its name has " << consonant(p) << " consonants.\n";
}
void Out(tree* &t, ofstream &ofst)
{
	OutputFileCheck(ofst);
	ofst << "It is a Tree: its name is " << t->name << ", its age is estimated to be " << t->age << " years." << endl;

	switch(t->habitat)
	{
	case DESERT:
		ofst << "Its natural habitat is desert." << endl;
		break;
	case TUNDRA:
		ofst << "Its natural habitat is tundra." << endl;
		break;
	case FOREST:
		ofst << "Its natural habitat is forest." << endl;
		break;
	case JUNGLE:
		ofst << "Its natural habitat is jungle." << endl;
		break;
	case FIELD:
		ofst << "Its natural habitat is field." << endl;
		break;
	}
	plant *p = (plant*)t;
	ofst << "Its name has " << consonant(p) << " consonants.\n";
}
void Out(flower* &f, ofstream &ofst)
{
	OutputFileCheck(ofst);
	ofst << "It is a Flower: its name is " << f->name << ". ";
	switch(f->type)
	{
	case flower::GARDEN:
		ofst << "It's a garden flower." << endl;
		break;
	case flower::DOMESTIC:
		ofst << "It's a domestic flower." << endl;
		break;
	case flower::WILD:
		ofst << "It's a wild flower." << endl;
		break;
	case flower::BED:
		ofst << "It's from a flower-bed." << endl;
		break;
	}
	
	switch(f->habitat)
	{
	case DESERT:
		ofst << "Its natural habitat is desert." << endl;
		break;
	case TUNDRA:
		ofst << "Its natural habitat is tundra." << endl;
		break;
	case FOREST:
		ofst << "Its natural habitat is forest." << endl;
		break;
	case JUNGLE:
		ofst << "Its natural habitat is jungle." << endl;
		break;
	case FIELD:
		ofst << "Its natural habitat is field." << endl;
		break;
	}
	plant *p = (plant*)f;
	ofst << "Its name has " << consonant(p) << " consonants.\n";
}
void Out(plant* &p, ofstream &ofst)
{
	OutputFileCheck(ofst);
	tree* t;
	bush* b;
	flower* f;
	switch(p->k)
	{
	case TREE:
		t = (tree*)p;
		Out(t,ofst);
		break;
	case BUSH:
		b = (bush*)p;
		Out(b,ofst);
		break;
	case FLOWER:
		f = (flower*)p;
		Out(f,ofst);
		break;
	default:
		ofst << "Incorrect plant!" << endl;
	}
}
void OutFirstOnly(container* &c, ofstream &ofst)
{
	OutputFileCheck(ofst);
	container* cur = c;
	int counter = 0;
	while(cur->pl != NULL)
	{
		plant* p = cur->pl;
		cur = cur->next;
		if(p->k != 0)
			continue;
		ofst << ++counter << ": ";
		Out(p, ofst);
	}
}
void Sort(container* &c)
{
	container* start = c;
	for(int i = 0; i < start->len; ++i)
	{
		bool changed = false;
		container* cur = start;
		while(cur->next->pl != NULL)
		{
			int i1 = cur->pl->habitat;
			int i2 = cur->next->pl->habitat;
			if(i1 > i2)
			{
				plant* buf;
				buf = cur->pl;
				cur->pl = cur->next->pl;
				cur->next->pl = buf;
				changed = true;
			}
			cur=cur->next;
		}
		if(!changed)
			break;
	}
}
int consonant(plant* &p)
{
	int res = 0;
	string cur = p->name;
	string alphabet = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
	for(int i = 0; i < alphabet.length(); ++i)
	{
		int c = count(cur.begin(),cur.end(), alphabet[i]);
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