
#include <iostream>
#include <fstream>
using namespace std; 
int main()
{
	//setlocale(LC_ALL, "Rus");
	int coef[2];
	ifstream in("C:\\Users\\gieko\\source\\repos\\TOASU4_NEW\\TOASU4_NEW\\f.txt");
	if (in.is_open()) {
		for (int i = 0; i < 2; i++) in >> coef[i];
		int L = coef[0] ;//L - размер рюкзака
		int m = coef[1] + 1;// kolvo dostupnih predmetov
		//int k = coef[2];//nnumber line S_y (Y - budget)
		int** D = new int* [2];
		int** Res = new int* [L + 1];
		//create array D
		for (int i = 0; i <= m; i++) {
			D[i] = new int[2];
		}
		//create array Res
		for (int i = 0; i <= m; i++) {
			Res[i] = new int[L+1];
		}
		//read in file from array D
		
		for (int i = 1; i < m; i++) {
			for (int j = 0; j < 2; j++) {
				in >> D[i][j];
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < L; j++) {
				Res[i][j]=0;
			}
		}
		in.close();
	}
	else {
		cout << "Not true way to file..";
	}
}
