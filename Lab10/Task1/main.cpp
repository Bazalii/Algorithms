#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    vector<vector<int>> graph;
    int n, m, a, b;
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    fin >> n >> m;
    graph.resize(n, vector<int>());
    for (int i = 0; i < m; i++) {
        fin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < n; ++i) {
        fout << graph[i].size() << " ";
    }
    return 0;
}
