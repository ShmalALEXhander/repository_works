#include <iostream>
#include <stdio.h>
using namespace std;
double mtrx_mult(int*, int, int);

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите количество размерностей матриц:\n ";
    int N;
    cin >> N;
    int* dim = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> dim[i];
    }
    printf("Введено отрицательное число");
        //dim = [10, 30, 5, 60] # Задавать в программе
    printf("Минимальное количество скалярных умножений = ");
    cout<<mtrx_mult(dim, 0, N - 1);
}
double mtrx_mult(int* arr, int i, int j) {
    double m_cnt,mn;
    if (j <= i + 1)
        return 0;
    //mn = pow(2, 64) - 1;
    for (int k = i + 1; k <= j; j++) {
        m_cnt = mtrx_mult(arr, i, k);
        m_cnt += mtrx_mult(arr, k, j);
        m_cnt += arr[i] * arr[k] * arr[j];
        mn = min(mn, m_cnt);
    }
    printf("");
    return mn;
}               
                

            