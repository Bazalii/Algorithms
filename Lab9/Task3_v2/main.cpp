#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

vector<vector<int>> graph;
vector<int> Color;
bool checker = true;

bool in(int element, vector<int> list_to_check){
    for (int a : list_to_check) {
        if (a == element)
            return true;
    }
    return false;
}

bool modified_dfs(int v, int color){
    Color[v] = color;
    for (int i = 0; i < graph[v].size(); ++i) {
        int next_vertex = graph[v][i];
        if (Color[next_vertex] == 0){
            if (color == 1)
                modified_dfs(next_vertex, 2);
            if (color == 2)
                modified_dfs(next_vertex, 1);
        }
        else if (Color[next_vertex] == color){
            checker = false;
        }
    }
}


int main() {
    ifstream fin ("bipartite.in");
    ofstream fout ("bipartite.out");
    int a, b, n, m;
    fin >> n >> m;
    graph.resize(n, vector<int>());
    Color.resize(n);
    for (int i = 0; i < m; i++) {
        fin >> a >> b;
        if (a == b){
            graph[a - 1].push_back(b - 1);
        }
        else {
            if (!in(b - 1, graph[a - 1])){
                graph[b - 1].push_back(a - 1);
                graph[a - 1].push_back(b - 1);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
            Color[i] = 0;
        }
    for (int i = 0; i < n; ++i) {
        if (Color[i] == 0)
            modified_dfs(i, 1);
    }
    if (checker)
        fout << "YES";
    else
        fout << "NO";
    return 0;
}
