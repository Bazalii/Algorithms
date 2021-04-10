#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;

ifstream fin ("hamiltonian.in");
ofstream fout ("hamiltonian.out");
vector<vector<int>> graph;
vector<int> Color, Way;
vector<bool> used;
int n, m;

bool in(int element, vector<int> list_to_check){
    for (int a : list_to_check) {
        if (a == element)
            return true;
    }
    return false;
}

bool dfs(int v){
    used[v] = true;
    for (int i = 0; i < graph[v].size(); ++i) {
        if (!used[graph[v][i]])
            dfs(graph[v][i]);
    }
    Way.push_back(v);
}

void topological_sort(){
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs(i);
    }
    reverse(Way.begin(), Way.end());
}

int main() {
    int a, b;
    bool checker;
    fin >> n >> m;
    graph.resize(n, vector<int>());
    Color.resize(n);
    for (int i = 0; i < n; ++i) {
        Color[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        fin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }
    used.assign(n, false);
    topological_sort();
    for (int i = 0; i < Way.size() - 1; ++i) {
        checker = false;
        if (in(Way[i + 1], graph[Way[i]])){
            checker = true;
        }
        if (!checker)
            break;
    }
    if (checker)
        fout << "YES";
    else
        fout << "NO";
    return 0;
}
