#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
string func(string s1, string s2) {
	int j = 0;
	string S3=""; //isdigit (параметр - символ) - ПОСМОТРИ           isnumber (параметр - строка)
	for (int i = 0; i < s1.length(); i++) {
		if ((s1[i] >= '0') && (s1[i] <= '9')) {
			S3+= s1[i]; // По стандарту есть перегуженный оператор + , когда мы ставим ему операндами 2 строки , то он выполняет склейку строк
		}
	}
	for (int i = 0; i < s2.length(); i++) {
		if (isalpha(s2[i])) {
			S3+= s2[i];
		}
		//if (((s2[i] >= 'A') && (s2[i] <= 'Z')) || ((s2[i] >= 'a') && (s2[i] <= 'z')));
	}
	return S3;
}
int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	string S1, S2;
	cout << "Введите строку 1 -> ";
	getline(cin, S1);
	cout << "Введите строку 2 -> ";
	getline(cin, S2);
	cout << func(S1, S2);
}

