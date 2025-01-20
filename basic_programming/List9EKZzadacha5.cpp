#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;

typedef struct {
	double pozSTART;                     
	double pozFINAL;                       
	int number;
}TMarsh;
typedef struct {
	int *numer;
	int size;
}NUM;
NUM func(TMarsh* d, double argument, int n) {
	int chet = 0, k = 0, podchet = 0;
	for (int i = 0; i < n; i++) {
		if ((sqrt(pow(d[i].pozSTART, 2) + pow(d[i].pozFINAL, 2)) <= argument)) {
			chet++;
		}
	}
	int* numbers = new int[chet];
	for (int i = 0; i < chet; i++) {
		if ((sqrt(pow(d[i].pozSTART, 2) + pow(d[i].pozFINAL, 2)) <= argument)) {
			numbers[k++] = d[i].number;
			podchet++;
		}
	}
	NUM str;
	str.numer = numbers;
	str.size = podchet;
	return str;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	double startSH, finalSH, startD, finalD, len;
	cout << "Введите количество элементов в массиве -> ";
	cin >> n;
	cout << "Введите длину маршута, на выходе будут маршруты непревыщающие заданный -> ";
	cin >> len;
	TMarsh* info = new TMarsh[n];
	for (int i = 0; i < n; i++) {
		startSH = 90 - rand() % 180 + 1;
		finalSH = 90 - rand() % 180 + 1;
		startD = 360 - rand() % 180 + 1;
		finalD = 360 - rand() % 180 + 1;
		if (startSH < 0) startSH += 90; if (startD < 0) startD += 180;
		if (finalSH < 0) finalSH += 90; if (finalD < 0) finalD += 180;
		info[i].pozSTART = (startSH - finalSH) * 111;
		info[i].pozFINAL = (startD - finalD) * (111 * cos(startD - finalD));
		info[i].number = rand() % 100 + 1;
	}
	NUM numbers = func(info, len, n);
	cout << "\nМаршруты не превыщающие заданный:\n";
	for (int i = 0; i < numbers.size; i++) {
		cout << numbers.numer[i] << " ";
	}
}

