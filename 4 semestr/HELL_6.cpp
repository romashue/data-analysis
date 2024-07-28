#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Graph {
	vector<vector<int>>g, gr; //у нас будет обычный  граф и инвертированный для реализации алгоритма Косараджу
	vector<int> visited, order; // для ДФС, чтобы сделать топологическую сортировку
	void dfs1(int v) {// передаем только номер текущей вершины так как всё остальное функция найдет в полях класса
		visited[v] = 1;
	
		for (int to : gr[v]) {
			if (!visited[to]) {
				dfs1(to);
			}
		}
		order.push_back(v);
	}

	void dfs2(int v, int component) {
		cout << v + 1 << " ";
		visited[v] = component;
		for (int to : g[v]) {
			if (!visited[to]) {
				dfs2(to, component);
			}
		}
	}
public:
	Graph(int vertexCount) { // конструктор для принятия кол-ва вершин для задавния кол-ва ячеек для 2-х графов
		g.resize(vertexCount);
		gr.resize(vertexCount);
	}
	void addEdge(int a, int b) { // добавление ребер
		g[a].push_back(b);
		gr[b].push_back(a);
	}
	vector<int> Find_SCC() { // метод для поиски компонентов сильной связности
		visited.assign(g.size(), 0); // заполняем нулями
		int sccCount = 0;
		
		for (int v = 0; v < g.size(); v++) { // запускаем дфс от всех непосещенных вершин
			if (!visited[v]) {

				dfs1(v);
			
			}
		}
		reverse(order.begin(), order.end());

		visited.assign(g.size(), 0); // заполняем нулями
		
		for (int v : order) { 
			if (!visited[v]) {
				cout << "Номер компонента связи " << sccCount + 1 << ": ";
				dfs2(v, ++sccCount);
				cout << endl;


			}
		}
		return visited;
	}
};




int main() {
	setlocale(LC_ALL, "Russian");

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int vertexCount, edgeCount;
	cin >> vertexCount >> edgeCount; // веришина и ребра
	Graph graph(vertexCount);

	for (int i = 0; i < edgeCount; i++) {
		int a, b;
		cin >> a >> b;
		graph.addEdge(a - 1, b - 1);
	}

	vector<int> scc = graph.Find_SCC();
	


	

	return 0;


}