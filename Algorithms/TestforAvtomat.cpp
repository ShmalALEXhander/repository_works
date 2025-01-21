#include <iostream>
using namespace std;

int main()
{
    const int N = 4;
    int map[N+1][N];
    for (int i = 0; i < N+1; i++) {
        cout << '\n';
        for (int j = 0; j < N; j++) {
            map[i][j] = -1;
            cout << map[i][j];
        }
    }
}

