#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
typedef struct {
    int A1, A2, A3;
}TTriangle;
bool Proverka(TTriangle d) {
    if (d.A1 + d.A2 + d.A3 == 180) {
        return true;
    }
    else return false;
}
bool Proverka2(TTriangle *d) {
    if (d->A1 + d->A2 + d->A3 == 180) {
        return true;
    }
    else return false;
}
int main()
{
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    while (true) {
        ofstream output;
        output.open("C:\\Users\\Александр\\Desktop\\OUTPUT.txt", ios::out);
        if (!output) {
            cout << "Файл на запись не найден !!!";
            return 0;
        }
        int n;
        cout << "\nВведите общее количество треугольников -> ";
        cin >> n;
        TTriangle* dat = new TTriangle[n];
        TTriangle buf;
        int chet = 0;
        int k = 0;
        for (int i = 0; i < n; i++) {
            buf.A1 = rand() % 105 + 1;
            buf.A2 = rand() % 105 + 1;
            buf.A3 = rand() % 105 + 1;
            if (Proverka(buf) == 1) {
                dat[k++] = buf;
                chet++;
            }
        }
        cout << "Количество правильных треугольников -> " << chet << " \n";
        cout << "Количество неправильных треугольников -> " << n - chet;
        output << "Количество правильных треугольников -> " << chet << " \n";
        output << "Количество неправильных треугольников -> " << n - chet;
    }
}

