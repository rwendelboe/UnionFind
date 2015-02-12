#ifndef UNIONFIND_H
#define UNIONFIND_H
#include <iostream>
#include <vector>
using namespace std;

class UnionFind{
private:
	
public:
	UnionFind(int sizeOfArray);
	int * arrayInitial;
	int * notIn;
	void different(int a, int b);
	bool unionR(int a, int b);
	int find(int a);
	void ask(int a, int b);

};
#endif