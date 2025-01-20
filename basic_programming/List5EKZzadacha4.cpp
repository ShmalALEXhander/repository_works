#include <iostream>
#include <windows.h>
#pragma warning (disable : 4996)
using namespace std;
int rekurs(int x) {
	if (x == 1) {
		cout << x << " ";
		return 0;
	}
	else cout << x << " "; 
	return rekurs(x - 1);
}
void rekurs2(int x) {
	if (x > 1) {
		rekurs2(x - 1);
	}
	cout << x << " ";
}
int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	while (true) {
		int n;
		printf("Введите последнее число -> ");
		cin >> n;
		rekurs(n);
		cout << endl;
		rekurs2(n);
	}
}

