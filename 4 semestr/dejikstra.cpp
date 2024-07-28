#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#define _CRT_SECURE_NO_WARNINGS 

using namespace std;

const int INF = 1e9;

vector<int> dijikstra(vector<vector<pair<int, int>>>& graph, int start) {
    vector<int> dist(graph.size(), INF);
    dist[start] = 0;
    vector<bool> visited(graph.size());

    for (int i = 0; i < graph.size(); i++) {
        int nearest = -1; // находим ближайшую необработанную вершину
        for (int j = 0; j < graph.size(); j++) {
            if ((!visited[j]) && ((nearest == -1) || (dist[nearest] > dist[j]))) {
                nearest = j;
            }
        }
        visited[nearest] = true; // помечаем в visited

        for (auto& pair : graph[nearest]) { // перебираем исходящие из нее ребра и пробуем ее прорелаксировать 
            //(обновляем расстояние до смежных вершин, если новый путь оказывается короче текущего.).
            int to = pair.first; // присваиваем соотю части пар.
            int weight = pair.second;
            if (dist[to] > dist[nearest] + weight) {
                dist[to] = dist[nearest] + weight;
            }
        }
    }
    return dist;
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
    int start;
    cin >> start;

    vector<int>dist = dijikstra(graph, start);

    int count = 0;
    for (int i : dist) {
        cout << "Расстояние между " << start << " и вершиной " << count << " равна: ";
        if (i != INF) {
            cout << i << " ";
        }
        else {
            cout << "non ";
        }
        cout << endl;
        count++;
    }

    return 0;
}