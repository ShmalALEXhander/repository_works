#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
string kod2[] = { "Editing", "Viewing"};
typedef struct {
	string name[9];
	int size;
	string kod;
}TFile;

int func(TFile*, int);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;//кол-во файлов
	int sizeF;//размер флешки
	cout << "Введите количество файлов -> ";
	cin >> n;
	TFile* Folder = new TFile[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 8; j++) {
			Folder[i].name[j] = rand() % ('z' - 'a') + 'a';
		}
		Folder[i].size = rand() % 5000 + 1;
		Folder[i].kod = kod2[rand() % 2];
	}
	cout << "\nРазмер папки -> " << func(Folder, n) << endl;
	cout << "Укажите размер флешки для экспортирования ->";
	cin >> sizeF;
	if (func(Folder, n) > sizeF) {
		cout << "\nНе поместится!!!";
		return 0;
	}
	else if ((func(Folder, n) == sizeF)) {
		cout << "\nФайл поместится впритык!!!\n";
	}
	else if (func(Folder, n) < sizeF) {
		cout << "\nФайл поместится!!!\n";
		cout << "Свободного места останется -> " << sizeF - func(Folder, n) << " Mb";
	}
}
int func(TFile* d, int n) {
	int summ = 0;
	for (int i = 0; i < n; i++) {
		if (d[i].kod == kod2[rand() % 1]) {
			summ += d[i].size;
		}
	}
	return summ;
}

