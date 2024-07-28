#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;

// Класс для представления графа
class Graph {
public:
    Graph(int V); // Конструктор
    void addEdge(int v, int w); // Добавление ребра в граф
    void greedyColoring(); // Жадный алгоритм раскраски графа
private:
    int V; // Количество вершин
    list<int>* adj; // Указатель на массив списков смежности
};

// Конструктор графа
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

// Функция для добавления ребра в граф
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

// Функция для раскраски графа с использованием жадного алгоритма
void Graph::greedyColoring() {
    vector<int> result(V, -1); // Цвета вершин, изначально все вершины не окрашены

    // Назначаем первый цвет первой вершине
    result[0] = 0;

    // Временный массив для хранения доступности цветов
    vector<bool> available(V, true);

    // Назначаем цвета остальным вершинам
    for (int u = 1; u < V; u++) {
        // Помечаем цвета, которые уже заняты смежными вершинами
        for (auto i : adj[u]) {
            if (result[i] != -1) {
                available[result[i]] = false;
            }
        }

        // Находим первый доступный цвет
        int cr;
        for (cr = 0; cr < V; cr++) {
            if (available[cr]) {
                break;
            }
        }

        result[u] = cr; // Назначаем найденный цвет вершине u

        // Сбрасываем значения обратно на true для следующей итерации
        for (auto i : adj[u]) {
            if (result[i] != -1) {
                available[result[i]] = true;
            }
        }
    }

    // Выводим результат раскраски
    for (int u = 0; u < V; u++) {
        cout << "Вершина " << u << " ---> Цвет " << result[u] << endl;
    }
}

// Функция для чтения графа из файла
Graph readGraphFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл: " << filename << endl;
        exit(1);
    }

    int V, E;
    file >> V >> E;
    Graph g(V);

    for (int i = 0; i < E; ++i) {
        int v, w;
        file >> v >> w;
        g.addEdge(v, w);
    }

    file.close();
    return g;
}

int main() {

    setlocale(LC_ALL, "Russian");

    string filename = "graph.txt"; 

    Graph g = readGraphFromFile(filename);

    cout << "Раскраска графа: " << endl;
    g.greedyColoring();

    return 0;
}