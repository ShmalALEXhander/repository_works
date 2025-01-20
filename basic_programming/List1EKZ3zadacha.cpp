# include <iostream>
# include <windows.h>
# include <cmath>
# include <fstream>
# include <iomanip>

using namespace std;

const int nmax = 100;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char s1[nmax];
	char s2[nmax];
	char s[2 * nmax];

	ifstream in("String27.txt");
	cin.getline(s1, sizeof(s1));
	cout << s1 << "\n";
	cin.getline(s2, sizeof(s2));
	cout << s2 << "\n";

	int n1, n2;
	int size_s2 = strlen(s2);
	cout << "Введите целые положительные числа: n1<=" << strlen(s1);
	cout << " и n2<=" << size_s2 << ": ";
	cin >> n1 >> n2;
	strncpy(s, s1, n1);
	s[n1] = '\0';

	char* p = s2;
	p += size_s2 - n2;
	strcat(s, p);

	cout << s << endl;
	system("pause");
	return 0;
}