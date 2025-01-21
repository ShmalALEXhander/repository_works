#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 7; // Определяем количество вершин

void bfs(int matrix[N][N], int beg, int size, int* used, vector<int>& route) {
    queue<int> q;          // Очередь для BFS
    used[beg] = 1;         // Помечаем начальную вершину как посещенную
    q.push(beg);          // Добавляем начальную вершину в очередь
    route.push_back(beg); // Добавляем начальную вершину в маршрут

    while (!q.empty()) {
        int vertex = q.front(); // Получаем вершину из очереди
        q.pop();                // Убираем ее из очереди

        // Проверяем всех соседей текущей вершины
        for (int col = 0; col < size; col++) {
            // Если есть ребро и вершина еще не посещена
            if (matrix[vertex][col] != 0 && used[col] == 0) {
                used[col] = 1;      // Помечаем соседнюю вершину как посещенную
                q.push(col);        // Добавляем ее в очередь
                route.push_back(col); // Добавляем в маршрут
            }
        }
    }
}

int main() {
    int matrix[N][N] = {
        {0,0,0,1,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0},
        {1,1,0,0,1,0,1},
        {0,0,1,1,0,1,0},
        {0,0,0,0,1,0,1},
        {0,0,0,1,0,1,0}
    };

    for (int i = 0; i < N; i++) {
        int used[N] = { 0 }; // Инициализируем массив посещенных вершин
        vector<int> route; // Вектор для хранения маршрута

        bfs(matrix, i, N, used, route); // Запускаем BFS для каждой вершины

        cout << "From vertex " << i + 1 << ": ";
        for (int num : route) {
            cout << num + 1 << " "; // Выводим вершины в маршруте (с учетом 1-индексации)
        }
        cout << endl;
    }

    return 0;
}