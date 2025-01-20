#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;
string func(string S) {
	string Sfinal;
	bool flag = false;
	for (int i = 0; i < S.length(); i++) {
		if ((S[i] != '(') && (flag == false)) {
			Sfinal += S[i];
		}
		else if (S[i] == '(') {
			flag = true;
		}
		else if ((flag == true) && (S[i] == ')')) {
			flag = false;
		}
	}
	return Sfinal;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string s_in, s_out;
	ifstream input;
	input.open("C:\\Users\\Александр\\Desktop\\INPUT.txt", ios::in);
	if (!input) {
		cout << "Файл на чтение не найден!!!";
		return 0;
	}
	getline(input, s_in);
	s_out = func(s_in);
	input.close();
	ofstream output;
	output.open("C:\\Users\\Александр\\Desktop\\INPUT.txt", ios::out);
	if (!output) {
		cout << "Файл на запись не найден!!!";
		return 0;
	}
	cout << s_in;
	cout << '\n';
	cout << s_out;
	output << s_in;
	output << '\n';
	output << s_out;
}