#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;


void dfs(vector<vector<int>>& graph, int v, vector<int>& visited) {
	visited[v] = 1; // ����� ���������� ���������
	cout << v+1 << " "; // ����� �������� ��������
	for (int to : graph[v]) {
		if (!visited[to]) {
			dfs(graph, to, visited);
		}
	}
}





int main() {
	setlocale(LC_ALL, "Russian");

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int vertexCount, edgeCount;
	cin >> vertexCount >> edgeCount; // �������� � �����
	vector<vector<int>> graph(vertexCount);


	for (int i = 0; i < edgeCount; i++) {
		int a;
		int b;
		cin >> a >> b;
		a--;
		b--;
		//���� � ��� �������� �� ��������������� ������� ��������� ����� ������
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int> visited(vertexCount);
	int component = 0;
	for (int v = 0; v < vertexCount; v++) {
		if (!visited[v]) {
			component++;
			cout << "����� ���������� �����: " << component << ": ";
			dfs(graph, v, visited);
			cout << endl;
		}
	}

	

	return 0;


}