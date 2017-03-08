#include <iostream>
#include <fstream>
#include <string>

using namespace std;
enum key{TREE,BUSH};
enum hab{FOREST,FIELD,DESERT,TUNDRA,JUNGLE};

struct plant
{
	key k;
	string name;
	hab habitat;
};
struct tree
{
	key k;
	string name;
	hab habitat;
	long long age;
};
struct bush
{
	key k;
	string name;
	hab habitat;
	enum month {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
	month blooming;
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
void In(bush* &b, ifstream &ifst);
plant* In(ifstream &ifst);
void Out(bush* &b, ofstream &ofst);
void Out(tree* &t, ofstream &ofst);
void Out(plant* &p, ofstream &ofst);
void OutFirstOnly(container* &p, ofstream &ofst);
void Sort(container* &c);
