#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int INF = 1e9;

struct Edge {
    int a, b, weight;
};

void BellmanFord(int vertexCount, vector<Edge>& edges, int start, vector<int>& dist) {
    dist.assign(vertexCount, INF);
    dist[start] = 0;

    for (int i = 0; i < vertexCount - 1; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.a] != INF && dist[edge.b] > dist[edge.a] + edge.weight) {
                dist[edge.b] = dist[edge.a] + edge.weight;
            }
        }
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output1.txt");

    int vertexCount, edgeCount;
    fin >> vertexCount >> edgeCount;

    vector<Edge> edges(edgeCount);
    for (int i = 0; i < edgeCount; ++i) {
        fin >> edges[i].a >> edges[i].b >> edges[i].weight;
    }

    int start;
    fin >> start;

    vector<int> dist;
    BellmanFord(vertexCount, edges, start, dist);

    for (int i = 0; i < vertexCount; ++i) {
        if (dist[i] == INF) {
            fout << "–ассто€ние до вершины " << i << " от вершины " << start << " бесконечно\n";
        }
        else {
            fout << "–ассто€ние до вершины " << i << " от вершины " << start << " равно " << dist[i] << "\n";
        }
    }

    fin.close();
    fout.close();

    return 0;
}