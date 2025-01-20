#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
string func(string s) {
    string sfinal;
    for (int i = 0; i < s.length() - 2; i++) {
        if (isdigit(s[i]) && isdigit(s[i + 2])) {
            switch (s[i + 1]) {
            case '+':cout << s[i] << s[i + 1] << s[i + 2] << "=" << (s[i] - '0') + (s[i + 2] - '0') << endl; break;
            case '-':cout << s[i] << s[i + 1] << s[i + 2] << "=" << (s[i] - '0') - (s[i + 2] - '0') << endl; break;
            case '*':cout << s[i] << s[i + 1] << s[i + 2] << "=" << (s[i] - '0') * (s[i + 2] - '0') << endl; break;
            case '/':cout << s[i] << s[i + 1] << s[i + 2] << "=" << (s[i] - '0') / (s[i + 2] - '0') << endl; break;
            case ':':cout << s[i] << s[i + 1] << s[i + 2] << "=" << (s[i] - '0') / (s[i + 2] - '0') << endl; break;
            default:break;
            }
        }
    }
    return sfinal;
}
int main()
{
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    while (true) {
        string stroka;
        cout << "\nВведите строку -> ";
        getline(cin, stroka);
        cout << endl;
        cout << func(stroka);
    }
}
