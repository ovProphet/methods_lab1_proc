#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
enum hab{FOREST,FIELD,DESERT,TUNDRA,JUNGLE};
enum key{TREE,BUSH,FLOWER};
/*(1)*/
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
	/*month m;
	//It's better to replace that enum in string (1)*/
	month blooming;
};
struct flower
{
	key k;
	string name;
	hab habitat;
	enum habitat1{DOMESTIC, WILD, GARDEN, BED};
	/*habitat1 h;
	//It's better to replace that enum in string after (1)*/
	habitat1 type;
};
/*struct node
{
	plant *pl;
	node *next;
}
struct container
{
	node *cont;
	int len;
}*/
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
void OutFirstOnly(container* &p, ofstream &ofst);
void Sort(container* &c);
int consonant(plant* &p, ofstream &ofst);
