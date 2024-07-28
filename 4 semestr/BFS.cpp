#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

const int INF = 1e9;


vector<int> bfs(vector<vector<int>>& graph, int start, vector<bool>& visited, vector<int>& component) {
	vector<int> dist(graph.size(), INF);
	queue<int> q;
	visited[start] = true;
	component.push_back(start);
	dist[start] = 0;
	q.push(start); // добавляем в очередь

	while (!q.empty()) {
		int v = q.front();
		q.pop();


		for (int to : graph[v]) {
			if (dist[to] > dist[v] + 1) {
				dist[to] = dist[v] + 1;
				q.push(to);


				visited[to] = true;
				component.push_back(to);

			}
		}
	}


	return dist;
}

int findConnectedComponents(vector<vector<int>>& graph) {
	int numVertices = graph.size();
	vector<bool> visited(numVertices, false);
	int numComponents = 0;

	for (int i = 0; i < numVertices; i++) {
		if (!visited[i]) {
			vector<int> component;
			bfs(graph, i, visited, component);
			numComponents++;
			cout << "Component " << numComponents << ": ";
			for (int vertex : component) {
				cout << vertex << " ";
			}
			cout << endl;
		}
	}

	return numComponents;
}



int main() {
	setlocale(LC_ALL, "Russian");

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int vertexCount, edgeCount;
	cin >> vertexCount >> edgeCount; // веришина и ребра
	vector<vector<int>> graph(vertexCount);


	for (int i = 0; i < edgeCount; i++) {
		int a;
		int b;
		cin >> a >> b;
		//граф у нас является не ориентированный поэтому добавляем ребро дважды
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int start;
	cin >> start;
	vector<bool> visited(vertexCount, false);
	vector<int> component;
	vector<int> dist = bfs(graph, start, visited, component);
	for (int d : dist) {
		if (d != INF) {
			cout << d << endl;
		}

	}

	int numComponents = findConnectedComponents(graph);
	cout << "Количество компонентов связи: " << numComponents << endl;

	return 0;


}