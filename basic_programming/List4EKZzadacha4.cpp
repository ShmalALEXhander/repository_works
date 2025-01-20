#include <iostream>
#include <fstream>
#include <windows.h>
#pragma warning (disable : 4996)
using namespace std;
void PrNeg(int* mass, int n) {// передаём размер
	if (n != 0) {
		PrNeg(mass, n - 1);
	}
	if (mass[n] < 0) {
		cout << mass[n] << " ";
	}
}

int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	int n, a;
	printf("Количество элементов в массиве -> ");
	cin >> n;
	printf("Введите верхнюю границу максимума элементов -> ");
	cin >> a;
	int* mass = new int[n];
	for (int i = 0; i < n; i++) {
		mass[i] = a/2 - rand() % a; // !!!!!!!
		cout << mass[i] << " ";
	}
	cout << endl;
	PrNeg(mass, n - 1); //предельный индекс -- всё происходит из-за подсчёта с 0
}