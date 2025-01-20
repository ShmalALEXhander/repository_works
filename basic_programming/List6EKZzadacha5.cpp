#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
typedef struct {
	int red;
	int green;
	int blue;
}TPixel;
TPixel Color(TPixel px, int X) {
	px.red = (px.red + X > 255) ? 255 : (px.red + X);
	px.green = (px.green + X > 255) ? 255 : (px.green + X);
	px.blue = (px.blue + X > 255) ? 255 : (px.blue + X);
	return px;
}
int main() {
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	ofstream output;
	output.open("C:\\Users\\Александр\\Desktop\\OUTPUT.txt", ios::out);
	if (!output) {
		cout << "Файл на запись не найден!!!";
		return 0;
	}
	ifstream input;
	input.open("C:\\Users\\Александр\\Desktop\\INPUT.txt", ios::in);
	if (!input) {
		cout << "Файл на чтение не найден!!!";
		return 0;
	}
	int n, m;
	cout << "Введите n массива -> ";
	cin >> n;
	cout << "Введите m массива -> ";
	cin >> m;
	TPixel** dat = new TPixel * [n];
	for (int i = 0; i < n; i++) {
		dat[i] = new TPixel[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dat[i][j].red = rand() % 256;
			dat[i][j].green = rand() % 256;
			dat[i][j].blue = rand() % 256;
		}
	}
	int X;
	input >> X;
	for (int j = 0; j < m; j++) {
		dat[n - 1][j] = Color(dat[n - 1][j], X);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			output << dat[i][j].red << " " << dat[i][j].green << " " << dat[i][j].blue << " ";
			cout << dat[i][j].red << " " << dat[i][j].green << " " << dat[i][j].blue << " ";
		}
		output << endl;
		cout << endl;
	}
}