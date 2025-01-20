#include <iostream>
#include <windows.h>
using namespace std;
double func(double x, int n) {
	if (n == 1) {
		return x;
	}
	else return x * func(x, n - 1);
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "*** Вычисление значения функции y = x^3 ***\n";
	while (true) {
		double a, b, res;
		const int n = 3;
		double d = 0.1;
		cout << "Введите границу a  -> ";
		cin >> a;
		cout << "\nВведите границу b  -> ";
		cin >> b;
		for (double i = a; i <= b; i += d) {
			res = func(i, n);
			cout << "Результат = " << res << " при x =" << i << endl;
		}
		cout << endl;
	}
}
