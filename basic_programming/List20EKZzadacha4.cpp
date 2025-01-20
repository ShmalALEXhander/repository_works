#include <iostream>
#include <windows.h>
using namespace std;
int rekurs(int A, int B) {
    if (A != B) {
        if (A >= 0) {
            if (A % 2 == 0) {
                cout << A << " ";
                return rekurs(A + 1, B);
            }
            else return rekurs(A + 1, B);
        }
        else return rekurs(A + 1, B);
    }
    else if ((B % 2 == 0) && (B > 0))
        cout << B;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (true) {
        int A, B;
        cout << "Введите начальную границу A -> ";
        cin >> A;
        cout << "Введите конечную границу B -> ";
        cin >> B;
        rekurs(A, B);
        cout << endl;
    }
}
