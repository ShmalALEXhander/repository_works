#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#pragma warning (disable : 4996)
using namespace std;

int func(string d) {
	int chet = 0, max = 0;
	for (int i = 0; i < d.length(); i++) {
		if (isdigit(d[i])) {
			chet++;
		}
		else {
			if (chet > max)
				max = chet;
			chet = 0;
		}
	}
	return max;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ofstream output;
	output.open("C:\\Users\\Александр\\Desktop\\OUTPUT.txt", ios::out);
	if (!output) {
		cout << "Файл на запись не найден";
		return -1;
	}
	while (true) {
		string bufMAX, bufMIN;
		int max = 0, min = 1000;
		int n, a = 0;
		cout << "\nВведите количество строк в массиве -> ";
		cin >> n;
		string* mass = new string[n];
		for (int i = 0; i < n; i++) {
			if (a == 0) {
				getline(cin, mass[i]);
				a++;
			}
			getline(cin, mass[i]);
		}
		for (int i = 0; i < n; i++) {
			int len = func(mass[i]);
			if (len > max) {
				max = len;
				bufMAX = mass[i];
				//strcpy((char*)&bufMAX[0], (char*)&mass[i]);
			}
			if (len < min) {
				min = len;
				bufMIN = mass[i];
				//strcpy((char*)&bufMIN[0], (char*)&mass[i]);
			}
			cout << "Максимальное количество цифр, идущих подряд -> " << len << "\n";
		}
		cout << bufMAX << " = " << max << '\n';
		cout << bufMIN << " = " << min;
	}
}