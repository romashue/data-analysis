#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#define _CRT_SECURE_NO_WARNINGS 

using namespace std;

const int INF = 1e9;

int prim(vector<vector<pair<int, int>>>& graph) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    vector<int> minWeight(numVertices, INF);
    int totalWeight = 0;

    minWeight[0] = 0; // Начинаем с вершины 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, 0 }); // Пара {вес, вершина}

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        totalWeight += w;

        for (auto& edge : graph[u]) {
            int to = edge.first;
            int weight = edge.second;
            if (!visited[to] && weight < minWeight[to]) {
                minWeight[to] = weight;
                pq.push({ weight, to });
            }
        }
    }

    return totalWeight;
}

int main() {
    setlocale(LC_ALL, "Russian");

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;
    vector<vector<pair<int, int>>> graph(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        graph[a].push_back({ b, weight });
        graph[b].push_back({ a, weight });
    }

    int minWeight = prim(graph);
    cout << "Минимальный вес остовного дерева: " << minWeight << endl;

    return 0;
}