#include<iostream>
#include<windows.h>
using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    int Max;
    cout << "Введите количество элементов в цепочке ->";
    cin >> Max;
    for (int i = 0; i < (int)pow(2, Max - 2); i++) { //лучше делать int 
        string s = "";
        int k = i;
        while (k != 0) {
            s += (char)(k % 2 + '0');
            k /= 2;
        }
        int l = s.length();
        for (int i = 0; i < (Max - 2) - l; i++) 
            s += "0";
            cout << "0" << s << "0" << endl;
    }
    for (int i = 0; i < (int)pow(2, Max - 2); i++) {
        string s = "";
        int k = i;
        while (k != 0) {
            s += (char)(k % 2 + '0');
            k /= 2;
        }
        int l = s.length();
        for (int i = 0; i < (Max - 2) - l; i++)
            s += "0";
        cout << "1" << s << "1" << endl;
    }
}

