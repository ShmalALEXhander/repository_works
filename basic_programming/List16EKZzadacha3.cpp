#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int func(char* stroka) {
    int res = 0;
    for (int i = 0; i < strlen(stroka); i++) {
        if (!isdigit(stroka[i]) && !isalpha(stroka[i])) {
            if (stroka[i] != '+') {
                cout << "Неправильный знак!!!";
                break;
            }
        }
        if (isdigit(stroka[i]))
            res += (stroka[i] - '0'); //Выполнено. Но логичнее работать с чётными и нечётными индексами, текст функции уменьшится в 2-3 раза!!!
    }
    cout << "\nCумма элементов = ";
    return res;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (true) {
        char stroka[64];
        cout << "\nВведите строку -> ";
        cin.getline(stroka,64);
        cout << func(stroka);
    }
}