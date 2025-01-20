#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
typedef struct {
    int Number;
    int Month;
    int Year;
}TDate;
int ConverData(TDate dat) {
    int x, y, z;
    x = dat.Number;
    y = dat.Month * 30;
    z = dat.Year * 365;
    return x + y + z;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream input;
    input.open("C:\\Users\\Александр\\Desktop\\INPUT.txt", ios::in);
    if (!input) {
        cout << "Файл не найден!!!";
        return 0;
    }
    ofstream output;
    output.open("C:\\Users\\Александр\\Desktop\\OUTPUT.txt", ios::out);
    if (!output) {
        cout << "Файл не найден!!!";
        return 0;
    }
    int summa;
    int n = 5;//количество дат
    TDate* dat = new TDate[n];
    for (int i = 0; i < n; i++) {
        input >> dat[i].Number;
        input >> dat[i].Month;
        input >> dat[i].Year;
        summa = ConverData(dat[i]);
        cout << "Дни -> " << summa << " для " << i + 1 << " сочетания\n";
        output << "Дни -> " << summa << " для " << i + 1 << " сочетания\n";
    }
}

