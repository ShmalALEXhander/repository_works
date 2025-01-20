#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

string func(string S1) {
    string S2;
    for (int i = 0; i < S1.length(); i++) {
        if ((i % 2 == 0) || (i == 0)) {
            S2 += S1[i];
        }
    }
    return S2;
}
int main()
{
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    string S1;
    cout << "Введите строку -> ";
    getline(cin, S1);
    cout << endl;
    cout << func(S1);
}
