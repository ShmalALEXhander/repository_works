#include <iostream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;

void quick_sort(int*, int, int);
void radix_sort(vector<int>& vec);

int main()
{
    int i;
    int size = 500000;
    int* mass1 = new int[size];
    vector<int> mass2;
    for (i = 0; i < size; i++) {
        mass1[i] = rand() % 1000000 + 1;
        mass2.push_back(mass1[i]);
    }
    // Хоар - быстрая сортировка
    //Radix - поразрядная сортировка
    auto start_time = chrono::high_resolution_clock::now();
    quick_sort(mass1, 0, size);
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> restime = end_time - start_time;
    cout << "quick_sort -> " << restime.count() <<" seconds\n";
    for (i = 0; i < 10; i++)
        cout << mass1[i] << " ";
    start_time = chrono::high_resolution_clock::now();
    radix_sort(mass2);
    end_time = chrono::high_resolution_clock::now();
    restime = end_time - start_time;
    cout << "\nradix_sort -> " << restime.count() <<" seconds\n";
    for (i = 0; i < 10; i++)
        cout << mass2[i] << " ";
}
void quick_sort(int* s_arr, int first, int last) {
    if (first < last) {
        int left = first;
        int right = last;
        int middle = s_arr[(left + right) / 2];
        do {
            while (s_arr[left] < middle)
                left++;
            while (s_arr[right] > middle)
                right--;
            if (left <= right) {
                int tmp = s_arr[left];
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;
                right--;
            }
        } while (left < right);
        quick_sort(s_arr, first, right);
        quick_sort(s_arr, left, last);
    }
}
void radix_sort(vector<int>& mass) {
    vector<vector<int>> buskets(10);
    int power_of_ten = 1;
    int max_num = 10000;
    int d = 0;
    while (max_num > 0) {
        max_num /= 10;
        d++;
    }
    for (int pow = 0; pow < d; ++pow) {
        for (auto elem : mass) {
            buskets[elem / power_of_ten % 10].push_back(elem);
        }
        mass.clear();
        for (int i = 0; i < buskets.size(); ++i) {
            for (int j = 0; j < buskets[i].size(); ++j) {
                mass.push_back(buskets[i][j]);
            }
            buskets[i].clear();
        }
        power_of_ten *= 10;
    }
}
