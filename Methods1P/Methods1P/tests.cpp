#include <iostream>
#include <fstream>
#include "declarations.h"
#include "gtest/gtest.h"
using namespace std;
struct container;

TEST(init_container,empty_container)
{
	container* c = NULL;
	Init(c);
	EXPECT_EQ(c->len,0);
	EXPECT_TRUE(c->pl == NULL);
	EXPECT_TRUE(c->next == NULL);
}
TEST(init_container,nonempty_container)
{
	container* c = NULL;
	c = new container;
	c->len = 54;
	c->next = new container;
	c->pl = new plant;
	Init(c);
	EXPECT_EQ(c->len,0);
	EXPECT_TRUE(c->pl == NULL);
	EXPECT_TRUE(c->next == NULL);
}
TEST(clear_container,empty_container)
{
	container* c = NULL;
	Clear(c);
	EXPECT_EQ(c->len,0);
	EXPECT_TRUE(c->pl == NULL);
	EXPECT_TRUE(c->next == NULL);
}
TEST(clear_container,nonempty_container)
{
	container* c = NULL;
	c = new container;
	c->len = 3;
	c->pl = new plant;
	c->next = new container;
	c->next->pl = new plant;
	c->next->next = new container;
	c->next->next->pl = new plant;
	c->next->next->next = new container;
	c->next->next->next->next = NULL;
	c->next->next->next->pl = NULL;
	Clear(c);
	EXPECT_EQ(c->len,0);
	EXPECT_TRUE(c->pl == NULL);
	EXPECT_TRUE(c->next == NULL);
}
TEST(sort_container, reverse_container)
{
	ifstream ifst("sort_reverse.txt");
	container* c,*first;
	Init(c);
	first=c;
	In(c,ifst);
	Sort(c);
	EXPECT_TRUE(c->pl->name == "tewte" || c->pl->name == "Toomoo");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "tewte" || c->pl->name == "Toomoo");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "OOOOO)))" || c->pl->name == "Nyeea");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "OOOOO)))" || c->pl->name == "Nyeea");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "Toomoonyee" || c->pl->name == "Vasily");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "Toomoonyee" || c->pl->name == "Vasily");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "Sookomoo" || c->pl->name == "Flower3");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "Sookomoo" || c->pl->name == "Flower3");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "Za-Bor" || c->pl->name == "BushNumba4");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "Za-Bor" || c->pl->name == "BushNumba4");
	c = c->next;
	EXPECT_TRUE(c->pl == NULL);
	Clear(first);
}
TEST(sort_container, sorted_container)
{
	ifstream ifst("sorted.txt");
	container* c,*first;
	Init(c);
	first=c;
	In(c,ifst);
	Sort(c);
	EXPECT_TRUE(c->pl->name == "tewte" || c->pl->name == "Toomoo");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "tewte" || c->pl->name == "Toomoo");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "OOOOO)))" || c->pl->name == "Nyeea");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "OOOOO)))" || c->pl->name == "Nyeea");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "Toomoonyee" || c->pl->name == "Vasily");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "Toomoonyee" || c->pl->name == "Vasily");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "Sookomoo" || c->pl->name == "Flower3");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "Sookomoo" || c->pl->name == "Flower3");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "Za-Bor" || c->pl->name == "BushNumba4");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "Za-Bor" || c->pl->name == "BushNumba4");
	c = c->next;
	EXPECT_TRUE(c->pl == NULL);
	Clear(first);
}
TEST(sort_container, one_element_container)
{
	ifstream ifst("one_sort.txt");
	container* c,*first;
	Init(c);
	first=c;
	In(c,ifst);
	Sort(c);
	EXPECT_TRUE(c->pl->name == "tewte" || c->pl->name == "Toomoo");
	c = c->next;
	EXPECT_TRUE(c->pl == NULL);
	Clear(first);
}
TEST(sort_container, empty_container)
{
	container* c,*first;
	Init(c);
	first=c;
	Sort(c);
	EXPECT_TRUE(c->pl == NULL);
	Clear(first);
}
TEST(consonant,no_consonants)
{
	ofstream ofst("trash.txt");
	plant* p = new plant;
	p->habitat = TUNDRA;
	p->k = TREE;
	p->name = "AAAaAAoIOEEEEUOuioeoa";
	EXPECT_EQ(consonant(p,ofst),0);
}
TEST(consonant,all_consonants)
{
	ofstream ofst("trash.txt");
	plant* p = new plant;
	p->habitat = TUNDRA;
	p->k = TREE;
	p->name = "QWRTPSDFGHJKLZXCVBNMqwrtpsdfghjklzxcvbnm";
	EXPECT_EQ(consonant(p,ofst),40);
}
TEST(consonant,empty_string)
{
	ofstream ofst("trash.txt");
	plant* p = new plant;
	p->habitat = TUNDRA;
	p->k = TREE;
	p->name = "";
	EXPECT_EQ(consonant(p,ofst),0);
}
TEST(consonant,orchid)
{
	ofstream ofst("trash.txt");
	plant* p = new plant;
	p->habitat = FOREST;
	p->k = FLOWER;
	p->name = "Orchidaceae";
	EXPECT_EQ(consonant(p,ofst),5);
}
TEST(plant_in,all_at_once)
{
	ifstream ifst("all_types.txt");
	plant* p;
	p = In(ifst);
	EXPECT_TRUE(p->habitat == FOREST);
	EXPECT_TRUE(p->name == "Toomoo");
	EXPECT_TRUE(p->k == BUSH);
	p = In(ifst);
	EXPECT_TRUE(p->habitat == FOREST);
	EXPECT_TRUE(p->name == "tewte");
	EXPECT_TRUE(p->k == FLOWER);
	p = In(ifst);
	EXPECT_TRUE(p->habitat == JUNGLE);
	EXPECT_TRUE(p->name == "Za-Bor");
	EXPECT_TRUE(p->k == TREE);
}
TEST(output_container,empty)
{
	ofstream ofst("trash.txt");
	container* c,*first;
	Init(c);
	Out(c,ofst);
	Clear(c);
}
TEST(output_container,nonempty)
{
	ofstream ofst("trash.txt");
	container* c,*first;
	Init(c);
	In(c,ifstream("sorted.txt"));
	Out(c,ofst);
	Clear(c);
}
TEST(input_container,all_at_once)
{
	container* c, *first;
	Init(c);
	first = c;
	In(c,ifstream("sorted.txt"));
	EXPECT_EQ(c->len,10);
	EXPECT_TRUE(c->pl->name == "Toomoo");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "tewte");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "Nyeea");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "OOOOO)))");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "Toomoonyee");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "Vasily");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "Flower3");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "Sookomoo");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "BushNumba4");
	c = c->next;
	EXPECT_TRUE(c->pl->name == "Za-Bor");
	c = c->next;
	EXPECT_TRUE(c->pl == NULL);
	Clear(first);
}
TEST(input_container,empty)
{
	container* c;
	Init(c);
	In(c,ifstream("empty.txt"));
	EXPECT_EQ(c->len,0);
	EXPECT_TRUE(c->pl==NULL);
	EXPECT_TRUE(c->next==NULL);
}
TEST(input_tree,all_at_once)
{
	ifstream ifst("trees.txt");
	tree* tr = new tree;
	In(tr, ifst);
	EXPECT_TRUE(tr->age == 2000000000000000);
	EXPECT_TRUE(tr->name == "Gnav-ov-Stryka");
	EXPECT_TRUE(tr->habitat == FOREST);
	In(tr, ifst);
	EXPECT_TRUE(tr->age == 55555);
	EXPECT_TRUE(tr->name == "Kyr-Lun-Borgor");
	EXPECT_TRUE(tr->habitat == FIELD);
	In(tr, ifst);
	EXPECT_TRUE(tr->age == 55555);
	EXPECT_TRUE(tr->name == "Kyr-Lun-Borgor");
	EXPECT_TRUE(tr->habitat == DESERT);
	In(tr, ifst);
	EXPECT_TRUE(tr->age == 55555);
	EXPECT_TRUE(tr->name == "Kyr-Lun-Borgor");
	EXPECT_TRUE(tr->habitat == TUNDRA);
	In(tr, ifst);
	EXPECT_TRUE(tr->age == 1337);
	EXPECT_TRUE(tr->name == "Za-Bor");
	EXPECT_TRUE(tr->habitat == JUNGLE);
}
TEST(input_bush,all_at_once)
{
	ifstream ifst("bushes.txt");
	bush* tr = new bush;
	In(tr, ifst);
	EXPECT_TRUE(tr->blooming == bush::MAY);
	EXPECT_TRUE(tr->name == "Poomoo");
	EXPECT_TRUE(tr->habitat == FOREST);
	In(tr, ifst);
	EXPECT_TRUE(tr->blooming == bush::JAN);
	EXPECT_TRUE(tr->name == "Nyeea");
	EXPECT_TRUE(tr->habitat == FIELD);
	In(tr, ifst);
	EXPECT_TRUE(tr->blooming == bush::FEB);
	EXPECT_TRUE(tr->name == "Hoozooa");
	EXPECT_TRUE(tr->habitat == DESERT);
	In(tr, ifst);
	EXPECT_TRUE(tr->blooming == bush::MAR);
	EXPECT_TRUE(tr->name == "Shoom");
	EXPECT_TRUE(tr->habitat == TUNDRA);
	In(tr, ifst);
	EXPECT_TRUE(tr->blooming == bush::APR);
	EXPECT_TRUE(tr->name == "BushNumba4");
	EXPECT_TRUE(tr->habitat == JUNGLE);
	In(tr, ifst);
	EXPECT_TRUE(tr->blooming == bush::JUN);
	EXPECT_TRUE(tr->name == "BushNumba4");
	EXPECT_TRUE(tr->habitat == JUNGLE);
	In(tr, ifst);
	EXPECT_TRUE(tr->blooming == bush::JUL);
	EXPECT_TRUE(tr->name == "BushNumba4");
	EXPECT_TRUE(tr->habitat == JUNGLE);
	In(tr, ifst);
	EXPECT_TRUE(tr->blooming == bush::AUG);
	EXPECT_TRUE(tr->name == "BushNumba4");
	EXPECT_TRUE(tr->habitat == JUNGLE);
	In(tr, ifst);
	EXPECT_TRUE(tr->blooming == bush::SEP);
	EXPECT_TRUE(tr->name == "BushNumba4");
	EXPECT_TRUE(tr->habitat == JUNGLE);
	In(tr, ifst);
	EXPECT_TRUE(tr->blooming == bush::OCT);
	EXPECT_TRUE(tr->name == "BushNumba4");
	EXPECT_TRUE(tr->habitat == JUNGLE);
	In(tr, ifst);
	EXPECT_TRUE(tr->blooming == bush::NOV);
	EXPECT_TRUE(tr->name == "BushNumba4");
	EXPECT_TRUE(tr->habitat == JUNGLE);
	In(tr, ifst);
	EXPECT_TRUE(tr->blooming == bush::DEC);
	EXPECT_TRUE(tr->name == "BushNumba4");
	EXPECT_TRUE(tr->habitat == JUNGLE);
}
TEST(input_flower,all_at_once)
{
	ifstream ifst("flowers.txt");
	flower* tr = new flower;
	In(tr, ifst);
	EXPECT_TRUE(tr->type == flower::WILD);
	EXPECT_TRUE(tr->name == "tewte");
	EXPECT_TRUE(tr->habitat == FOREST);
	In(tr, ifst);
	EXPECT_TRUE(tr->type == flower::DOMESTIC);
	EXPECT_TRUE(tr->name == "Flower1");
	EXPECT_TRUE(tr->habitat == FIELD);
	In(tr, ifst);
	EXPECT_TRUE(tr->type == flower::GARDEN);
	EXPECT_TRUE(tr->name == "Flower2");
	EXPECT_TRUE(tr->habitat == DESERT);
	In(tr, ifst);
	EXPECT_TRUE(tr->type == flower::BED);
	EXPECT_TRUE(tr->name == "Flower3");
	EXPECT_TRUE(tr->habitat == TUNDRA);
	In(tr, ifst);
	EXPECT_TRUE(tr->type == flower::BED);
	EXPECT_TRUE(tr->name == "Flower3");
	EXPECT_TRUE(tr->habitat == JUNGLE);
}
TEST(output_bush,all_at_once)
{
	bush* b = new bush;
	b->k = BUSH;
	b->name = "name";
	b->habitat = FOREST;
	b->blooming = bush::JAN;
	Out(b,ofstream("trash.txt"));
	b->habitat = FIELD;
	b->blooming = bush::FEB;
	Out(b,ofstream("trash.txt"));
	b->habitat = DESERT;
	b->blooming = bush::MAR;
	Out(b,ofstream("trash.txt"));
	b->habitat = TUNDRA;
	b->blooming = bush::APR;
	Out(b,ofstream("trash.txt"));
	b->habitat = JUNGLE;
	b->blooming = bush::MAY;
	Out(b,ofstream("trash.txt"));
	b->blooming = bush::JUN;
	Out(b,ofstream("trash.txt"));
	b->blooming = bush::JUL;
	Out(b,ofstream("trash.txt"));
	b->blooming = bush::AUG;
	Out(b,ofstream("trash.txt"));
	b->blooming = bush::SEP;
	Out(b,ofstream("trash.txt"));
	b->blooming = bush::OCT;
	Out(b,ofstream("trash.txt"));
	b->blooming = bush::NOV;
	Out(b,ofstream("trash.txt"));
	b->blooming = bush::DEC;
	Out(b,ofstream("trash.txt"));
}
TEST(output_tree,all_at_once)
{
	tree* b = new tree;
	b->k = TREE;
	b->name = "name";
	b->age = 500000;
	b->habitat = FOREST;
	Out(b,ofstream("trash.txt"));
	b->habitat = FIELD;
	Out(b,ofstream("trash.txt"));
	b->habitat = DESERT;
	Out(b,ofstream("trash.txt"));
	b->habitat = TUNDRA;
	Out(b,ofstream("trash.txt"));
	b->habitat = JUNGLE;
	Out(b,ofstream("trash.txt"));
}
TEST(output_flower,all_at_once)
{
	flower* b = new flower;
	b->k = FLOWER;
	b->name = "name";
	b->type = flower::BED;
	b->habitat = FOREST;
	Out(b,ofstream("trash.txt"));
	b->type = flower::GARDEN;
	b->habitat = FIELD;
	Out(b,ofstream("trash.txt"));
	b->type = flower::DOMESTIC;
	b->habitat = DESERT;
	Out(b,ofstream("trash.txt"));
	b->type = flower::WILD;
	b->habitat = TUNDRA;
	Out(b,ofstream("trash.txt"));
	b->habitat = JUNGLE;
	Out(b,ofstream("trash.txt"));
}
TEST(output_plant,all_at_once)
{
	plant* pl;
	ifstream ifst("sort_reverse.txt");
	pl = In(ifst);
	Out(pl,ofstream("trash.txt"));
	pl = In(ifst);
	Out(pl,ofstream("trash.txt"));
	pl = In(ifst);
	Out(pl,ofstream("trash.txt"));
}
TEST(output_trees_only,no_trees)
{
	container* c;
	Init(c);
	In(c,ifstream("no_trees.txt"));
	OutFirstOnly(c,ofstream("trash.txt"));
}
TEST(output_trees_only,all_trees)
{
	container* c;
	Init(c);
	In(c,ifstream("all_trees.txt"));
	OutFirstOnly(c,ofstream("trash.txt"));
}
TEST(output_trees_only,empty_container)
{
	container* c;
	Init(c);
	In(c,ifstream("empty.txt"));
	OutFirstOnly(c,ofstream("trash.txt"));
}
TEST(output_trees_only,mixed)
{
	container* c;
	Init(c);
	In(c,ifstream("in.txt"));
	OutFirstOnly(c,ofstream("trash.txt"));
}
/*
TODO:
+ void Init(container* &c);
+ void Clear(container* &c);
+ void In(container* &c, ifstream &ifst);
+ void Out(container* &c, ofstream &ofst);
+ void In(tree* &t, ifstream &ifst);
+ void In(flower* &f, ifstream &ifst);
+ void In(bush* &b, ifstream &ifst);
+ plant* In(ifstream &ifst);
+ void Out(bush* &b, ofstream &ofst);
+ void Out(tree* &t, ofstream &ofst);
+ void Out(flower* &f, ofstream &ofst);
+ void Out(plant* &p, ofstream &ofst);
+ void OutFirstOnly(container* &p, ofstream &ofst);
+ void Sort(container* &c);
+ int consonant(plant* &p, ofstream &ofst);

*/
int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::getchar();
	return 0;
}