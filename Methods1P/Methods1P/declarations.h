#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
enum hab{FOREST, FIELD, DESERT, TUNDRA, JUNGLE};
enum key{TREE, BUSH, FLOWER};
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
struct flower
{
	key k;
	string name;
	hab habitat;
	enum habitat1{DOMESTIC, WILD, GARDEN, BED};
	habitat1 type;
};
struct container
{
	container *next;
	plant *plant;
	int length;
};

void Init(container* &c);
void Clear(container* &c);
void In(container* &c, ifstream &inputFile);
void Out(container* &c, ofstream &outputFile);
void In(tree* &t, ifstream &inputFile);
void In(flower* &f, ifstream &inputFile);
void In(bush* &b, ifstream &inputFile);
plant* In(ifstream &inputFile);
void Out(bush* &b, ofstream &outputFile);
void Out(tree* &t, ofstream &outputFile);
void Out(flower* &f, ofstream &outputFile);
void Out(plant* &p, ofstream &outputFile);
void OutFirstOnly(container* &p, ofstream &outputFile);
void Sort(container* &c);
int Consonant(plant* &p);
