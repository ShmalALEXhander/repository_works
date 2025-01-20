#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

int get_digit(string d) {
    int chet = 0;
    for (int i = 0; i < d.length(); i++) {
        if (isdigit(d[i]))
            chet++;
    }
    return chet;
}
string *func(string* d, int n) {
    int flag = 0;
    do {
        flag = 0;
        for (int i = 0; i < n - 1; i++) {
            if (get_digit(d[i]) > (get_digit(d[i + 1]))) {
                flag = 1;
                swap(d[i], d[i + 1]);
            }
        }
    } while (flag == 1);
    return d;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream input;
    input.open("C:\\Users\\Александр\\Desktop\\INPUT.txt", ios::in);
    if (!input) {
        cout << "Файл на чтение не найден!!!";
        return 0;
    }
    ofstream output;
    output.open("C:\\Users\\Александр\\Desktop\\OUTPUT.txt", ios::out);
    if (!output) {
        cout << "Файл на запись не найден!!!";
        return 0;
    }
    int n = 8;
    string* mass = new string[n];
    for (int i = 0; i < n; i++) {
        getline(input, mass[i]);
    }
    func(mass, n);
    for (int i = 0; i < n; i++) {
        cout << mass[i] << "\n";
        output << mass[i] << "\n";
    }
}


