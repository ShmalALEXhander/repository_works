#include <iostream>
#include <windows.h>
using namespace std;
int rekurs(int A, int B) {
	if (A == B) {
		cout << B;
		return B; ////// ???????????
	}
	else {
		cout << A << " ";
		return rekurs(A + 1, B);
	}
}
int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	int A, B;
	cout << "Введите начальное число A -> ";
	cin >> A;
	cout << "\nВведите конечное число B -> ";
	cin >> B;
	rekurs(A, B);
}
