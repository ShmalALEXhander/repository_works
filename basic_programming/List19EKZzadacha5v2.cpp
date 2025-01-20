#include<iostream>
#include<fstream>
#include<windows.h>
#pragma warning(disable : 4996)
using namespace std;

typedef struct {
	char name[20];
	char doln[24];//*
	char otdel[20];
}TWorker;
char func(TWorker* d, int size, char* nameotdel/*(&nameotdel)[13]*/) {
	char chief[20];
	int  chet = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp(d[i].otdel, nameotdel) == 0) {
			cout << d[i].name << endl;
			chet++;
		}
		if (strcmp(d[i].doln, "chief") == 0) {
			strcpy(chief, d[i].name);
		}
	}
	if (chet == 0) {
		cout << "Отдел пуст!!!";
	}
	else {
		cout << "Количество сотрудников в отделе -> " << chet << endl;
		cout << "Руководитель отдела -> " << chief << endl;
	}
	return 0;
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
	while (true) {
		char nameotdel[13] = "";
		cout << "Введите имя отдела -> ";
		cin.getline(nameotdel, 13);
		cin.getline(nameotdel, 13);
		func(Firma, size, nameotdel);
	}
}