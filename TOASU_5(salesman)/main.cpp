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
//	ifstream in("C:\\Users\\gieko\\Documents\\DevProjects\\TOASU_5\\f.txt");
	ifstream in("C:\\Users\\gieko\\Documents\\DevProjects\\TOASU_5\\f0.txt");
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
			for (int j = 0; j < m+1; j++) {
				Res[0][j]=j;
				Res[1][j]=0;
				Xi[0][j]=j;
				Xi[1][j]=0;
			}
			
		
		
		Res[1][0]=0;Xi[1][0]=0;
		
		int *S = new int[m];//array for intermediate result 
		int *X = new int[m];
		memset(S, 0, sizeof(S));
		memset(X, 0, sizeof(X));
		for(int j=1; j<m+1;j++){
				for(int i=0;i<=j;i++){
					S[i]=Res[1][i]+Table[i][j-1], X[i]=i;
				}
				Res[1][j]=min(S,X,j), Xi[1][j]=P;
				
		}
			cout <<"j\t";
			for(int j=0;j<m+1;j++){
				cout <<	Res[0][j] <<"\t";
			}
			cout << endl;
			cout <<"S(j)/i\t";
			for(int j=0;j<m+1;j++){
				cout <<	Res[1][j] <<"/"<<Xi[1][j]<< "\t";
			}
			cout << endl;	
	}
	else {
		cout << "Not true way to file..";
	}
}
