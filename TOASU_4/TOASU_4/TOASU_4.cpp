/*#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
//#include <ocale.h>

int limW = 20; // предельный вес выбранных предметов
enum { N = 10 }; // количество предметов

typedef struct {
	int weight; //// вес предметов
	int value; //// ценность предметов
} object;

// Формирование структурного типа с параметрами модели
object obj[] = { 10,18, 11,20, 12,17, 13,19, 14,25, 15,21, 16,27, 17,23, 18,25, 19,24 };

int maxv; // для инициализации стоимости предметов

// Рекурсивная функция
int TRY(int i, int tw, int av) {
	// Попытка включения предмета
	if (tw + obj[i].weight <= limW)
		if (i < N - 1)
			TRY(i + 1, tw + obj[i].weight, av);

		else if (av > maxv)
			maxv = av;
	// Попытка исключения предмета
	if (av > maxv + obj[i].value)
		if (i < N - 1)
			TRY(i + 1, tw, av - obj[i].value);
		else
			maxv = av - obj[i].value;
	return maxv;
}

// Главная функция программы
int main(void) {
	int i, price;
	int sumw = 0;
	int sumv = 0;
	setlocale(LC_ALL, "rus");

	maxv = obj[0].value; // инициализации стоимости предметов
	puts("\n\t\t\tЗАДАЧА О РЮКЗАКЕ");
	puts("\t\t  Характеристика предметов");
	for (i = 0; i < (4 * N + 12); i++)
		printf("%s", "_");

	printf("\n\n %12s", "Вес:");
	for (i = 0; i < N; i++) {
		sumw += obj[i].weight;
		printf(" %3d", obj[i].weight);
	}

	printf("\n %12s", "Стоимость:");
	for (i = 0; i < N; i++) {
		sumv += obj[i].value;
		printf(" %3d", obj[i].value);
	}
	printf("\n ");
	for (i = 0; i < (4 * N + 12); i++)
		printf("%s", "_");

	printf("\n\n %32s: %d\n", "Общий вес всех предметов", sumw);
	printf(" %32s: %d\n", "Общая стоимость всех предметов", sumv);
	printf(" %32s: %d\n ", "Допустимый вес рюкзака", limW);
	for (i = 0; i < (4 * N + 12); i++)
		printf("%s", "_");
	// Вызов рекурсивной функции с начальными параметрами
	price = TRY(0, 0, sumv);
	printf("\n\n  Стоимость выбранных предметов: %d\n ", price);
	for (i = 0; i < (4 * N + 12); i++)
		printf("%s", "_");

	printf("\n\n ... Нажмите любую клавишу: ");
	return 0;
} */

/*
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int P;
int max(int *S, int *W, int k) {
	int result = 0;
	for (int i = 0; i < k; i++) {
		if (S[i] > result)  result = S[i], P = W[i];

	}
	for (int i = 0; i < k; i++) S[i] = 0, W[i] = 0;
	return result;
}
int main() {
	setlocale(LC_ALL, "Rus");
	int coef[2];
	ifstream in("C:\\Users\\gieko\\source\\repos\\TOASU_4\\TOASU_4\\f.txt");
	if (in.is_open()) {
		for (int i = 0; i < 3; i++) in >> coef[i];
		int n = coef[0];//L - размер рюкзака
		int m = coef[1];//
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
				cout << F_x[i][j] << "\t";
			cout << endl;
		}
		//create array S_y and Ways
		for (int i = 0; i < k; i++) {
			S_y[i] = new int[n];
			Ways[i] = new int[n];
		}
		int tmax = 0;//intermediate result 


		int *S = new int[k - 1];//array for intermediate result 
		int *W = new int[k - 1];
		memset(S, 0, sizeof(S));
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < k; i++) {
				if (i != 0) {
					if (j != 0) {
						for (int x = 0; x <= i; x++) {
							if (x >= m) S[x] = 0;
							else S[x] = S_y[i - x][j - 1] + F_x[j][x], W[x] = x;
						}
						S_y[i][j] = max(S, W, k);
						Ways[i][j] = P;
					}
					else {
						if (i < 4)
							S_y[i][j] = F_x[0][i], Ways[i][j] = i;
						else S_y[i][j] = F_x[0][n], Ways[i][j] = n;
					}
				}
				else S_y[i][j] = 0, Ways[i][j] = 0;
			}
		}
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < n; j++) {
				cout << S_y[i][j] << "/" << Ways[i][j] << "\t\t";
			}
			cout << endl;
		}
		int rr = k - 1;
		int *o = new int[n];
		for (int i = n - 1; i >= 0; i--) {
			o[i] = Ways[rr][i];
			rr = rr - Ways[rr][i];
		}
		cout << "one option of the optimal production: X*( " << o[0] << ", " << o[1] << ", " << o[2] << ", " << o[3] << ")" << endl;
		cout << "Check: " << F_x[0][o[0]] << " + " << F_x[1][o[1]] << " + " << F_x[2][o[2]] << " + " << F_x[3][o[3]] << " = " << F_x[0][o[0]] + F_x[1][o[1]] + F_x[2][o[2]] + F_x[3][o[3]] << endl;
		//clear cash
		for (int i = 0; i < n; i++) delete[] F_x[i];
		delete[] F_x;
		in.close();
	}
	else {
		cout << "Not true way to file..";
	}
}
*/


#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#define co 2
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	int coef[2];
	ifstream in("C:\\Users\\gieko\\source\\repos\\TOASU_4\\TOASU_4\\f.txt");
	if (in.is_open()) {
		for (int i = 0; i < 2; i++) in >> coef[i];
		int L = coef[0];//L - размер рюкзака
		int m = coef[1];// kolvo dostupnih predmetov
		//int k = coef[2];//nnumber line S_y (Y - budget)
		int **D = new int *[co];
		int **Res = new int *[L+1];
		//create array D
		for (int i = 0; i <= m; i++) {
			D[i] = new int[co];
		}
		//read in file from array D
		D[0][0] = 0; D[0][1] = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j < 2; j++) {
				in >> D[i][j];
				cout << D[i][j] << endl;
			}
		}
	}
	else {
		cout << "Not true way to file..";
	}
}