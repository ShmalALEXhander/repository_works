#include<iostream>
#include<windows.h>
using namespace std;

int func(int A, int B) {
	if (A >= 0) {
		return 0;
	}
	if (B == A) {
		return B;
	}
	else {
		if (B >= 0) {
			return 1 * func(A, B - 1);
		}
		else return B * func(A, B - 1);
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int A, B;
	while (true) {
		cout << "\nВведите начальную позицию A -> ";
		cin >> A;
		cout << "Введите конечную позицию B -> ";
		cin >> B;
		cout << endl;
		cout << "Произведение отрицательных элементов -> " << func(A, B);
	}
}