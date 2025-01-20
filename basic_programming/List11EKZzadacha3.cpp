#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <algorithm>
using namespace std;

string* func(string* mass, int n) {
    int flag = 0;
    do {
        flag = 0;
        for (int i = 0; i < n - 1; i++) {
            if (mass[i].length() > mass[i + 1].length()) {
                flag = 1;
                swap(mass[i], mass[i + 1]);
            }
        }
   } while (flag == 1);
    return mass;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream input;
    input.open("C:\\Users\\Александр\\Desktop\\INPUT.txt", ios::in);
    if (!input) {
        cout << "Файл на чтение не найден !!!";
        return 0;
    }
    int n = 8;
   // cout << "Сколько строчек считать из массива ???";
   // cin >> n;
    string* mass = new string[n];
    for (int i = 0; i < n; i++) {
        getline(input, mass[i]);
    }
    ofstream output;
    output.open("C:\\Users\\Александр\\Desktop\\OUTPUT.txt", ios::out);
    if (!output) {
        cout << "Файл на запись не найден !!!";
        return 0;
    }
    string* ptr = func(mass, n);
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << ptr[i] << '\n';
        output << ptr[i] << '\n';
    }
}

 