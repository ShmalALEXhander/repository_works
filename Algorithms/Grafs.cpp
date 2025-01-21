#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define edge pair<int,int>

class Graph {
	vector<pair<int, edge>> G;
	vector<pair<int, edge>> T;
	int* parent;
public: Graph(int size) {
		parent = new int[size];
		for (int i = 0; i < size; i++)
			parent[i] = i;
		G.clear();
		T.clear();
	}
	void AddWeight(int a, int b, int w) {
		G.push_back(make_pair(w, edge(a, b)));
	}
	void printFM() {
		for (int i = 0; i < G.size(); i++) {
			cout << G[i].second.first << "-";
			cout << G[i].second.second << " ";
			cout << G[i].first << "\n";
		}
	}
	int find(int i) {
		if (i == parent[i])
			return i;
		else return find(parent[i]);
	}
	void Union(int a, int b) {
		parent[a] = parent[b];
	}
	void kruskal() {
		int a, b;
		sort(G.begin(), G.end());
		for (int i = 0; i < G.size(); i++) {
			a = find(G[i].second.first);
			b = find(G[i].second.second);
			if (a != b) {
				T.push_back(G[i]);
				Union(a, b);
			}
		}
	}
};

int main()
{
	Graph g(5);
	g.AddWeight(0, 1, 3);
	g.AddWeight(1, 3, 3);
	g.AddWeight(0, 3, 8);
	g.AddWeight(0, 2, 2);
	g.AddWeight(3, 4, 8);
	g.printFM();
	g.kruskal();
	cout << endl;
	g.printFM();
}
