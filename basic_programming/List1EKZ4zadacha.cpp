#include<iostream>
#include<windows.h>
using namespace std;
void rekurs(int n) {
	if (n > 1) {
		rekurs(n - 1);
	}
	cout << n << " ";
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << "Введите максимальное число -> ";
	cin >> n;
	rekurs(n);
}