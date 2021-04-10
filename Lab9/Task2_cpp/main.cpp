#pragma comment(linker, "/STACK:127108864")
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

vector<vector<int>> graph;
vector<int> Color;
vector<int> Array;
int checker = 0, n, m;
ifstream fin ("cycle.in");
ofstream fout ("cycle.out");

bool dfs(int v){
    if (Color[v] == 1){
        Color[v] = 3;
        return true;
    }
    if (Color[v] == 2)
        return false;
    Color[v] = 1;
    for (int i = 0; i < graph[v].size(); ++i) {
        if (dfs(graph[v][i])){
            if (Color[graph[v][i]] == 3 and checker == 0)
                    checker += 1;
            else if (Color[graph[v][i]] == 3 and checker == 1){
                fout << "YES\n";
                reverse(Array.begin(), Array.end());
                for (int j = 0; j < Array.size(); ++j) {
                    fout << Array[j] << " ";
                }
                exit(0);
            }
            Array.push_back(graph[v][i] + 1);
            return true;
        }
    }
    Color[v] = 2;
    return false;
}

void topological_sort(){
    for (int i = 0; i < n; ++i) {
        bool Cycle = dfs(i);
        if (Cycle){
            fout << "YES\n";
            reverse(Array.begin(), Array.end());
            for (int j = 0; j < Array.size(); ++j) {
                    fout << Array[j] << " ";
            }
            exit(0);
        }
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
    fout << "NO";
    return 0;
}
