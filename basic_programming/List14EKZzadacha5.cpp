#include <iostream>
#include <windows.h>
using namespace std;

typedef struct {
    char name[7];
    int number;
    int data[3];
}TPlane;
TPlane *func(TPlane*, int);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    cout << "Введите количество самолётов(элементов массива) -> ";
    cin >> n;
    TPlane* Aeroflot = new TPlane[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            Aeroflot[i].name[j] = (char)(rand() % ('z' - 'a') + 'a'); //rand -сдвиг , "a - база
        }
        Aeroflot[i].number = i + 1;
        Aeroflot[i].data[0] = rand() % 31 + 1;
        Aeroflot[i].data[1] = rand() % 12 + 1;
        Aeroflot[i].data[2] = 2000 + rand() % 40 + 1;
    }
    TPlane * summer= func(Aeroflot, n);
    int i = 0;
    while (summer[i].data[1] >= 6 && summer[i].data[1] <= 8) {
        cout << summer[i].name << "  ";
        cout << summer[i].number << "  ";
        cout << summer[i].data[0] <<"."<< summer[i].data[1] <<"."<< summer[i].data[2] << endl;
        i++;
    }
}
TPlane *func(TPlane *d, int n) {
    int chet = 0;
    for (int i = 0; i < n; i++) {
        if (d[i].data[1] >= 6 && d[i].data[1] <= 8) {
            chet++;
        }
    }
    TPlane* dat = new TPlane[chet];
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (d[i].data[1] >= 6 && d[i].data[1] <= 8) {
            dat[p++] = d[i];
        }
    }
    return dat;
}
