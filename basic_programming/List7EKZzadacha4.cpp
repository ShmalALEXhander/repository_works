#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

int func(int x) {
	if (x == 2) {
		return 1;
	}
	else if (x % 2 != 0) { // На каком-то этапе ОБЯЗАТЕЛЬНО появится нечётное число
		return 0;
	}
	return func(x / 2);
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Проверка числа на его кратность с цифрой 2!!!\n";
	while(true) {
		int N;
		cout << "\nВведите число -> ";
		cin >> N;
		cout << endl;
		if (func(N) == 1) {
			cout << "Yes";
		}
		else 
			cout << "NO";
	}
}
	

