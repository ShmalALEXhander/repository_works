#include <iostream>
#include <vector>
using namespace std;
const int N = 4; //В контейнерах позволяет расходовать большие системные ресурсы
void printFm(vector <vector <int>>, int);

int main()
{
    setlocale(LC_ALL, "rus");

    const int INF = 1e9;
    vector <vector<int> > F(N, vector<int>(N, INF));
    vector <vector<int> > W(N, vector<int>(N, 0));
    /*int matrix[N][N]{
        {0,2,5,7},
        {4,0,INF,5},
        {2,INF,0,3},
        {INF,6,3,0},
    };*/
    int matrix[N][N]{
        {INF,2,5,7},
        {4,INF,INF,5},
        {2,INF,INF,3},
        {INF,6,3,INF},
    };
   /* int matrix[N][N]{
        {0,2,1},
        {INF,0,-2},
        {INF,INF,0}
    };*/

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            W[i][j] = matrix[i][j];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            F[i][j] = INF; // Вроде как начальные состояние всего графа( те самые 0 и бесконечности при рукопашном решении)
    }
/////////////////////////////// ПРОСТО ВЫВОД ( НЕ ВАЖНО)
cout << "Before"<<endl;
for (int i = 0; i < N; i++) {
    cout << "\n";
    for (int j = 0; j < N; j++) {
        cout << F[i][j] << " ";
    }
}
cout << endl;
for (int i = 0; i < N; i++) {
    cout << "\n";
    for (int j = 0; j < N; j++) {
        cout << W[i][j] << " ";
    }
}
/////////////////////////////// ПРОСТО ВЫВОД ( НЕ ВАЖНО)
    int start;
    cout << "\nВведите стартовую вершину -> ";
    cin >> start;
    F[0][start] = 0;
    for (int k = 1; k < N; ++k)
        for (int j = 0; j < N; ++j)
        {
            F[k][j] = F[k - 1][j];
            for (int i = 0; i < N; ++i)
                if (F[k - 1][i] + W[i][j] < F[k][j])
                    F[k][j] = F[k - 1][i] + W[i][j];
        }
    /////////////////////////////// ПРОСТО ВЫВОД ( НЕ ВАЖНО)
    cout << endl;
    for (int i = 0; i < N; i++) { 
        cout << "\n";
        for (int j = 0; j < N; j++) {
            cout <<F[i][j] << " ";
        }
    }
    printFm(W, N);
   /* cout << endl;
    for (int i = 0; i < N; i++) { 
        cout << "\n";
        for (int j = 0; j < N; j++) {
            cout << W[i][j] << " ";
        }
    }*/
    /////////////////////////////// ПРОСТО ВЫВОД ( НЕ ВАЖНО)
}
void printFm(vector<vector<int>> mass, int N) {
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << "\n";
        for (int j = 0; j < N; j++) {
            cout << mass[i][j] << " ";
        }
    }
}
