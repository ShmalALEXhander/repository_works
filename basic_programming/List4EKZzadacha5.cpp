#include <iostream>
#include <fstream>
#include <windows.h>
#pragma warning (disable : 4996)
using namespace std;
typedef struct {
    int Day;
    int Month;
    int Year;
}TDate;
int CheekDate(TDate D) {
    if (!((D.Day > 0) && (D.Day <= 30))) {
        return 2;
    }
    else if (!((D.Month > 0) && (D.Month <= 12))) {
        return 1;
    }
    else return 0;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ofstream output;
    output.open("C:\\Users\\Александр\\Desktop\\OUTPUT.txt", ios::out);
    if (!output) {
        printf("Файл не найден !!!");
        return 0;
    }
    int n, res;
    int k = 0;
    printf("Введите количество дат -> ");
    cin >> n;
    TDate* dat = new TDate[n];
    for (int i = 0; i < n; i++) {
        dat[i].Day = rand() % 50 + 1; 
        dat[i].Month = rand() % 25 + 1; ////////////// НЕ ВЫЗЫВАЙ СЛИШКОМ МНОГО ФУНКЦИЙ
        dat[i].Year = rand() % 100 + 1;
    }
    for (int i = 0; i < n; i++) {
        if (CheekDate(dat[i]) != 0) {                        
            output << dat[i].Day << " ";
            output << dat[i].Month << " ";
            output << dat[i].Year << endl;
        } 
    }
    cout << "###########Таблица неправильных треугольников###########";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << " День " << dat[i].Day << endl;
        cout << " " << i + 1 << " Месяц " << dat[i].Month << endl;
        cout << " " << i + 1 << " Год " << dat[i].Year << endl;
    }
}