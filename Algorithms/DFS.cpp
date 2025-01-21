#include <iostream>
#include<vector>
//#include <stack>
using namespace std;
const int N =5;

void print_route(vector <int> route) {
	cout << "Route ";
	for (auto point : route) {
		cout << point + 1 << " ";
	}
	cout << endl;
}
int dfs(int matrix[N][N], int beg, int size, int* used, vector<int>&route, vector<int>&sequence) {
	//stack.pop();
	int res=0, cnt=0;
	used[beg] = 1;
	route.push_back(beg);
	sequence.push_back(beg);
	for (int col = 0; col < size; col++) {
		if (matrix[beg][col] != 0 && used[col] == 0) {
			//stack.push(col);
			res=dfs(matrix, col, N, used, route, sequence);
			cnt++;
		}
	}
	
	if (cnt == 0) {
		print_route(route);
		route.pop_back();
		
		return 0;
	}
	used[beg] = 0;
	return 1;
}

int main()
{
	int matrix[N][N] = {
		{0,1,0,1,0},
		{1,0,1,0,1},
		{0,1,0,0,0},
		{1,0,0,0,1},
		{0,1,0,1,0}
	};
	

	/*int matrix[N][N] = {
		{0,0,0,1,0,0,0},
		{0,0,1,1,0,0,0},
		{0,1,0,0,1,0,0},
		{1,1,0,0,1,1,0},
		{0,0,1,1,0,0,1},
		{0,0,0,1,0,0,1},
		{0,0,0,0,1,1,0} };*/

	for (int i = 0; i < N; i++) {
		//stack<int>stack;
		//stack.push(i);
		int used[N];
		for (int j = 0; j < N; j++) used[j] = 0;
		vector<int> route;
		vector<int> sequence;
		cout << "Routes from " << i + 1 << endl;
		dfs(matrix, i, N, used, route, sequence);
		cout << "Sequence from " << i + 1 << endl;
		for (int num : sequence) {
			cout << num + 1 << " ";
		}
		cout << endl;
	}


}

