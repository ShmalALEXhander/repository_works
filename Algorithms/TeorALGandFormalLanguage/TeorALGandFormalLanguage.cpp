#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int getnum(char, string);
string provAlfa(string);
string provWord(string);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string word, alfa;
    int size;//(k)
    int sizealfa, i;
    string tmp;// Подтверждение
    while (true) {
        alfa = provAlfa(alfa);
        word = provWord(word);
        size = word.length();
        sizealfa = alfa.length();
        cout << "Алфавит -> " << alfa << "\n";
        cout << "Количество букв в слове = " << size << "\n";
        cout << "Количество букв в алфавите Е = " << sizealfa << "\n";
        long long sum = 0;
        for (int i = 0; i < size; i++) {
            int pos;
            if ((pos = getnum(word[i], alfa)) != -1) {
                int tmp = pow(sizealfa, size - i - 1);
                sum += tmp * pos;
                cout << sizealfa << "**" << size - i - 1 << "x" << pos << " ";
            }
        }
        cout << "\nНомер -> " << sum;
        cout << "\nХотите повторить ? Введите + или - \n";
        cin >> tmp;
        if (tmp == "-") {
            cout << "Программа закончила свою работу.";
            break;   
        }
        else continue;
    }
}
int getnum(char c, string alfa)  {
    int size = alfa.length();
    for (int i = 0; i < size; i++) 
        if (c == alfa[i])return i + 1;
    return -1;
}
string provAlfa(string alfa) {
    while (true) {
        int flag = 0;
        cout << "Введите алфавит\n->";
        cin >> alfa;
        for (int i = 0; i < alfa.length(); i++) {
            unsigned char a = alfa[i];
            if( !( (a >='A' && a<= 'Z') || (a >= 'a' && a <= 'z') || (a >= 0xC0 && a <= 0xFF))){
                flag = 1;
                break;
            }
        }
        if (flag == 1) continue;
        break;
    }
    return alfa;
}
string provWord(string word) {
    while (true) {
        int flag = 0;
        cout << "\nВведите слово\n->";
        cin >> word;
        for (int i = 0; i < word.length(); i++) {
            unsigned char a = word[i];
            if (!((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z') || (a >= 0xC0 && a <= 0xFF))) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) continue;
        else break;
    }
    return word;
}
//  if (((alfa[i] < 0x80 && alfa[i]> 0xAF) || (alfa[i] < 0xE0 && alfa[i]>0xF1)) ||
         //      ((alfa[i] < 0x65 && alfa[i]>0x90) || (alfa[i] < 0x97 && alfa[i]>0x122))) {