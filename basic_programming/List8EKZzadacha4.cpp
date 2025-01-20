#include<iostream>
#include<windows.h>
using namespace std;

int func(int n) {
	if (n == 0) {
		return 0;
	}
	else return n % 10 + func(n / 10);
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true) {
		int n;
		cout << "\nВведите число -> ";
		cin >> n;
		cout << "Сумма цифр числа = " << func(n);
	}
}