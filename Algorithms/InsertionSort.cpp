#include <iostream>
#include <windows.h>
using namespace std;

void Sort(int* arr, int n) {
	int counter = 0;
	for (int i = 1; 0 < n; i++) {
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
			counter++;
			int tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
		}
	}
	cout << counter << endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size;
	cout << "Введите размер массива ->";
	cin >> size;
	int* mass = new int[size];
	for (int i = 0; i < size; i++) {
		mass[i] = rand() % 50;
		cout << mass[i] << " ";
	}
	Sort(mass, size);
	cout << '\n';
	for (int i = 0; i < size; i++) {
		cout << mass[i] << " ";
	}
}
