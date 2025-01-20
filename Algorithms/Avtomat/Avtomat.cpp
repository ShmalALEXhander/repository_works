
#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>
#include <windows.h>
#pragma warning (disable : 4996)
using namespace std;
const int maxplen = 401;
bool hasch[256];
void computefunc(const string p, int f[maxplen][256])
{
    int m = p.length();
    for (int i = 0; i <= m; i++)
    {
        for (int j = 1; j <= 255; j++)
        {
            if (hasch[j]) {
                int k = 0;
                if (m >= i + 1) k = i + 1;
                else k = m;
                while (k > 0)
                {
                    k = k - 1;
                    char c = p[k];
                    if ((k >= 0) && c == j) {
                        int t1 = k, t2 = i;
                        while ((t1 > 0) && (p[t1] == p[t2])) {
                            t1 = t1 - 1;
                            t2 = t2 - 1;
                        }
                        if (t1 == 0) {
                            k++;
                            break;
                        }
                    }

                }
                f[i][j] = k;
            }

        }
    }
}
void match(const string t, int f[maxplen][256], const int m)
{
    cout << "Осуществим проход по тексту. В начале автомат находится в состоянии q=0." << endl;
    cout << "Взяв следующий символ 'а' текста T. Автомат переходит в состояние f[q]['а']" << endl << endl;
    int n = t.length();
    int v = 0, q = 0;
    for (int i = 0; i < n; i++) {
        char c = t[i];
        v = f[q][c];
        cout << "T[" << i + 1 << "] =  " << "'" << t[i] << "'" << " , f[" << q << ", " << "'" << t[i] << "'" << "] = " << v;
        q = f[q][c];
        if (v == m) cout << ", мы попали в состояние " << m << ". следовательное образец входит в текст с позиции " << i - m + 2 << "." << endl;
        else cout << endl;
    }
}
void fill(const int n, const char ch)
{
    for (int i = 0; i <= n; i++) cout << ch;
}
void printfunc(int f[maxplen][256], const int m)
{
    cout << endl;
    cout << "Длина образца |P| = " << m << ", поэтмоу количество состояний в автомате - " << m + 1 << " (|P|+1)." << endl;
    cout << "Автомат находит вхождения образца, если он попадает в допускающее состояние " << m << "." << endl;
    cout << "Построим функцию перехода f. Для каждого префикса P[0..m], где m=0.." << m << " ." << endl;
    cout << "Переберем все символы 'a', встречающиеся в образце, и найдем максимальный" << endl << "суффикс строки P[0..m]a, который является префиксом P. Длину найденного префикса" << endl <<
        "сохраним в ячейке f[m, 'a'] функции переходов." << endl << endl << "Полученная в результате функция переходов имеет вид:" << endl << endl;
    int t = m;
    int digits = 0;
    while (t > 0) {
        digits = digits;
        t = t / 10;
    }
    cout << "  ";
    for (int i = 0; i <= m + digits; i++) cout << "| " << i;
    cout << endl;
    for (int i = 1; i <= 255; i++) {
        if (hasch[i])
        {
            cout << "--";
            for (int j = 0; j <= m; j++)
            {
                cout << "+";
                fill(digits + 1, '-');
            }
            cout << endl;
            char c = i;
            cout << " " << c;
            for (int j = 0; j <= m; j++) cout << "| " << f[j][i];
            cout << endl;
        }
    }
    cout << endl;
}
int _tmain(int argc, TCHAR* argv[])
{
    setlocale(LC_ALL, "Russian");
    int f[maxplen][256];
    string t;
    cout << "Введите строку:" << endl;
    getline(std::cin, t);
    int n = 0;
    cout << "Количество подстрок,которые мы пытаемся найти:" << endl;
    cin >> n;
    string* p = new string[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        memset(f, 0, sizeof(f));
        memset(hasch, false, sizeof(hasch));
        cout << endl << "Ищем образец \"" << p[i] << "\" (P) в тексте " << t << "\" (T).";
        for (int j = 0; j < p[i].length(); j++)
        {
            char c = p[i][j];
            hasch[c] = true;
        }
        computefunc(p[i], f);
        printfunc(f, p[i].length());
        match(t, f, p[i].length());
        cout << "\n\n\n\n\n\n\n\n\n";
    }
    getch();
    return 0;
}