#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int func(string s) {
	int res = 0;
	bool flag = true;
	for (int i = 0; i < s.length(); i++) {
		if ((isdigit(s[i])) && (flag)) {
			res += atoi(&s[i]);
		}
		else if (s[i] == '+') {
			flag = true;
		}
		else if (s[i] == '-'){
			flag = false;
		}
		else if ((isdigit(s[i])) && (!flag)) {
			res -= atoi(&s[i]);
		}
	}
	return res;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true) {
		string stroka;
		cout << "\nВведите выражение для вычисления:\n";
		getline(cin, stroka);
		cout << "Результат = " << func(stroka);
	}
}
