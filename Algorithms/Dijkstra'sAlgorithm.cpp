#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int, int> //Теоритически можно ошибиться в типах. А Const проверяет тип.
void Dijkstra(vector<vector<edge>>&, int&);
const size_t inf = 2000000000; //Препроцессор

int main() {
    setlocale(LC_ALL,"rus");
    // Список смежности 
    // представляет собой вектор векторов пар.
    // Первый элемент пары смежная вершина (в массиве 1-я = 0),
    // а второй элемент – вес инцидентного ребра
    vector<vector<edge>> G{
     { {1, 1}, {2, 6}}, // 0
     { {0, 1}, {2, 4}, {3, 3}, {4, 9}, {5, 8}, {6, 7}},// 1
     { {0, 6}, {1, 4}}, // 2
     { {1, 3}, {4, 2}}, // 3
     { {1, 7}, {5, 5}}  // 4
    };
    int vortex; //ООП не поменяет ничего. Лучше матричную алгебру напиши функционально и на ООП.
    cout << "Введите номер вершины: ";
    cin >> vortex;
    Dijkstra(G, vortex);
}
void Dijkstra(vector<vector<edge>>& myG, int& s) {
    // Определяем значение infinity

    size_t n = myG.size();
    // Определяем три массива:
    // D - для хранения кратчайших путей в графе от исходной вершины
    // P - для хранения промежуточных итогов длин путей
    // U - для хранения булевских флагов посещения вершин
    vector<size_t> D(n, inf); // Вектор D размерностью n заполненный inf. *Инициализация вектора.
    //vector<size_t> P(n, inf); //size_t беззнаковое целое - пока затычка, принято чёткой разделять знаквоые и беззнаковы переменные
    vector<bool> U(n, false);
    // Исходная вершина (в данном случае первая)
    D[s] = 0;
    for (size_t i = 0; i < n; i++) {
        // Определяем уникальное значение стартовой вершины
        // Количество вершин не должно превышать это значение
        size_t v = inf;
        for (size_t j = 0; j < n; j++) { //v==inf это как флаг.
            if (!U[j] && (v == inf || D[j] < D[v])) { // Тут 2 Операнда. 
                v = j; // 1 раз отработает в коде. 1 ая попавшееся вершина.
              // break;
            }
        }
        // Выходим, если встретился хоть один инф,
        // что значит: кратчайших маршрутов больше не найдено
        if (D[v] == inf)
            break;
        // Говорим, что посетили вершину
        U[v] = true;
        // Определяем итераторы по текущему списку
        auto beg = myG[v].begin();
        auto end = myG[v].end();
        while (beg != end) { //
            int to = beg->first;
            int len = beg->second;
            // Этот процесс называют "релаксацией". Т.е. если можно меньше получить путь,
            // то повторяет алгоритм Флойда – Уоршелла
            if (D[to] > D[v] + len) {
                D[to] = D[v] + len;
            }
            beg++;
        }
    }
    // Выводим список кратчайших маршрутов от
    // исходной вершины ко всем остальным:
    for (auto r : D) {
        cout << r << " ";
    }
}
/*#include <iostream>
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
        {{4,3},{2,8},{3,2}},
        {{2,4}},
        {{1,4},{0,8},{3,6},{4,4}},
        {{0,2},{2,6}}, 
        { { 0,3 },{2,4} },
    };
    int vortex;
    cout << "Введите начальную вершину ->";
    cin >> vortex;
    Dijkstra(G, vortex);
}
void Dijkstra(vector<vector<edge>>& myG, int& s) {
    //Определить состояние (Возможно) и построить вывод для составляющих короткий путь вершин.
    const int inf = 2000000000;
    size_t n = myG.size();
    size_t i, j;
    vector<size_t> D(n, inf);
    //vector<size_t> P(n, inf);
    vector<bool> U(n, false);
    D[s] = 0;

    for (i = 0; i < n; i++) {
        vector <int> mindist(n, 0);
        size_t v = inf;
        for (j = 0; j < n; j++) {
            if (!U[j] && (v == inf || D[j] < D[v])) {
                v = j; //без брейка возьмёт последнюю по n 
                //break;// Влияет на время обработки, но сам алгоритм не меняется
            }
        }
        if (D[v] == inf)
            break; // Для текущей вершины переходы все просмотрены
        U[v] = true;
        auto beg = myG[v].begin();
        auto end = myG[v].end();
        while (beg != end) { 
            int to = beg->first;
            int len = beg->second;
            if (D[to] > D[v] + len) {
                D[to] = D[v] + len;
                mindist.push_back(v);
            }
            beg++;
        }
        for (auto it: mindist) {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (auto r : D) {
        cout << r << " ";
    }
    //Т.к. мы просматриваем построчно можно формировать вектор минимальных вершин.
}

*/