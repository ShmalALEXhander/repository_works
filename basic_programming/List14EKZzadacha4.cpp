#include <iostream>
#include <windows.h>
using namespace std;

int func(int A, int B) {
	if (B <= 0) {
		return 0;
	}
	if (A > B) {
		return 0;
	}
	if (A > 0) {
		if (A % 2 == 0) {
			return A + func(A + 1, B);
		}
		else return func(A + 1, B);
	}
	else return  func(A + 1, B);
}
int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	while (true) {
		int A, B;
		cout << "\nВведите начальную позицию А -> ";
		cin >> A;
		cout << "\nВведите конечную позицию В -> ";
		cin >> B;
		cout << "\nСумма положительных чётных элементов -> " << func(A, B);
	}
}

