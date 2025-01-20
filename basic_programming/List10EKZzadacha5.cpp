#include <iostream>
#include <windows.h>
using namespace std;
typedef struct {
    char fam[9]; 
    long long num;
    int data[3]; 
}TNote;
int func(TNote *d,int n, int *bday) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (d[i].data[0] == bday[0] && d[i].data[1] == bday[1] && d[i].data[2] == bday[2]) {
            cout << d[i].fam << "  " << d[i].num << endl;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //srand(time(0));
    int n;
    cout << "Введите количество элементов массива -> ";
    cin >> n;
    TNote* dat = new TNote[n];
    memset(dat, 0, sizeof(TNote) * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            dat[i].fam[j] = (char)('a' + rand() % ('z' - 'a'));         
        }       
            dat[i].num = 8 * 10000000000 + (rand() % 10) * 1000000000 + (rand() % 10) * 100000000 + (rand() % 10) * 10000000 +
                (rand() % 10) * 1000000 + (rand() % 10) * 100000 + (rand() % 10) * 10000 + (rand() % 10) * 1000 +
                (rand() % 10) * 100 + (rand() % 10) * 10 + (rand() % 10);
            dat[i].data[0] = rand() % 31 + 1;
            dat[i].data[1] = rand() % 12 + 1;
            dat[i].data[2] = rand() % 100 + 1;
    }
    int bday[3] = { 23,1,92 };
    cout << func(dat, n, bday);
}