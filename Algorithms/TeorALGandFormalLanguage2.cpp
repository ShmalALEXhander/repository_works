#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

string provAlfa(string tmp);
int provNum(string tmp);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (true) {
        cout << " ";
        string ans = "";
        int len_alfa;
        string tmpN, tmpA;
        string tmp;//подтверждение
        int tmpNUM;
        cout << " ";
        string alfa;
        alfa = provAlfa(tmpA);
        len_alfa = alfa.length();
        cout << " ";
        tmpNUM = provNum(tmpN);
        while (tmpNUM >= 1) {
            for (int i = 1; i <= len_alfa; i++)
                if ((tmpNUM - i) % len_alfa == 0) {
                    tmpNUM = (tmpNUM - i) / len_alfa;
                    ans += alfa[i - 1];
                    cout << tmpNUM << "x" << len_alfa << "+" << i << " ";
                    break;
                }
        }
        reverse(ans.begin(), ans.end());
        cout << "\n";
        cout << "Cлово -> " << ans;
        cout << "\nХотите повторить ? Введите + или - \n";
        cin >> tmp;
        if (tmp == "-") {
            cout << "Программа закончила свою работу.";
            break;
        }
        else continue;
    }
}

string provAlfa(string alfa) {
    while (true) {
        int flag = 0;
        cout << "Введите алфавит\n->";
        cin >> alfa;
        for (int i = 0; i < alfa.length(); i++) {
            unsigned char a = alfa[i];
            if (!((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z') || (a >= 0xC0 && a <= 0xFF))) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) continue;
        break;
    }
    return alfa;
}

int provNum(string tmp) {
    int K;
    while (true) {
        int flag = 0;
        cout << " ";
        do {
            cout << "Введите номер \n->";
            cin >> tmp;
        } while (tmp.length() == 0);
        for (int i = 0; i < tmp.length(); i++)
            if (!isdigit(tmp[i])) {
                flag = 1;
                break;
            }
        if (flag == 1) continue;
        K = atoi((char*)&tmp[0]);
        if (K > 0) {
            return K;
        }
    }
}
