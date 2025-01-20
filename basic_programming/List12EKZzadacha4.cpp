#include<iostream>
#include<windows.h>
using namespace std;
int SUM(int* data, int n) {
	if (n != 0) {
		return data[n - 1] + SUM(data, n - 1);
	}
	else return 0;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << "Введите размер массива -> ";
	cin >> n;
	int* dat = new int[n];
	for (int i = 0; i < n; i++) {
		dat[i] = rand() % 500 + 1;
	}
	for (int i = 0; i < n; i++) {
		cout << dat[i] << " ";
	}
	cout << endl;
	cout << SUM(dat, n);
}