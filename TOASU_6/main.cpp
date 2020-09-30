#include <iostream>
#include <fstream>
#include <cstring>
#define co 2
using namespace std;
int P;
int min(int *S,int *X,int m) {
	int result =500;
	for (int i = 0; i < m; i++) {
		if (S[i] < result)  {result = S[i],P=X[i];} 
	}
	for (int i = 0; i < m; i++) S[i] = 0,X[i]=0;
	return result;
}
int main() {
	setlocale(LC_ALL, "Rus");
	int coef[2];
//	ifstream in("C:\\Users\\gieko\\Documents\\DevProjects\\TOASU_6\\f.txt");
	ifstream in("C:\\Users\\gieko\\Documents\\DevProjects\\TOASU_6\\f0.txt");
	if (in.is_open()) {
		int m;
		in >> m;
		int **Table = new int *[m];
		int **Res = new int *[co];
		int **Xi=new int *[co];
		//create array Table
		for (int i = 0; i <= m; i++) {
			Table[i] = new int[m];
		}
		//create array Res and Xi
		for (int i = 0; i < m; i++) {
			Res[i] = new int[co];
			Xi[i] = new int[co];
		}

		//read in file from array Table
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				in >> Table[i][j];
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				cout << Table[i][j]<<"\t";
			}
			cout<<endl;
		}
		cout<<endl;
		in.close();
		
	}
	else {
		cout << "Not true way to file..";
	}
}
