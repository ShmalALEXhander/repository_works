#include <iostream>
#include <windows.h>
using namespace std;

typedef struct {
    char name[20];
    int cena;
    int kolvo;
} TTovar;
int func(TTovar* mass[3], int n, int m) {
    int chet = 0;
    int max = 0, s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mass[i][j].cena != 0) {
                chet++;
            }
            else break;
        }
        if (chet > max) {
            max = chet;
            s = i;
        }
    }
    return s;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int n = 3;
    int m, kategor;
    cout << "\nВведите количество товаров во всех 3 категориях -> ";
    cin >> m;
    TTovar** mass = new TTovar * [n];
    for (int i = 0; i < n; i++) {
        mass[i] = new TTovar[m];
        memset(mass[i], 0, sizeof(TTovar));
    }
    int pos[n];
    pos[0] = pos[1] = pos[2] = 0;
        for (int j = 0; j < m; j++) {
            cin >> kategor;
            cin >> mass[kategor - 1][pos[kategor -1]].name;
            cin >> mass[kategor - 1][pos[kategor - 1]].cena;
            cin >> mass[kategor - 1][pos[kategor - 1]].kolvo;
            pos[kategor - 1]++;
        }
        cout << "Больше всего товаров в категории -> " << func(mass, n, m) + 1;
}
