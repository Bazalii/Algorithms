#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;

vector <vector<int>> graph, transp_graph;
vector<char> used;
vector<int> order, component;
int component_number = 1;

void dfs1 (int v) {
	used[v] = true;
	for (int i = 0; i < graph[v].size(); ++i)
		if (!used[graph[v][i]])
			dfs1 (graph[v][i]);
	order.push_back(v);
}
 
void dfs2 (int v) {
	used[v] = true;
	component[v] = component_number;
	for (int i = 0; i < transp_graph[v].size(); ++i)
		if (!used[transp_graph[v][i]])
			dfs2(transp_graph[v][i]);
}
 
int main() {
	ifstream fin ("cond.in");
    ofstream fout ("cond.out");
    int a, b, n, m;
    fin >> n >> m;
    graph.resize(n, vector<int>());
    transp_graph.resize(n, vector<int>());
    component.resize(n);
	for (int i = 0; i < m; i++) {
        fin >> a >> b;
		graph[a - 1].push_back (b - 1);
		transp_graph[b - 1].push_back (a - 1);
	}
	used.assign (n, false);
	for (int i = 0; i < n; ++i)
		if (!used[i])
			dfs1 (i);
	used.assign (n, false);
	for (int i = 0; i < n; ++i) {
		int v = order[n - 1 - i];
		if (!used[v]) {
			dfs2(v);
			component_number += 1;
		}
	}
	fout << component_number - 1 << endl;
    for (int i = 0; i < component.size(); ++i) {
        fout << component[i] << " ";
    }
    return 0;
}
