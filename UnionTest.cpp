#include <iostream>
#include <fstream>
#include "UnionFind.h"

using namespace std;

int main(){
	ifstream file;
	
	int numOfTests;
	int numOfTestLines;
	int sizeOfArray;
	int count = 0;
	char AorD;
	int a;
	int b;

	file.open("highschool.txt");
	file >> numOfTests;
	
	for (int i = 0; i < numOfTests; ++i){
		cout << "Test " << i + 1<< endl;
		file >> sizeOfArray;
		file >> numOfTestLines;
		UnionFind practice(sizeOfArray);
		for (int j = 0; j < numOfTestLines; ++j){
			int * testArray = new int[sizeOfArray];
			file >> AorD;
			if (AorD == 'A'){
				file >> a;
				file >> b;
				practice.ask(a, b);
			}
			if (AorD == 'D'){
				file >> a;
				file >> b;
				practice.different(a, b);
			}
		}
		cout << endl;
	}
	//un-comment to see visual arrays and to do path comression if wasnt done before in the test.
		/*practice.find(6);
		for (int i = 0; i < sizeOfArray; i++)
		{
			cout << practice.arrayInitial[i] << " ";

		}
		cout << endl;
		for (int i = 0; i < sizeOfArray; i++)
		{
			cout << practice.notIn[i] << " ";

		}
		cout << endl;
	*/
	file.close();
	cin.get();
	return 0;
}
