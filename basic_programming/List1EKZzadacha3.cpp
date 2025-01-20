#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

string func(string S1, string S2, int N1, int N2) {
    static string S3=""; // нужен именно статик т.к без него будет возвращена не ссылка на строку, а ссылка на изменяемую область . ( НИ В КОЕМ СЛУЧАЕ ВОЗВРАЩАТЬ УКАЗАТЕЛЬ НА ЛОКУЛЬНУЮ ПЕРЕМЕННУЮ)
    S1[N1] = '\0';
    //S3 = S1 + S2[S2.length() - N2];
    for (int i = 0; i < N1; i++) {

        S3 += S1[i];
    }
    for (int i = S2.length()-N2; i < S2.length(); i++) {
        S3 += S2[i];
    }
    return S3; 
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N1, N2;
    string S1, S2;
    cout << "Введите число передаваемых символов 1 строки -> ";
    cin >> N1;
    cout << "Введите число передаваемых символов 2 строки -> ";
    cin >> N2;
    cout << "Введите 1 строку -> ";
    getline(cin, S1);
    getline(cin, S1); //реакция на гетлайн
    cout << "Введите 2 строку -> ";
    getline(cin, S2);
    cout << endl;
    cout << "Ответ " << func(S1, S2, N1, N2);
}