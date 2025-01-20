#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
typedef struct  {
	double A1, A2, A3;
}TTriangle;
double Perim(TTriangle T) {
	return T.A1 + T.A2 + T.A3;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ofstream output;
	output.open("C:\\Users\\Александр\\Desktop\\OUTPUT.txt", ios::out);
	if (!output) {
		cout << "Файл не найден!!!";
		return 0;
	}
	int n;
	int min = 999999;
	cout << "Введите количество треугольников -> ";
	cin >> n;
	TTriangle* dat = new TTriangle[n];
	for (int i = 0; i < n; i++) {
		dat[i].A1 = rand() % 20 + 1;
		dat[i].A2 = rand() % 20 + 1;
		dat[i].A3 = rand() % 20 + 1;
		cout << "\nA1 = " << dat[i].A1 << " ";
		cout << "A2 = " << dat[i].A2 << " ";
		cout << "A3 = " << dat[i].A3 << " ";
		cout << "\nПериметр " << i + 1 << " треугольника -> " << Perim(dat[i]);
		output << "\nA1 = " << dat[i].A1 << " ";
		output << "A2 = " << dat[i].A2 << " ";
		output << "A3 = " << dat[i].A3 << " ";
		output << "\nПериметр " << i + 1 << " треугольника -> " << Perim(dat[i]);
	}
	for (int i = 0; i < n; i++) {
		if (Perim(dat[i]) < min) {
			min = Perim(dat[i]);
		}
	}
	cout << "\nСамый маленький периметр -> " << min;
	output << "\nСамый маленький периметр -> " << min;
}

