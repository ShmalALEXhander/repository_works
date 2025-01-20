#include <iostream>
#include <windows.h>
using namespace std;
int func(int* mass, int n, int k) {
    if (n == k) {
        return 0;
    }
    else if (mass[k] % 2 == 0) {
        cout << mass[k] << " ";
        return func(mass, n, k + 1);
    }
    else if (mass[k] % 2 != 0)
        return func(mass, n, k + 1);
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    cout << "Введите количество чисел в массиве -> ";
    cin >> n;
    int* mass = new int[n];
    for (int i = 0; i < n; i++) {
        mass[i] = rand() % 100 + 1;
    }
    for (int i = 0; i < n; i++) {
        cout << mass[i] << " ";
    }
    int k = 0;
    cout << endl;
    func(mass, n, k);
}