#include <iostream>
#include <fstream>
#include <windows.h>
#pragma warning (disable : 4996)
using namespace std;
int rekurs(int A, int B) { ///////?????????
    if (A < B) {
        if (A % 2 == 0)
        {
            cout << " " << A;
        }
        return rekurs(A + 1, B);
    }
    else if (A == B) {
        cout << " ";
        return B;
    }
}
int main()
{
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    ofstream output;
    output.open("C:\\Users\\Александр\\Desktop\\OUTPUT.txt", ios::out);
    if (!output) {
        printf("Файл  не найден!!!");
        return 0;
    }
    int A, B;
    printf("Введите число A -> ");
    cin >> A;
    printf("Введите число B -> ");
    cin >> B;
    rekurs(A, B);
    output << rekurs(A, B);
    output.close();
    ifstream output;
    output.open("C:\\Users\\Александр\\Desktop\\INPUT.txt", ios::in);
    
}
