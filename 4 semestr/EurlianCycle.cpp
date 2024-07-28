#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;

    Graph(int vertices) : V(vertices) {
        adj.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        adj[u][v] = adj[v][u] = 1;
    }

    bool hasEulerianCycle() {
        for (int i = 0; i < V; ++i) {
            int degree = 0;
            for (int j = 0; j < V; ++j) {
                if (adj[i][j]) {
                    degree++;
                }
            }
            if (degree % 2 != 0) {
                return false;
            }
        }
        return true;
    }

    vector<int> findEulerianCycle() {
        vector<int> cycle;
        if (!hasEulerianCycle()) {
            return cycle; // if no Eulerian cycle exists, return empty vector
        }

        stack<int> circuit;
        vector<bool> visited(V, false);

        // Find the starting vertex for Eulerian cycle
        int start = 0;
        for (int i = 0; i < V; ++i) {
            if (adj[i][0]) {
                start = i;
                break;
            }
        }

        dfs(start, visited, circuit);

        while (!circuit.empty()) {
            cycle.push_back(circuit.top());
            circuit.pop();
        }

        return cycle;
    }

private:
    void dfs(int v, vector<bool>& visited, stack<int>& circuit) {
        visited[v] = true;
        for (int u = 0; u < V; ++u) {
            if (adj[v][u] && !visited[u]) {
                dfs(u, visited, circuit);
            }
        }
        circuit.push(v);
    }
};

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Failed to open input.txt\n";
        return 1;
    }

    ofstream outputFile("output1.txt");
    if (!outputFile) {
        cerr << "Failed to open output.txt\n";
        return 1;
    }

    int V, E;
    inputFile >> V >> E;

    Graph graph(V);

    int u, v;
    for (int i = 0; i < E; ++i) {
        inputFile >> u >> v;
        graph.addEdge(u, v);
    }

    if (!graph.hasEulerianCycle()) {
        outputFile << "No Eulerian cycle exists in the graph.\n";
        return 0;
    }

    vector<int> eulerianCycle = graph.findEulerianCycle();

    outputFile << "Eulerian Cycle: ";
    for (int vertex : eulerianCycle) {
        outputFile << vertex << " ";
    }
    outputFile << endl;

    cout << "Output has been written to output.txt\n";

    return 0;
}