#include <iostream>
#include <map>
#include <vector>
#include <cstring>

#define INF 1e9
using namespace std;
typedef pair<int, int> pii;

// Структура для описания ребра в сети
struct Edge {
    Edge(int _c = 0, int _b = 0, int _f = 0) {
        backEdgeFlow = _b;
        flow = _f;
        capacity = _c;
    }

    int backEdgeFlow;
    int flow;
    int capacity;
};

const int maxN = 1000;
// Список смежности
std::vector<int> g[maxN];
// Отображение (пара вершин -> ребро между ними)
std::map<pii, Edge> edges;
// Количество вершин
int N;
bool visited[maxN];

// Алгоритм Форда-Фалкерсона
int dfs(int u, int minCapacity) {
    if (u == N)
        return minCapacity;
    visited[u] = true;
    for (int v : g[u]) {
        Edge& uv = edges[{u, v}];
        if (!visited[v] && uv.flow < uv.capacity) {
            int delta = dfs(v, min(minCapacity, uv.capacity - uv.flow));
            if (delta > 0) {
                uv.flow += delta;
                uv.backEdgeFlow -= delta;
                return delta;
            }
        }
    }
    return 0;
}

int main() {
    freopen("input1.txt", "r", stdin);
    cin >> N;
    int u, v, c;
    while (cin >> u >> v >> c) {
        edges.insert({ make_pair(u, v), Edge(c) });
        g[u].push_back(v);
    }
    int maximumFlow = 0;
    // Запускаем алгоритм до тех пор, пока мы не сможем больше увеличить поток
    while (true) {
        int delta = dfs(1, INF);
        if (delta == 0) break;
        maximumFlow += delta;
        memset(visited, 0, sizeof visited);
    }
    cout << "u v c f" << "\n";
    // Вывод потока для пар вершин
    for (auto edge : edges) {
        Edge& description = edge.second;
        if (description.flow)
            cout << edge.first.first << " " << edge.first.second << " " << description.capacity << " "
            << description.flow << "\n";
    }
    cout << "Max flow = " << maximumFlow;
    return 0;
}
