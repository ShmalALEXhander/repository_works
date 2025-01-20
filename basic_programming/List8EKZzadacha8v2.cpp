#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
char func(char *S) {
	char S3[100];
	for (int i = 0; i < sizeof(S); i++) {
		//if (S[i]) {
		if ((i == 0) || (i % 2 == 0)) {
			if ((S[i] >= 'A') && (S[i] <= 'Z')) {
				S3[i] += S[i];
			}
			else {
				S[i] = (char)(S[i] + 32);
				S3[i] += S[i];
			}
		}
		else {
			if ((S[i] >= 'a') && (S[i] <= 'z')) {
				S3[i] += S[i];
			}
			else {
				S[i] = (char)(S[i] - 32);
				S3[i] += S[i];
			}
		}
		//}
		//else
			//continue;
	}
	return S3[25];
}
int main()
{
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	//setlocale(LC_ALL, "rus");
	char S[255];
	cout << "Vvedite stroku -> ";
	cin >> S;
	//getline(cin, S);
	cout << func(S);
}