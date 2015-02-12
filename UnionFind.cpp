#include "UnionFind.h"
#include <assert.h>


UnionFind::UnionFind(int sizeOfArray){
	arrayInitial = new int[sizeOfArray];
	notIn = new int[sizeOfArray];
	for (int i = 0; i < sizeOfArray; ++i){
		arrayInitial[i] = -1;
		notIn[i] = -1;
	}
}

void UnionFind::different(int a, int b){
	
	if (notIn[a] < 0 ){
		notIn[a] = b;
	}
	else{
		if(unionR(b, notIn[a]) == false) return;
		
	}
	if (notIn[b] < 0){
		notIn[b] = a;
	}
	else{
		unionR(a, notIn[b]);
	}
}
bool UnionFind::unionR(int a, int b){
	if (find(a) == find(notIn[b])){
		cout << "Bad Data" << endl;
		return false;
	}
	
	if (arrayInitial[b] > arrayInitial[a]){
		arrayInitial[a] = b;
	}
	else{
		if (arrayInitial[a] == arrayInitial[b]){
			arrayInitial[a]--;
			arrayInitial[b] = a;
		}
		else{
			arrayInitial[b] = a;
		}
	}
	return true;
}

int UnionFind::find(int a){
	//find with path compression
	int returnVal;
	if (arrayInitial[a] >= 0){
		returnVal = find(arrayInitial[a]);
		arrayInitial[a] = returnVal;
	}
	else{
		returnVal = a;
	}
	return returnVal;
}
void UnionFind::ask(int a, int b){
	if (find(a) == find(b)){
		cout << "Person " << a <<" and " << b << ": Went to the same school." << endl;
	}
	else if (find(a) == find(notIn[b])) {
		cout << "Person " << a <<" and " << b << ": In different schools." << endl;
	}
	else{
		cout << "Not sure yet" << endl;
	}
}