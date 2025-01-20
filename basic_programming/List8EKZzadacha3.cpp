#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
string func(string S) {
	bool flag = 0;
	for (int i = 0; i < S.length(); i++) {
		if (isalpha(S[i])) {
			S[i] = (flag) ? tolower((int)S[i]) : toupper((int)S[i]);
			flag = !flag;
		}
	}
		return S;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string S;
	while (true) {
		cout << "\nВведите строку -> ";
		getline(cin, S);
		cout << func(S);
	}
}
/*string S3 = "";
	for (int i = 0; i < S.length(); i++) {
		if (S[i]) {
			if ((S[i] >= 'A') && (S[i] <= 'Z')) {
				S[i] = (char)(S[i] + 32);
				S3 += S[i];
			}
			else {
				if ((S[i] >= 'a') && (S[i] <= 'z')) {
					S[i] = (char)(S[i] - 32);
					S3 += S[i];
				}			
			}
		}
		else
		continue;
	}
	return S3;*/