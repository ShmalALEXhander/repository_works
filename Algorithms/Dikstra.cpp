#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int,int>
void Dijkstra(vector<vector<edge>>&, int&);

int main()
{
    setlocale(LC_ALL, "rus");
    //vector<vector<edge>> G{
    //  {{1,3},{2,8},{3,2}},
    //  {{0,3},{2,4}},
    //  {{1,4},{0,8},{3,6},{4,4}},
    //  {{0,2},{2,6}},
    //  {{4,4}}
    //};
    vector<vector<edge>> G{
      {{1,3},{2,8},{3,2}},
      {{0,3},{2,4}},
      {{1,4},{0,8},{3,6},{4,4}},
      {{0,2},{2,6}},
      {{2,4}}
    };
    int vortex;
    cout << "Введите начальную вершину ->";
    cin >> vortex;
    Dijkstra(G, vortex);
}
void Dijkstra(vector<vector<edge>>& myG, int& s) {
    size_t size = myG.size();
    const int inf = 2000000000;
    vector<size_t> D(size, inf);
    vector<bool> U(size, false);
    D[s] = 0;

    size_t i, j;
    for (i = 0; i < size; i++) {
        size_t v = inf;
        for (j = 0; j < size; j++) {
            if (!U[j] && (v == inf || D[v] > D[j]))
                v = j;
        }
        if (D[v] == inf)
            break;
        U[v] = true;
        auto beg = myG[v].begin();
        auto end = myG[v].end(); //Итератор возвращает значение
        while (beg != end) {
            int to = beg->first;
            int len = beg->second;
            if (D[to] > D[v] + len)
                D[to] = D[v] + len;
            beg++;
        }
    }
    for (auto r : D) {
        cout << r << " ";
    }
}

