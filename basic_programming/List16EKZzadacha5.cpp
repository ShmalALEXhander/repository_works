#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

typedef struct {
	char name[15];//название месяца
	int kolvo;// количество дней в месяце
	int prazdn;// количество праздников в месяце
}TMonth;
int* func(TMonth* d, int* n) {
	int  max = 0;
	static int j[12]; // static - делает массив постоянным, глобальным, по имени виден только в этой функции.
	for (int i = 0; i < 12; i++) {
		if (d[i].prazdn > max) {
			max = d[i].prazdn;
		}
	}
	for (int i = 0; i < 12; i++) {
		if (d[i].prazdn == max) {
			j[(*n)++] = i;
		}
	} 
	return j;
}
/*/int func(TMonth* d, int n) {
	int max = 0, j = 0;
	for (int i = 0; i < n; i++) {
		if (d[i].prazdn > max) {
			max = d[i].prazdn;
			j = i;
		}
	}
	return j;
}
*/
int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	ifstream input;
	input.open("C:\\Users\\Александр\\Desktop\\INPUT.txt", ios::in);
	if (!input) {
		cout << "Файл на чтение не найден!!!";
		return 0;
	}
	ofstream output;
	output.open("C:\\Users\\Александр\\Desktop\\OUTPUT.txt", ios::out);
	if (!output) {
		cout << "Файл на запись не найден!!!";
		return 0;
	}
	const int n = 12;
	TMonth* GOD = new TMonth[n];
	for (int i = 0; i < n; i++) {
		input >> GOD[i].name;
		input >> GOD[i].kolvo;
		input >> GOD[i].prazdn;
	}
	int* j;
	int m = 0;
	j = func(GOD,&m);
	for (int i = 0; i < m; i++) {
		output << GOD[j[i]].name << " " << GOD[j[i]].kolvo << " " << GOD[j[i]].prazdn;
		output << endl;
		cout << GOD[j[i]].name << " " << GOD[j[i]].kolvo << " " << GOD[j[i]].prazdn;	
		cout << endl;
	}
}

