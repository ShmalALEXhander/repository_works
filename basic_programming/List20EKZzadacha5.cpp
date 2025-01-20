#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
typedef struct {
	char name[8]; //имя маршрута          7 + 1 (1 для конца строки)
	int slojn; //сложность маршрута
	int dlina;// протяжённость маршрута
}TMasrh;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream input;
	input.open("C:\\Users\\Александр\\Desktop\\INPUT.txt", ios::in);
	if (!input) {
		cout << "Файл на чтение не найден!!!";
		return 0;
	}
	ofstream output;
	output.open("C:\\Users\\Александр\\Desktop\\OUTPUT.txt", ios::out);
	if (!output) {
		cout << "Файл на запись не найден!!!";
		return 0;
	}
	const int n = 7;
	cout << "Количество маршрутов -> 7" << endl;
	TMasrh* dat = new TMasrh[n];
	for (int i = 0; i < n; i++) {
		/*/input >> dat[i].name;
		input >> dat[i].slojn;
		input >> dat[i].dlina;*/
		cin >> dat[i].name;
		cin >> dat[i].slojn;
		cin >> dat[i].dlina;
	}
	int* func(TMasrh*, int*);
	int* j;
	int m = 0;
	j = func(dat, &m);
	for (int i = 0; i < m; i++) {
		output << dat[j[i]].name << " " << dat[j[i]].slojn << " " << dat[j[i]].dlina;
		output << endl;
		cout << dat[j[i]].name << " " << dat[j[i]].slojn << " " << dat[j[i]].dlina;
		cout << endl;
	}
}
int* func(TMasrh* d, int* n) {
	static int buf[15];
	int m = 0;
	int max = 0;
	for (int i = 0; i < 7; i++) {
		if (d[i].slojn + d[i].dlina / 1000 > max) {
			max = d[i].slojn + d[i].dlina / 1000;
		}
	}
	for (int i = 0; i < 7; i++) {
		if (max == d[i].slojn + d[i].dlina / 1000) {
			buf[(*n)++] = i;
		}
	}
	return buf;
}