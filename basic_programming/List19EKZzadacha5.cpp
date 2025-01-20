#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;

typedef struct {
	string name;
	string doln;
	string otdel;
}TWorker;
void func(TWorker* d, int size, string nameotdel) {
	int chet = 0;
	string chief;
	for (int i = 0; i < size; i++) {
		if (d[i].otdel == nameotdel) {
			cout << d[i].name << "\n";
			chet++;
			if (d[i].doln == "chief") {
				chief = d[i].name;
			}
		}
	}
	if (chet == 0) {
		cout << "Этот отдел пуст!!!";
	}
	else {
		cout << "Количество сотрудников в отделе -> " << chet << endl;
		cout << "Руководитель отдела -> " << chief;
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream input;
	input.open("C:\\Users\\Александр\\Desktop\\INPUT.txt", ios::in);
	if (!input) {
		cout << "Файл на чтение не найден!!!";
		return 0;
	}
	int size;
	cout << "Введите количество сотрудников во всех отделах -> ";
	cin >> size;
	TWorker* Firma = new TWorker[size];
	for (int i = 0; i < size; i++) {
		input >> Firma[i].name;
		input >> Firma[i].doln;
		input >> Firma[i].otdel;
	}
	string nameotdel;
	while (true) {
		cout << endl;
		cout << "\nВведите наименование отдела -> ";
		cin >> nameotdel;
		func(Firma, size, nameotdel);
	}
}