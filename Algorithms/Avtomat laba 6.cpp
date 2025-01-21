#include <iostream>
#include <string>
using namespace std;

int main()
{
    int size = 5;
    int N, M;
   
    string final = { '3','6' };
    string nofinal = { '0','1','2','4','5' };
    N = final.length();
    M = nofinal.length();
    string** mass = new string *[N+1];
    for (int i = 0; i < nofinal.length() + 1; i++)
    mass[i] = new string[M+1];
    //Заполенение массива
    for (int i = 1, j = 0; i < N, j < N; i++, j++) {
        mass[i][0] = final[j];  
    }
    for (int j = 0; j < M; j++)
        mass[0][j + 1] = nofinal[j];
    for (int i = 0; i < N + 1; i++) {
        cout << "\n";
        for (int j = 0; j < M + 1; j++)
            cout << mass[i][j] << " ";
    }
}

