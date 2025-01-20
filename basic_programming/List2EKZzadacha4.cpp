#include <iostream>
#include <windows.h>
using namespace std;
double f(double x, int n) {
    if (n == 1) {
        return x;
    }
    return x * f(x, n - 1);
}
int main()
{
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    int n;
    double x;
    cout << "Введите x -> ";
    cin >> x;
    cout << "Введите n -> ";
    cin >> n;
    cout << endl;
    cout << f(x, n);
}


