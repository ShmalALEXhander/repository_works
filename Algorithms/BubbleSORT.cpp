#include <iostream>
using namespace std;
int main()
{
	int size;
	cin >> size;
	cout << '\n';
	int* mass = new int[size];
	for (int i = 0; i < size; i++) {
		mass[i] = rand() % 80 + 1;
	}
	for (int i = 0; i < size; i++) {
		cout << mass[i] << ' ';
	}
	for (int i = 0; i < size; i++) {
		for (int i = 0; i < size - 1; i++) {
			if (mass[i] > mass[i + 1]) {
				swap(mass[i], mass[i + 1]);
			}
		}
   }
	cout << '\n';
	for (int i = 0; i < size; i++) {
		cout << mass[i] << ' ';
	}
}