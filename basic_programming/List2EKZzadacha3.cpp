#include <iostream>
#include <windows.h>
using namespace std;
string func(string S1, string S2, int n) {
    string S3;
    for (int i = 0; i < 2*n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i % 2 == 0) || (i == 0)) {
                S3 += S1[j];
                break;
            }
            else S3 += S2[j];
            break;
        }
    }
    return S3;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string S1, S2;
    int N;
    cout << "Введите длину обеих строчек -> ";
    cin >> N;
    cout << "Введите 1 строку -> ";
    cin >> S1;
    cout << "Введите 2 строку -> ";
    cin >> S2;
    cout << endl;
    cout << "Ответ -> " << func(S1, S2, N);
}