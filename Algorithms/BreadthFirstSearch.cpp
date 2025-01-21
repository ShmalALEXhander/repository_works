#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 7; //Поиск в ширину


void bfs(int matrix[N][N], int beg, int size, int* used, vector<int>& route, vector<int>& sequence) {
	queue<int> q;
	used[beg] = 1;
	for (int col = 0; col < size; col++) {
		if (matrix[beg][col] != 0 && used[col] == 0) {
			used[col] = 1;
			q.push(col);
			sequence.push_back(col);
		}
	}
	while (!q.empty()) {
		int vertex = q.front();
		q.pop();
		for (int col = 0; col < size; col++) {
			if (matrix[vertex][col] != 0 && used[col] == 0) {
				bfs(matrix, vertex, size, used, route, sequence);
			}
		}
	}
}

int main() {
	int matrix[N][N] = {
		{0,0,0,1,0,0,0},
		{0,0,1,1,0,0,0},
		{0,1,0,0,1,0,0},
		{1,1,0,0,1,1,0},
		{0,0,1,1,0,0,1},
		{0,0,0,1,0,0,1},
		{0,0,0,0,1,1,0}};
	// 0-3-1-4-6-2-5-
	for (int i = 0; i < N; i++) {
		int used[N];
		for (int j = 0; j < N; j++) used[j] = 0;
			vector<int> route;
			vector<int> sequence;
			bfs(matrix, i, N, used, route, sequence);
			cout << "Sequence from "<< i + 1 << endl;
			for (int num : sequence) {
				cout << num + 1 << " ";		
			}
			cout << "Route from " << i + 1 << endl;
			for (int num : route) {
				cout << num + 1 << " ";
			}
			cout << endl;
	}
}

