#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
string func(string S1, string S2) {
    string S3;
    for (int i = 0; i < S1.length(); i++) {
        S3 += S1[i];
    }
    for (int i = S2.length(); i >= 0; i--) {
        S3 += S2[i];
    }
    return S3;
}
int main()
{
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    string S1, S2;
    cout << "Введите 1 строчку ->";
    getline(cin, S1);
    cout << "Введите 2 строчку ->";
    getline(cin, S2);
    cout << endl;
    cout << func(S1, S2);
}
