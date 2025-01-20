#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
bool func(string S) {
	long long num = 0;
	if (S[0] == '+') {
		num = atoll((char*)&S[1]);
	}
	else
		num = atoll((char*)&S[0]);
	if (num == 0)
		return false;
	if (num > 80000000000 && num < 89999999999)
		return true;
	else
		return false;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream input;
	input.open("C:\\Users\\Александр\\Desktop\\INPUT.txt", ios::in);
	if (!input) {
		cout << "Файл на чтение не найден";
		return 0;
	}
	ofstream output;
	output.open("C:\\Users\\Александр\\Desktop\\OUTPUT.txt", ios::out);
	if (!output) {
		cout << "Файл на запись не найден";
		return 0;
	}
	string stroka;
	int i = 0;
	while (getline(input, stroka)) {
		i++;
		if (func(stroka) == 1) {
			output << i << " номер -> " << stroka << endl;
		}
	}
}