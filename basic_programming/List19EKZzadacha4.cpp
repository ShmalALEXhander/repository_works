#include <iostream>
#include <windows.h>
using namespace std;

int func(int* dat, int n) {
	if (n != 0) {
		if (dat[n - 1] % 2 == 0) {
			return dat[n - 1] + func(dat, n - 1);
		}
		else return func(dat, n - 1);
	}
	else return 0;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while(true) {
		int n;
		cout << "\nВведите количество элементов -> ";
		cin >> n;
		int* dat = new int[n];
		for (int i = 0; i < n; i++) {
			dat[i] = rand() % 50 + 1;
		}
		for (int i = 0; i < n; i++) {
			cout << dat[i] << " ";
		}
		cout << endl;
		cout << "Сумма чётных элементов массива -> ";
		cout << func(dat, n);
	}
}

