#include <iostream>
#include <windows.h>
using namespace std;

int func(int* d, int size, int k) {
    if (k != size) {
        if (d[k] >= d[k + 1]) {
            d[k + 1] = d[k];
            return func(d, size, k + 1);
        }
        return func(d, size, k + 1);
    }
    else return d[k];
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (true) {
        int n, k = 0;
        cout << "\nВведите размер массива -> ";
        cin >> n;
        int* mass = new int[n];
        for (int i = 0; i < n; i++) {
            mass[i] = rand() % 125 + 1;
        }
        for (int i = 0; i < n; i++) {
            cout << mass[i] << " ";
        }
        cout << endl;
        cout << "Максимальный элемент -> " << func(mass, n, k);
    }
}

