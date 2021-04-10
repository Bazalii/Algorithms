#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;

vector<vector<int>> graph;
vector<int> Color;
vector<int> Array;
int n, m;
ifstream fin ("topsort.in");
ofstream fout ("topsort.out");

bool dfs(int v){
    if (Color[v] == 1)
        return true;
    if (Color[v] == 2)
        return false;
    Color[v] = 1;
    for (int i = 0; i < graph[v].size(); ++i) {
        if (dfs(graph[v][i]))
            return true;
    }
    Array.push_back(v + 1);
    Color[v] = 2;
    return false;
}

void topological_sort(){
    for (int i = 0; i < n; ++i) {
        bool Cycle = dfs(i);
        if (Cycle){
            fout << "-1";
            exit(0);
        }
    }
    reverse(Array.begin(), Array.end());
    for (int i = 0; i < Array.size(); ++i) {
        fout << Array[i] << " ";
    }
}

int main() {
    int a, b;
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
    topological_sort();
    return 0;
}
