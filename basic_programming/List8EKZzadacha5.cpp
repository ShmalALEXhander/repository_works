#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
typedef struct {
    char fam[15];//фамилия
    char doln[20];//Должность
    int data;//Год поступлени на работу 
}TWorker;
void func(TWorker*, int, int);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream input;
    input.open("C:\\Users\\Александр\\Desktop\\INPUT.txt", ios::in);
    if (!input) {
        cout << "Файл на чтение не найден !!!";
        return 0;
    }
    ofstream output;
    output.open("C:\\Users\\Александр\\Desktop\\OUTPUT.txt", ios::out);
    if (!output) {
        cout << "Файл на запись не найден !!!";
        return 0;
    }
    int n = 7, P;
    //cout << "Введите количество сотрудников ->";
    //cin >> n;
    TWorker* Firma = new TWorker[n];
    for (int i = 0; i < n; i++) {
        //input >> Firma[i].fam;
       // input >> Firma[i].doln;
        //input >> Firma[i].data;
        cin >> Firma[i].fam;
        cin >> Firma[i].doln;
        cin >> Firma[i].data;
    }
    cout << "Введите такой стаж работы сотрудников,выше которого данные по стажу будут выводится -> ";
    cin >> P;
    func(Firma, n, P);
}
void func(TWorker *mass, int n, int P) {
    int j = 2000;
    ofstream output;
    for (int i = 0; i < n; i++) {
        if (j - mass[i].data > P) {
            cout << mass[i].fam << " ";
            output << mass[i].fam << " ";
            cout << mass[i].doln;
            output << mass[i].doln;
            cout << mass[i].data;
            output << mass[i].data;
        }
        else continue;// необязательно
    }
}

