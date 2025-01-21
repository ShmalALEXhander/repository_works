#include <iostream>
#include <windows.h>
using namespace std;
//typedef int baseType;

int mass_g[] = { 6,3,9,2,1,5,4,7 };

void QuickSort(int*, int, int);

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size = 8;
    /*int size;
    cout << "Введите размер массива -> ";
    cin >> size;
    baseType* mass = new baseType[size];*/
    for (int i = 0; i < size; i++) {
        /*mass[i] = rand() % 150 + 1;*/
        cout << mass_g[i] <<" ";
    }
    QuickSort(mass_g, 0, size - 1);;
    cout << '\n';
    for (int i = 0; i < size; i++) {
        cout << mass_g[i] <<" ";
    }
}
void QuickSort(int* mass, int first, int last) {
    if (first < last) {
        int left = first, right = last;
        int m = first;
        int middle = mass[m];
        do {
            while (mass[left] > middle) {
                left++;
            }
            while (mass[right] < middle) {
                right--;
            }
            if (left <= right) {
                if (left < right && mass[left] < mass[right]) {
                    swap(mass[left], mass[right]);
                }
                left++;
                right--;
            }
        } while (left <= right);
        QuickSort(mass, left, last);
        QuickSort(mass, first, right);
    }
}
