#include <iostream>
#include <fstream>
#include <cstring>
#define co 2
using namespace std;
int P;
int max(int *S,int *X,int m) {
	int result = -1;
	for (int i = 0; i < m; i++) {
		if (S[i] > result)  result = S[i],P=X[i];
		
	}
	for (int i = 0; i < m; i++) S[i] = 0,X[i]=0;
	return result;
}
int main() {
	setlocale(LC_ALL, "Rus");
	int coef[2];
	ifstream in("C:\\Users\\gieko\\source\\repos\\TOASU_4\\TOASU_4\\f.txt");
	if (in.is_open()) {
		for (int i = 0; i < 2; i++) in >> coef[i];
		int L = coef[0];//L - razmer rukzaka
		int m = coef[1];// kolvo dostupnih predmetov
		int **D = new int *[co];
		int **Res = new int *[L+1];
		int **Xi=new int *[L+1];
		//create array D
		for (int i = 0; i <= m; i++) {
			D[i] = new int[co];
		}
		//create array Res and Xi
		for (int i = 0; i <= m; i++) {
			Res[i] = new int[L+1];
			Xi[i] = new int[L+1];
		}

		//read in file from array D
		D[0][0] = 0; D[0][1] = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j < 2; j++) {
				in >> D[i][j];
			}
		}
		in.close();
		
		int tmax=0;//intermediate result
		int *S = new int[L+1];//array for intermediate result 
		int *X = new int[L+1];
		memset(S, 0, sizeof(S));
		memset(X, 0, sizeof(X));
		cout <<"i \t c \t w"<<endl;
		for (int i = 0; i <= m; i++) {
		cout <<i<<"\t"; 
			for (int j = 0; j < 2; j++) {
				cout << D[i][j] << "\t";
			}
			cout << endl;
		}
		
		for(int i=0;i<=m;i++){
			for(int j=0;j<=L;j++){
				if((i!=0)&&(j!=0)){	
						for(int x=0;x<=(j/D[i][1]);x++){
							S[x]=Res[i-1][j-x*D[i][1]]+x*D[i][0], X[x]=x;
							
						}
						Res[i][j]=max(S,X,m), Xi[i][j]=P;
						if((i==1)&&(j==1)) Res[i][j]=0,Xi[i][j]=0;
				}
				else Res[i][j]=0,Xi[i][j]=0;
			}
		}
		for (int i=0;i<=m;i++){
			for(int j=0;j<=L;j++){
				cout <<	Res[i][j] <<"/"<<Xi[i][j]<< "   ";
			}
			cout << endl;
		}
		
		int rr = L;
		int *o = new int[m];
		for (int i = m; i >=0; i--) {
			o[i] = Xi[i][rr];
			rr = rr - Xi[i][rr]*D[i][1];
		}
		cout << "one option of the optimal production: X*( " <<o[0]<< ", "<<o[1]<< ", " << o[2]<< ", " << o[3]<<", " <<o[4]<<", " <<o[5]<<")" << endl;
		cout << "Check: " << D[0][0]*o[0] << " + " << D[1][0]*o[1] << " + " << D[2][0]*o[2] << " + " << D[3][0]*o[3]<<" + " << D[4][0]*o[4]<<" + " << D[5][0]*o[5]<< " = " << D[0][0]*o[0]+D[1][0]*o[1]+D[2][0]*o[2]+D[3][0]*o[3]+D[4][0]*o[4]+D[5][0]*o[5];

	}

	else {
		cout << "Not true way to file..";
	}

}
