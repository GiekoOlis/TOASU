#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

#define inf 100
using namespace std;
struct Edges {
	int u, v, w;
};
const int Vmax = 100;
const int Emax = Vmax * (Vmax - 1) / 2;
int i, j, e;
Edges edge[Emax];
int d[Vmax];


void bellford(int n, int s) {
	int i, j;
	for (i = 0; i < n; i++) d[i] = inf;
	d[s] = 0;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < e; j++)
			if (d[edge[j].v] + edge[j].w < d[edge[j].u])
				d[edge[j].u] = d[edge[j].v] + edge[j].w;

	if (d[n - 1] == inf) {
		cout << "Not" << '\n';
	}
	else {
		cout << " " << d[n - 1];
	}
}


int graph() {
	int schet = 0;
	ifstream file("C:\\Users\\gieko\\source\\repos\\TOASU_1\\TOASU_1\\f.txt");
	if (file.is_open()) {
		string str;
		while (!file.eof()) {
			getline(file, str);
			schet++;
		}
		file.close();
	}
	else {
		cout << "Error";
	}
	return schet;
}
int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Rus");
	ifstream in("C:\\Users\\gieko\\source\\repos\\TOASU_1\\TOASU_1\\f.txt");
	if (in.is_open()) {
		int n = graph();
		int m = graph();
		int **MatringSize = new int *[n];
		//create array
		for (int i = 0; i < n; i++) {
			MatringSize[i] = new int[m];
		}
		//read in file from array
		for (int i=0; i < n; i++) {
			for (int j=0; j < m; j++) {
				in >> MatringSize[i][j];
			}
		}
		//viev from file to console
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << MatringSize[i][j] << "\t";
			cout << endl;
		}
		//structure 
		e = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (MatringSize[i][j] != 0) {
					edge[e].v = i;
					edge[e].u = j;
					edge[e].w = MatringSize[i][j];
					e++;
				}
			}
		cout << "Must shooter way: ";
		bellford(n, 0);
		//clear cash
		for (int i = 0; i < n; i++) delete[] MatringSize[i];
		delete[] MatringSize;
		in.close();
	}
	else {
		cout << "Not true way to file..";
	}
	return 0;
}

