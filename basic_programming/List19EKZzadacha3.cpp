#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;
typedef struct {
	int kolvo;
	string STROKA;
}MAS;
MAS get_roman(string in) {
	static string out;
	//out.resize(300);
	string dig[] = { "0","I","II","III","IV","V","VI","VII","VIII","IX" };
	int j = 0, chet = 0;
	for (int i = 0; i < in.length(); i++) {
		if (!isdigit(in[i])) {
			char c = in[i];
			string app = "0";
			app[0] = c;
			out += app;
		}
		else {
			int k = (int)(in[i] - '0');
			out += (dig[k]);
			j += dig[k].length();
			chet++;
		}
	}
	MAS fly;
	fly.kolvo = chet;
	fly.STROKA = out;
	return fly;
} // Проблема: string это динамическая структура и при добавлении символов её размер расширяется (если добавление делается через append или через + или += (всегда перегрузка)

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream input;
	input.open("C:\\Users\\Александр\\Desktop\\INPUT.txt", ios::in);
	if (!input) {
		cout << "Файл на чтение не найден !!!";
		return 0;
	}
	ofstream output;
	output.open("C:\\Users\\Александр\\Desktop\\OUTPUT.txt", ios::out);
	if (!output) {
		cout << "Файл на запись не найден !!!";
		return 0;
	}
	string stroka;
	while (getline(input, stroka)) {
		MAS data = get_roman(stroka);
		cout << stroka << endl << data.STROKA << " - " << data.kolvo;
		output << stroka << endl << data.STROKA << " - " << data.kolvo;
	}
}
