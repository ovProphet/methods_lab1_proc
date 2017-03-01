#include <iostream>
#include <fstream>
#include "declarations.h"
using namespace std;

struct container;
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
	
	while(cur->pl != NULL)
	{
		prev = cur;
		cur = cur->next;
		delete prev;
	}

	delete cur;
	c = new container;
	c->next = NULL;
	c->pl = NULL;
	c->len = 0;
}
void In(container* &c, ifstream &ifst)
{
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
	ifst >> t->name >> t->age;
}
void In(bush* &b, ifstream &ifst)
{
	int mon;
	ifst >> b->name >> mon;
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
}
plant* In(ifstream &ifst)
{
	plant *pl;
	tree* t;
	bush* b;
	int k;
	ifst >> k;
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
	default:
		return 0;
	}
}
void Out(bush* &b, ofstream &ofst)
{
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
	plant *p = (plant*)b;
	ofst << "Its name has " << consonant(p,ofst) << " consonants.\n";
}
void Out(tree* &t, ofstream &ofst)
{
	ofst << "It is a Tree: its name is " << t->name << ", its age is estimated to be " << t->age << " years." << endl;
	plant *p = (plant*)t;
	ofst << "Its name has " << consonant(p,ofst) << " consonants.\n";
}
void Out(plant* &p, ofstream &ofst)
{
	tree* t;
	bush* b;
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
	default:
		ofst << "Incorrect plant!" << endl;
	}
}
int consonant(plant* &p, ofstream &ofst)
{
	int res = 0;
	string cur = p->name;
	string alphabet = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
	for(int i = 0; i < alphabet.length(); ++i)
	{
		int c = count(cur.begin(),cur.end(), alphabet[i]);
		if (c > 0)
			res += c;
	}
	return res;
}