#include <iostream>
#include <fstream>
#include <string>

using namespace std;
enum key{TREE,BUSH,FLOWER};
struct plant
{
	key k;
	string name;
};
struct tree
{
	key k;
	string name;
	long long age;
};
struct bush
{
	key k;
	string name;
	enum month {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
	month blooming;
};
struct flower
{
	key k;
	string name;
	enum habitat{DOMESTIC, WILD, GARDEN, BED};
	habitat type;
};
struct container
{
	container *next;
	plant *pl;
	int len;
};

void Init(container* &c);
void Clear(container* &c);
void In(container* &c, ifstream &ifst);
void Out(container* &c, ofstream &ofst);
void In(tree* &t, ifstream &ifst);
void In(flower* &f, ifstream &ifst);
void In(bush* &b, ifstream &ifst);
plant* In(ifstream &ifst);
void Out(bush* &b, ofstream &ofst);
void Out(tree* &t, ofstream &ofst);
void Out(flower* &f, ofstream &ofst);
void Out(plant* &p, ofstream &ofst);