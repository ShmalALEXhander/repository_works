#include <iostream>
#include <fstream>
#include <windows.h>
#include <cmath>
#pragma warning (disable : 4996)
using namespace std;
typedef struct {
    double x, y;
} TPoint;
typedef struct {
    TPoint d;
}Triangle;
double Leng(double A, double B) {
    return sqrt((pow(A, 2)) + (pow(B, 2)));
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    double a, b;
    printf("Введите количество прямых ->");
    cin >> n;
    Triangle* tochku = new Triangle[n];
    for (int i = 0; i < n; i++) {
        tochku[i].d.x = rand() % 30 + 1;// ???????????????????????????????
        tochku[i].d.y = rand() % 30 + 1;
    }
    for (int i = 0; i < n; i++) {
        a = Leng(tochku[i + 1].d.x, tochku[i].d.x);
        b = Leng(tochku[i + 1].d.y, tochku[i].d.y);
    }
}

