#include <iostream>
#include <string>
#include <set>
#include <map>
#define N 10
using namespace std;

map<char, int> alpha2idx;

int Map[N][N];

set<char> alphaSet;
int main()
{
    int n;
    int s_begin, s_end;
    int s0, s1;
    string str;// Строка для распознавания
    cin >> n;
    cin >> s_begin >> s_end;
    char alpha;
    int idx4alpha = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            Map[i][j] = -1;
    for (int i = 0; i < n; i++) {
        cin >> s0 >> alpha >> s1;
        if (alphaSet.find(alpha) == alphaSet.end()) {// Определяем, преобразован ли текущий символ в соответствующий индекс
            alpha2idx[alpha] = idx4alpha;
            alphaSet.insert(alpha);
            idx4alpha++;
        }
        Map[s0][alpha2idx[alpha]] = s1;
    }

    while (cin >> str) {
        int curState = s_begin;//Начальное состояние
        cout << curState << "->";
        int len = str.size();
        bool flag = true;
        for (int i = 0; i < len; i++) {
            if (alphaSet.find(str[i]) == alphaSet.end()) {// Определяем, находится ли текущая буква в алфавите
                flag = false;
                break;
            }
            else {
                i != len - 1 ? cout << Map[curState][alpha2idx[str[i]]] << "->" : cout << Map[curState][alpha2idx[str[i]]];

                if (Map[curState][alpha2idx[str[i]]] != -1) {
                    curState = Map[curState][alpha2idx[str[i]]];
                }
                else {
                    flag = false;
                    break;
                }
            }
        }
        cout << endl; 
        if (curState == s_end && flag) {
            cout << "True" << endl;
        }
        else {
            cout << "False" << endl;
        }
    }
    return 0;
}
