#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int from, to, weight;
};

bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

int findParent(int vertex, vector<int>& parent) {
    if (parent[vertex] == vertex)
        return vertex;
    return parent[vertex] = findParent(parent[vertex], parent);
}

void unionSets(int a, int b, vector<int>& parent) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b)
        parent[b] = a;
}

int kruskal(const vector<Edge>& edges, int vertexCount) {
    vector<int> parent(vertexCount);
    for (int i = 0; i < vertexCount; i++)
        parent[i] = i;

    int minWeightSum = 0;
    vector<Edge> result;

    for (const Edge& edge : edges) {
        if (findParent(edge.from, parent) != findParent(edge.to, parent)) {
            minWeightSum += edge.weight;
            result.push_back(edge);
            unionSets(edge.from, edge.to, parent);
        }
    }

    return minWeightSum;
}

int main() {
    setlocale(LC_ALL, "Russian");

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;
    vector<Edge> edges(edgeCount);

    for (int i = 0; i < edgeCount; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), compareEdges);

    int minWeight = kruskal(edges, vertexCount);
    cout << "Минимальный вес остовного дерева: " << minWeight << endl;

    return 0;
}