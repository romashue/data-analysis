#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;

// ����� ��� ������������� �����
class Graph {
public:
    Graph(int V); // �����������
    void addEdge(int v, int w); // ���������� ����� � ����
    void greedyColoring(); // ������ �������� ��������� �����
private:
    int V; // ���������� ������
    list<int>* adj; // ��������� �� ������ ������� ���������
};

// ����������� �����
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

// ������� ��� ���������� ����� � ����
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

// ������� ��� ��������� ����� � �������������� ������� ���������
void Graph::greedyColoring() {
    vector<int> result(V, -1); // ����� ������, ���������� ��� ������� �� ��������

    // ��������� ������ ���� ������ �������
    result[0] = 0;

    // ��������� ������ ��� �������� ����������� ������
    vector<bool> available(V, true);

    // ��������� ����� ��������� ��������
    for (int u = 1; u < V; u++) {
        // �������� �����, ������� ��� ������ �������� ���������
        for (auto i : adj[u]) {
            if (result[i] != -1) {
                available[result[i]] = false;
            }
        }

        // ������� ������ ��������� ����
        int cr;
        for (cr = 0; cr < V; cr++) {
            if (available[cr]) {
                break;
            }
        }

        result[u] = cr; // ��������� ��������� ���� ������� u

        // ���������� �������� ������� �� true ��� ��������� ��������
        for (auto i : adj[u]) {
            if (result[i] != -1) {
                available[result[i]] = true;
            }
        }
    }

    // ������� ��������� ���������
    for (int u = 0; u < V; u++) {
        cout << "������� " << u << " ---> ���� " << result[u] << endl;
    }
}

// ������� ��� ������ ����� �� �����
Graph readGraphFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "�� ������� ������� ����: " << filename << endl;
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

    cout << "��������� �����: " << endl;
    g.greedyColoring();

    return 0;
}