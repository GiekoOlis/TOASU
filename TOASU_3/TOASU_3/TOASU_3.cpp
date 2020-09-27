
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int P;
int max(int *S,int *W, int k) {
	int result = 0;
	for (int i = 0; i < k; i++) {
		if (S[i] > result)  result = S[i], P = W[i];
		
	}
	for (int i = 0; i < k; i++) S[i] = 0,W[i]=0;
	return result;
}
int main(){
	setlocale(LC_ALL, "Rus");
	int coef[3];
	//ifstream in("C:\\Users\\gieko\\source\\repos\\TOASU_3\\TOASU_3\\f.txt"); //homework
	ifstream in("C:\\Users\\gieko\\source\\repos\\TOASU_3\\TOASU_3\\f0.txt"); //classwork
	if (in.is_open()) {
		for (int i = 0; i < 3; i++) in >> coef[i];
		int n = coef[0];//number line F_x and column S_y
		int m = coef[1];//number column F_x
		int k = coef[2];//nnumber line S_y (Y - budget)
		int **F_x = new int *[n];
		int **S_y = new int *[k];
		int **Ways = new int *[k];
		//create array F_x
		for (int i = 0; i < n; i++) {
			F_x[i] = new int[m];
		}
		//read in file from array F_x
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				in >> F_x[i][j];
			}
		}
		//viev from file to console
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout <<F_x[i][j] << "\t";
			cout << endl;
		}
		//create array S_y and Ways
		for (int i = 0; i < k; i++) {
			S_y[i] = new int[n];
			Ways[i] = new int[n];
		}
		int tmax=0;//intermediate result 


		int *S = new int[k-1];//array for intermediate result 
		int *W = new int[k - 1];
		memset(S, 0, sizeof(S));
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < k; i++) {
				if (i != 0) {
					if (j != 0) {
						for (int x = 0; x <= i;x++) {
							if (x >= m) S[x] = 0;
							else S[x] = S_y[i - x][j - 1] + F_x[j][x], W[x]=x;
						}
						S_y[i][j] = max(S, W, k);
						Ways[i][j] = P;
					}
					else {
						if(i<4)
						S_y[i][j]=F_x[0][i], Ways[i][j] = i;
						else S_y[i][j] = F_x[0][n], Ways[i][j] = n;
					}
				}
				else S_y[i][j]= 0, Ways[i][j]=0;
			}
		}
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < n; j++) {
				cout << S_y[i][j]<<"/"<<Ways[i][j] << "\t\t";
			}
			cout << endl;
		}
		int rr = k-1;
		int *o = new int[n];
		for (int i = n - 1; i >=0; i--) {
			o[i] = Ways[rr][i];
			rr = rr - Ways[rr][i];
		}
		cout << "one option of the optimal production: X*( " <<o[0]<< ", "<<o[1]<< ", " << o[2]<< ", " << o[3]<<")" << endl;
		cout << "Check: " << F_x[0][o[0]] << " + " << F_x[1][o[1]] << " + " << F_x[2][o[2]] << " + " << F_x[3][o[3]]<< " = " << F_x[0][o[0]]+F_x[1][o[1]]+F_x[2][o[2]]+F_x[3][o[3]] << endl;
		//clear cash
		for (int i = 0; i < n; i++) delete[] F_x[i];
		delete[] F_x;
		in.close();
	}
	else {
		cout << "Not true way to file..";
	}
}

