#include<iostream>
#include<windows.h>
using namespace std;

typedef int baseType;
void make_mass(baseType*, int);
void print_mass(baseType*, int);
int binary_Search(baseType*, int, int);
int binarySearch(baseType*, int, int*, int, int);
const int size1 = 8;
int work_mass[] = { 9,4,3,0,2,7,6,8 };

void QuickSort(baseType* arr, int first, int last) {
    if (first < last) {
        int left = first, right = last;
        int m = first;
        int middle = arr[m];
        do {
            while (arr[left] > middle) {
                left++;
            }
            while (arr[right] < middle) {
                right--;
            }
            if (left <= right) {
                if (left < right && arr[left] < arr[right]) {
                    swap(arr[left], arr[right]);
                }
                left++;
                right--;
            }
        } while (left <= right);
        QuickSort(arr, left, last);
        QuickSort(arr, first, right);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int key, res;
    cout << "array ready\n";
    QuickSort(work_mass, 0, size1 - 1);
    cout << "array sorted\n";
    print_mass(work_mass, size1);
    
    cout << "Искомый ключ -> "; cin >> key;
    res = binary_Search(work_mass, size1, key);
    if (res == -1) {
        cout << "Элемент не найден!!!";
    }
    else cout << "\nПозиция в массиве -> " << res;
}
void make_mass(baseType* mass, int N) {
    for (int i = 0; i < N; i++) {
        mass[i] = rand();
    }
}
void print_mass(baseType* mass, int N) {
    cout << '\n';
    for (int i = 0; i < N; i++) {
        cout << mass[i] << ' ';
    }
}
int binary_Search(baseType* mass, int size, int key) {
    int cnt_bin = 0;
    if (key > mass[0] || key < mass[size - 1]) {
        return -1;
    }
    int res = binarySearch(mass, key, &cnt_bin, 0, size - 1);
    cout << "\nКоличество сравнений при бинарном поиске -> " << cnt_bin; 
}
int binarySearch(baseType* mass, int key, int* cnt_bin, int beg, int end) {            
    if (end - beg < 2 && mass[end] != key && mass[beg] != key) {
        return -1;
    }
    if (key == mass[md]) {
        (*cnt_bin)++;
        return md;
    }
    if (key > mass[md]) {
        (*cnt_bin)++;
        return binarySearch(mass, key, cnt_bin, beg, md - 1); 
    }
    if (key < mass[md]) {
        (*cnt_bin)++;
        return binarySearch(mass, key, cnt_bin, md + 1, end);
    }
}