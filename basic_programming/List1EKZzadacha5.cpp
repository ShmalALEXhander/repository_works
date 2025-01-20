#include<iostream>
#include<fstream>
#include<windows.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996 )
using namespace std;
typedef struct {
    double x, y;
}TPoint;
double Leng(double A,double B) {
    double d;
    d = sqrt(pow((A), 2) + pow((B), 2));
    return d;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ofstream output;
    output.open("C:\\Users\\Александр\\Desktop\\OUTPUT.txt", ios::out);
    if (!output) {
        printf("Файл на запись не найден!!!");
        return 0;
    }
    double ktX, ktY, dlina;
    int n;// количество отрезков в массиве
    cout << "\nВведите количество отрезков в массиве -> ";
    cin >> n;
    TPoint* data = new TPoint[n];
    for (int i = 0; i < n; i++) {
        cout << "\n";
        data[i].x = rand() % 50 + 1;
        cout << "x";
        output << "x";
        cout << data[i].x << " ";
        output << data[i].x << " ";
        data[i].y = rand() % 50 + 1;
        cout << "y";
        output << "y";
        cout << data[i].y << " ";
        output << data[i].y << " ";
    }
    for (int i = 0; i < n; i++) {
        cout << endl;
        cout << "Между " << i + 1 + 1 << " и " << i + 1 << " точками -> ";
        ktX = data[i + 1].x - data[i].x;
        ktY = data[i + 1].y - data[i].y;
        dlina = Leng(ktX, ktY);
        cout << endl;
        cout << dlina << " ";
        output << "Между " << i + 1 + 1 << " и " << i + 1 << " точками -> ";
        output << endl;
        output << dlina << " ";
    }
}