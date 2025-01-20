#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;

typedef struct {
	char simvl;
	int kolvo;
}TChar;
TChar* func(TChar* d, string s) {
	for (int i = 0; i < s.length(); i++) {
		d[s[i]].simvl = s[i];
		d[s[i]].kolvo++;
	}
	return d;
}
int main() {
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	ofstream output;
	output.open("C:\\Users\\Александр\\Desktop\\OUTPUT.txt", ios::out);
	if (!output) {
		cout << "Файл на запись не найден !!!";
		return 0;
	}
	string stroka;
	while (true) {
		cout << "Введите строку -> ";
		getline(cin, stroka);
		TChar* dat = new TChar[256];
		memset(dat, 0, 256 * sizeof(TChar));
		TChar* spisok = func(dat, stroka);
		for (int i = 0; i < 256; i++) {
			if (spisok[i].simvl != 0) {
				cout << dat[i].simvl << " " << dat[i].kolvo << "\n";
				output << dat[i].simvl << " " << dat[i].kolvo << "\n";
			}
		}
	}
}
