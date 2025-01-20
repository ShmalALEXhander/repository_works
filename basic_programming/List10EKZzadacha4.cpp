#include <iostream>
#include <windows.h>
using namespace std;
int func(int* dat, int n, int k) {
	if (n != k) {
		if (dat[k] % 2 != 0) {
			cout << dat[k] << " ";
			return dat[k] + func(dat, n, k + 1);
		}
		else return func(dat, n, k + 1);
	}
	else return 0;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, k = 0;
	cout << "Введите количество элементов массива -> ";
	cin >> n;
	int* mass = new int[n];
	for (int i = 0; i < n; i++) {
		mass[i] = rand() % 80 + 1;
	}
	for (int i = 0; i < n; i++) {
		cout << mass[i] << " ";
	}
	cout << endl;
	cout << "Суммы нечётных чисел массива -> " << func(mass, n, k);
}