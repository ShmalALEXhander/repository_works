#include<iostream>
#include<windows.h>
using namespace std;
string cities[] = { "Vladivostok","Moscow","Saratov","Perm","London","Paris","Peterburg","Izum"
"RostovOnDon","Rostov","Kuba","Kislovodsk","Novosibirsk","Novorossiysk" };

typedef struct {
	int* mas;//Указатель на 1 число массива numbers,потому fly.size=chet; Указатель на целое число и на массив это 1 и тоже !!!!    Натуральный костыль)))
	int size;
}MAS;
typedef struct { 
	int day;
	int month;
	int year;
}Date;
typedef struct { //переименовываем структуру !!!!!
	string name;
	int number;
	Date data;
}TPlane;
MAS func(TPlane* mass, int d, int m, int y, int n, string gorod) {
	int chet = 0;
	for (int i = 0; i < n; i++) {
		if (mass[i].data.day == d && mass[i].data.month == m && mass[i].data.year == y && mass[i].name == gorod) {
			chet++;
		}
	}
	int* numbers = new int[chet];
	for (int k = 0, i = 0; i < n; i++) {
		if (mass[i].data.day == d && mass[i].data.month == m && mass[i].data.year == y && mass[i].name == gorod) {
			numbers[k++] = mass[i].number;
		}
	}
	MAS fly;
	fly.mas = numbers; 
	fly.size = chet;
	return fly;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	string gorod;
	int d, m, y;
	cout << "Введите количество самолётов -> ";
	cin >> n;
	cout << "\n********************************\n";
	TPlane* Aeroflot = new TPlane[n];
	for (int i = 0; i < n; i++) {
		Aeroflot[i].name = cities[rand() % 14];
		Aeroflot[i].number = rand() % 10000 + 1;
		Aeroflot[i].data.day = rand() % 30 + 1;
		Aeroflot[i].data.month = rand() % 12 + 1;
		Aeroflot[i].data.year = rand() % 5 + 2020;
	}
	cout << "Определение нужного пункта назначения!!!\n";
	cout << "Введите день -> ";
	cin >> d;
	cout << "\nВведите месяц -> ";
	cin >> m;
	cout << "\nВведите год -> ";
	cin >> y;
	cout << "\nВведите интересующий город -> ";
	cin >> gorod; 
	MAS nums = func(Aeroflot, d, m, y, n, gorod);
	for (int i = 0; i < nums.size; i++) {
		cout << "Номер самолёта -> " << nums.mas[i] << endl;
	}
}