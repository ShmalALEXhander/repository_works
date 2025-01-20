#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int Max = 4;
    for (int i = 0; i < (int)pow(2, Max - 2); i++) {
        string s = "";
        int k = i;
        while (k != 0) {
            s += (char)(k % 2+'0');
            k /= 2;
        }
        int l = s.length();
        for (int i = 0; i < (Max - 2)-l; i++) s += "0";
       
        cout << "0" << s << "0" << endl;
    }
}
/*
3   0/1
4   0xx0  1xx1  xx= 0..3  2^2
5   0xxx0 1xxx1  xxx=0..7  2^3
6   0xxxx0 1xxxx1 xxxx=0..15 2^
7
 for (int len = 1; len < Max; len++) {
        string s = "";
        for (int i = 0; i < pow(3, len - 1); i++) {
            cout << "aaaa" << endl;
       
        }
    }*/

